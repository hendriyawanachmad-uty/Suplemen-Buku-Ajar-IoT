/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Companion
 * Lisensi kode: MIT
 *
 * CATATAN: berkas ini adalah KERANGKA/TEMPLATE. Lengkapi bagian bertanda TODO
 * pada tahap penulisan bab. Sesuaikan pin dan kredensial sebelum diunggah.
 */
// Bab 7 | Kerangka: pemrosesan di edge (rata-rata bergerak + deteksi ambang).

const int N = 10;
float buf[N]; int idx = 0; bool penuh = false;

float rataBergerak(float x) {
  buf[idx] = x; idx = (idx + 1) % N; if (idx == 0) penuh = true;
  int n = penuh ? N : idx; float s = 0; for (int i = 0; i < n; i++) s += buf[i];
  return s / n;
}

void setup() { Serial.begin(115200); }

void loop() {
  float x = 0.0;               // TODO: pembacaan sensor
  float avg = rataBergerak(x);
  // TODO: kirim ke cloud HANYA bila avg melewati ambang (kurangi bandwidth)
  Serial.println(avg);
  delay(1000);
}
