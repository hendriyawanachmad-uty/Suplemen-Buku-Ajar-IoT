/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Companion
 * Lisensi kode: MIT
 *
 * CATATAN: berkas ini adalah KERANGKA/TEMPLATE. Lengkapi bagian bertanda TODO
 * pada tahap penulisan bab. Sesuaikan pin dan kredensial sebelum diunggah.
 */
// Bab 6 | Kerangka: kirim telemetri ke platform cloud IoT (mis. ThingSpeak/Blynk).

#include <WiFi.h>
#include "secrets.h"

void setup() {
  Serial.begin(115200);
  // TODO: koneksi WiFi
  // TODO: inisialisasi klien platform cloud dengan CLOUD_TOKEN
}

void loop() {
  // TODO: baca sensor lalu kirim ke cloud (HTTP/MQTT)
  // TODO: (opsional) terima perintah kendali dari cloud untuk aktuator
  delay(15000);
}
