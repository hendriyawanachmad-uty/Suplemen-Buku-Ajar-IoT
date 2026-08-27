/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Companion
 * Lisensi kode: MIT
 *
 * CATATAN: berkas ini adalah KERANGKA/TEMPLATE. Lengkapi bagian bertanda TODO
 * pada tahap penulisan bab. Sesuaikan pin dan kredensial sebelum diunggah.
 */
// Bab 5 | Kerangka: publish data sensor ke broker MQTT.

#include <WiFi.h>
// TODO: #include <PubSubClient.h>
#include "secrets.h"

void setup() {
  Serial.begin(115200);
  // TODO: koneksi WiFi
  // TODO: set broker MQTT dan koneksi klien
}

void loop() {
  // TODO: baca sensor
  // TODO: client.publish("topik/sensor", payload)
  delay(5000);
}
