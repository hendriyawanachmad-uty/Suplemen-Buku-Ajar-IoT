/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 5 - Praktik: mengirim telemetri sensor ke broker MQTT.
 *
 * Lisensi kode: MIT
 * Library: PubSubClient (Nick O'Leary), DHT sensor library (Adafruit),
 *          Adafruit Unified Sensor.
 * Pengawatan: DHT22 DATA -> GPIO4 ; VCC -> 3V3 ; GND -> GND.
 *
 * Salin secrets.h.contoh menjadi secrets.h lalu isi kredensial Anda.
 */
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "secrets.h"

#define PIN_DHT  4
#define DHTTYPE  DHT22

const unsigned long SELANG_KIRIM = 5000;   // kirim tiap 5 detik

DHT dht(PIN_DHT, DHTTYPE);
WiFiClient wifi;
PubSubClient mqtt(wifi);

unsigned long terakhirKirim = 0;

void hubungkanWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Menyambung WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("WiFi terhubung. IP: ");
  Serial.println(WiFi.localIP());
}

/* Sambung ke broker. Pengenal klien HARUS unik, sebab broker memutus
 * hubungan lama bila ada dua klien memakai pengenal yang sama. */
void sambungMQTT() {
  while (!mqtt.connected()) {
    String id = "esp32-" + String(random(9999));
    Serial.print("Menyambung broker sebagai ");
    Serial.println(id);

    if (mqtt.connect(id.c_str())) {
      Serial.println("Terhubung ke broker.");
    } else {
      Serial.print("Gagal, kode = ");
      Serial.print(mqtt.state());
      Serial.println(". Coba lagi 2 detik.");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  hubungkanWiFi();
  mqtt.setServer(MQTT_BROKER, MQTT_PORT);
}

void loop() {
  if (!mqtt.connected()) sambungMQTT();
  mqtt.loop();          // WAJIB: menjaga hubungan tetap hidup

  if (millis() - terakhirKirim < SELANG_KIRIM) return;
  terakhirKirim = millis();

  float suhu = dht.readTemperature();
  float rh   = dht.readHumidity();

  if (isnan(suhu) || isnan(rh)) {
    Serial.println("Gagal baca sensor, cek kabel.");
    return;
  }

  char muatan[16];
  dtostrf(suhu, 4, 1, muatan);           // ubah angka menjadi teks
  mqtt.publish(TOPIC_SUHU, muatan);

  dtostrf(rh, 4, 1, muatan);
  mqtt.publish(TOPIC_RH, muatan);

  Serial.print("Terkirim -> suhu ");
  Serial.print(suhu, 1);
  Serial.print(" C, kelembaban ");
  Serial.print(rh, 1);
  Serial.println(" %");
}
