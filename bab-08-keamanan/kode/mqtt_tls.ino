/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Companion
 * Lisensi kode: MIT
 *
 * CATATAN: berkas ini adalah KERANGKA/TEMPLATE. Lengkapi bagian bertanda TODO
 * pada tahap penulisan bab. Sesuaikan pin dan kredensial sebelum diunggah.
 */
// Bab 8 | Kerangka: MQTT over TLS (komunikasi terenkripsi).
// PENTING: jangan pernah commit sertifikat atau kredensial asli.

#include <WiFi.h>
// TODO: #include <WiFiClientSecure.h>
// TODO: #include <PubSubClient.h>
#include "secrets.h"

void setup() {
  Serial.begin(115200);
  // TODO: koneksi WiFi
  // TODO: set root CA pada WiFiClientSecure, koneksi ke broker port 8883
}

void loop() {
  // TODO: publish terenkripsi; bandingkan dengan versi tanpa TLS pada Bab 5
  delay(5000);
}
