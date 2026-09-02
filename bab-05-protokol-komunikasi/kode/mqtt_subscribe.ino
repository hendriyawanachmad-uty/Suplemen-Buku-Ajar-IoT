/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 5 - Contoh tambahan: berlangganan topic untuk menerima perintah.
 *
 * Menunjukkan arah sebaliknya dari mqtt_publish.ino: perangkat MENERIMA
 * pesan. Kirim "NYALA" atau "MATI" ke TOPIC_PERINTAH dari aplikasi klien
 * MQTT, lalu amati LED bawaan.
 *
 * Lisensi kode: MIT
 */
#include <WiFi.h>
#include <PubSubClient.h>
#include "secrets.h"

#define PIN_LED 2

WiFiClient wifi;
PubSubClient mqtt(wifi);

/* Dipanggil otomatis setiap kali ada pesan masuk pada topic langganan. */
void pesanMasuk(char* topic, byte* muatan, unsigned int panjang) {
  String isi = "";
  for (unsigned int i = 0; i < panjang; i++) isi += (char) muatan[i];

  Serial.print("Pesan pada ");
  Serial.print(topic);
  Serial.print(" -> ");
  Serial.println(isi);

  if (isi == "NYALA")     digitalWrite(PIN_LED, HIGH);
  else if (isi == "MATI") digitalWrite(PIN_LED, LOW);
}

void sambungMQTT() {
  while (!mqtt.connected()) {
    String id = "esp32-sub-" + String(random(9999));
    if (mqtt.connect(id.c_str())) {
      mqtt.subscribe(TOPIC_PERINTAH);     // daftar ulang tiap tersambung
      Serial.println("Terhubung dan berlangganan.");
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  mqtt.setServer(MQTT_BROKER, MQTT_PORT);
  mqtt.setCallback(pesanMasuk);           // daftarkan fungsi penanganan
}

void loop() {
  if (!mqtt.connected()) sambungMQTT();
  mqtt.loop();
}
