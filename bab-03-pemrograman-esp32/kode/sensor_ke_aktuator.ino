/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Companion
 * Lisensi kode: MIT
 *
 * CATATAN: berkas ini adalah KERANGKA/TEMPLATE. Lengkapi bagian bertanda TODO
 * pada tahap penulisan bab. Sesuaikan pin dan kredensial sebelum diunggah.
 */
// Bab 3 | Kerangka: kendali aktuator berbasis ambang dengan histeresis.

const int PIN_RELAY = 26;
// TODO: definisikan pin & sensor
float ambangAtas = 30.0;  // contoh: suhu nyalakan
float ambangBawah = 28.0; // histeresis: suhu matikan
bool aktif = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAY, OUTPUT);
}

void loop() {
  float nilai = 0.0; // TODO: ganti dengan pembacaan sensor
  if (!aktif && nilai > ambangAtas) aktif = true;
  else if (aktif && nilai < ambangBawah) aktif = false;
  digitalWrite(PIN_RELAY, aktif ? HIGH : LOW);
  // TODO: gunakan penjadwalan non-blocking (millis) untuk periode baca
  delay(1000);
}
