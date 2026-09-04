/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 6 - Telemetri ke cloud melalui MQTT, sekaligus menerima perintah.
 *
 * Menunjukkan kedua arah aliran data:
 *   uplink   : perangkat menerbitkan telemetri ke TOPIC_TELEMETRI
 *   downlink : perangkat berlangganan TOPIC_PERINTAH untuk menerima perintah
 *
 * Perangkat tetap memiliki ATURAN LOKAL sehingga aman ketika jaringan
 * terputus, sesuai pembahasan pada Bab 6.
 *
 * Lisensi kode: MIT
 * Library: PubSubClient, DHT sensor library, Adafruit Unified Sensor.
 */
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "secrets.h"

#define PIN_DHT   4
#define DHTTYPE   DHT22
#define PIN_RELAI 26

const float AMBANG_ATAS  = 30.0;   // aturan lokal (histeresis Bab 3)
const float AMBANG_BAWAH = 28.0;
const unsigned long SELANG_KIRIM = 10000;

DHT dht(PIN_DHT, DHTTYPE);
WiFiClient wifi;
PubSubClient mqtt(wifi);

bool modeManual  = false;   // true bila dikendalikan dari cloud
bool relaiNyala  = false;
unsigned long terakhirKirim = 0;

/* Downlink: dipanggil otomatis ketika ada perintah dari cloud. */
void pesanMasuk(char* topic, byte* muatan, unsigned int panjang) {
  String isi = "";
  for (unsigned int i = 0; i < panjang; i++) isi += (char) muatan[i];

  Serial.print("Perintah diterima: ");
  Serial.println(isi);

  if (isi == "NYALA") {
    modeManual = true;
    relaiNyala = true;
  } else if (isi == "MATI") {
    modeManual = true;
    relaiNyala = false;
  } else if (isi == "OTOMATIS") {
    modeManual = false;      // serahkan kembali ke aturan lokal
  }
}

void sambungMQTT() {
  while (!mqtt.connected()) {
    String id = "esp32-cloud-" + String(random(9999));
    if (mqtt.connect(id.c_str())) {
      mqtt.subscribe(TOPIC_PERINTAH);   // daftar ulang tiap tersambung
      Serial.println("Terhubung ke broker dan berlangganan perintah.");
    } else {
      delay(2000);
    }
  }
}

/* Aturan lokal: tetap bekerja walau jaringan terputus. */
void aturanLokal(float suhu) {
  if (!relaiNyala && suhu > AMBANG_ATAS)        relaiNyala = true;
  else if (relaiNyala && suhu < AMBANG_BAWAH)   relaiNyala = false;
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(PIN_RELAI, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  mqtt.setServer(MQTT_BROKER, MQTT_PORT);
  mqtt.setCallback(pesanMasuk);
}

void loop() {
  if (!mqtt.connected()) sambungMQTT();
  mqtt.loop();          // WAJIB dipanggil tiap putaran

  if (millis() - terakhirKirim < SELANG_KIRIM) return;
  terakhirKirim = millis();

  float suhu = dht.readTemperature();
  float rh   = dht.readHumidity();
  if (isnan(suhu) || isnan(rh)) return;

  if (!modeManual) aturanLokal(suhu);      // kendali lokal bila bukan manual

  if (relaiNyala) digitalWrite(PIN_RELAI, HIGH);
  else            digitalWrite(PIN_RELAI, LOW);

  // Kirim telemetri dalam format JSON sederhana
  char muatan[80];
  snprintf(muatan, sizeof(muatan),
           "{\"suhu\":%.1f,\"rh\":%.1f,\"relai\":%d}",
           suhu, rh, relaiNyala ? 1 : 0);
  mqtt.publish(TOPIC_TELEMETRI, muatan);

  Serial.print("Terkirim: ");
  Serial.println(muatan);
}
