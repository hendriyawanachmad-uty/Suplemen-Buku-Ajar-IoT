/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 4 - Praktik: menghubungkan ESP32 ke WiFi dan menjalankan web server
 *         yang menampilkan pembacaan sensor DHT22.
 *
 * Lisensi kode: MIT
 * Library: "DHT sensor library" (Adafruit) + "Adafruit Unified Sensor".
 * Pengawatan: DHT22 DATA -> GPIO4 ; VCC -> 3V3 ; GND -> GND.
 *
 * Salin secrets.h.contoh menjadi secrets.h lalu isi kredensial WiFi Anda.
 */
#include <WiFi.h>
#include <DHT.h>
#include "secrets.h"        // WIFI_SSID, WIFI_PASSWORD

#define PIN_DHT  4
#define DHTTYPE  DHT22

DHT dht(PIN_DHT, DHTTYPE);
WiFiServer server(80);      // web server pada porta 80

void hubungkanWiFi() {
  Serial.print("Menyambung ke ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Terhubung. Buka alamat ini pada peramban: ");
  Serial.println(WiFi.localIP());
}

/* Susun halaman HTML berisi pembacaan sensor. */
String buatHalaman(float suhu, float rh) {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset='utf-8'>";
  html += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  html += "<meta http-equiv='refresh' content='5'>";   // muat ulang tiap 5 detik
  html += "<title>Monitor Sensor ESP32</title></head><body>";
  html += "<h2>Monitor Sensor ESP32</h2>";

  if (isnan(suhu) || isnan(rh)) {
    html += "<p>Gagal membaca sensor, periksa pengawatan.</p>";
  } else {
    html += "<p>Suhu: " + String(suhu, 1) + " &deg;C</p>";
    html += "<p>Kelembaban: " + String(rh, 1) + " %</p>";
  }
  html += "<p><small>Halaman dimuat ulang otomatis tiap 5 detik.</small></p>";
  html += "</body></html>";
  return html;
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  hubungkanWiFi();
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // adakah klien yang meminta?
  if (!client) return;

  // Baca permintaan sampai baris kosong (akhir header HTTP)
  String baris = "";
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      if (c == '\n') {
        if (baris.length() == 0) break;     // baris kosong: header selesai
        baris = "";
      } else if (c != '\r') {
        baris += c;
      }
    }
  }

  float suhu = dht.readTemperature();
  float rh   = dht.readHumidity();

  // Kirim tanggapan HTTP
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();                          // baris kosong pemisah
  client.println(buatHalaman(suhu, rh));

  client.stop();
  Serial.println("Permintaan dilayani.");
}
