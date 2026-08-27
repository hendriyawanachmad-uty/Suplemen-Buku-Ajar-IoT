/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Companion
 * Lisensi kode: MIT
 *
 * CATATAN: berkas ini adalah KERANGKA/TEMPLATE. Lengkapi bagian bertanda TODO
 * pada tahap penulisan bab. Sesuaikan pin dan kredensial sebelum diunggah.
 */
// Bab 4 | Kerangka: hubungkan ESP32 ke WiFi dan sajikan data via web server.

#include <WiFi.h>
#include "secrets.h" // berisi WIFI_SSID, WIFI_PASSWORD

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nTerhubung. IP: " + WiFi.localIP().toString());
  server.begin();
}

void loop() {
  // TODO: layani permintaan klien dan kirim data sensor sebagai HTML/JSON
}
