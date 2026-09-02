/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 6 - Mengirim telemetri ke platform cloud melalui HTTP.
 *
 * Cara paling sederhana dan mudah diuji, tetapi lebih berat daripada MQTT
 * karena setiap pengiriman membawa header yang besar.
 *
 * Lisensi kode: MIT
 * Library: DHT sensor library (Adafruit) + Adafruit Unified Sensor.
 */
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include "secrets.h"

#define PIN_DHT 4
#define DHTTYPE DHT22

// Banyak platform gratis membatasi selang minimum antar pengiriman.
// Mengirim lebih cepat membuat sebagian data ditolak diam-diam.
const unsigned long SELANG_KIRIM = 20000;   // 20 detik

DHT dht(PIN_DHT, DHTTYPE);
unsigned long terakhirKirim = 0;

void hubungkanWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Menyambung WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Terhubung. IP: ");
  Serial.println(WiFi.localIP());
}

void kirimKeCloud(float suhu, float rh) {
  HTTPClient http;

  String url = String(HTTP_SERVER) + "/update"
             + "?api_key=" + KUNCI_API
             + "&field1=" + String(suhu, 1)
             + "&field2=" + String(rh, 1);

  http.begin(url);
  int kode = http.GET();

  if (kode == 200) {
    Serial.println("Terkirim ke cloud.");
  } else {
    Serial.print("Gagal kirim, kode HTTP = ");
    Serial.println(kode);
  }

  http.end();     // WAJIB: bebaskan sumber daya agar memori tidak habis
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  hubungkanWiFi();
}

void loop() {
  if (millis() - terakhirKirim < SELANG_KIRIM) return;
  terakhirKirim = millis();

  if (WiFi.status() != WL_CONNECTED) {
    hubungkanWiFi();
    return;
  }

  float suhu = dht.readTemperature();
  float rh   = dht.readHumidity();

  if (isnan(suhu) || isnan(rh)) {
    Serial.println("Gagal baca sensor, cek kabel.");
    return;
  }
  kirimKeCloud(suhu, rh);
}
