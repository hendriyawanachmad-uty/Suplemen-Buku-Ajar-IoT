/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 7 - Implementasi Algoritma 7.1: deteksi anomali berbasis
 *         rata-rata dan simpangan baku.
 *
 * Nilai yang menyimpang lebih dari k kali simpangan baku ditandai sebagai
 * anomali dan TIDAK dimasukkan ke jendela, agar kejanggalan tidak menggeser
 * rata-rata (lihat pembahasan langkah 8 pada buku).
 *
 * Lisensi kode: MIT
 * Library: DHT sensor library (Adafruit) + Adafruit Unified Sensor.
 */
#include <DHT.h>

#define PIN_DHT 4
#define DHTTYPE DHT22

const int   N_JENDELA = 20;    // banyak nilai pada jendela
const float PENGALI_K = 2.0;   // coba ubah menjadi 3.0
const unsigned long SELANG_BACA = 1000;

DHT dht(PIN_DHT, DHTTYPE);

float jendela[N_JENDELA];
int   terisi = 0;              // banyak nilai yang sudah masuk
int   posisi = 0;              // penunjuk penulisan berikutnya
unsigned long terakhirBaca = 0;

void masukkanJendela(float x) {
  jendela[posisi] = x;
  posisi = (posisi + 1) % N_JENDELA;
  if (terisi < N_JENDELA) terisi++;
}

float hitungRata() {
  float jumlah = 0;
  for (int i = 0; i < terisi; i++) jumlah += jendela[i];
  return jumlah / terisi;
}

float hitungSimpangan(float rata) {
  float jumlah = 0;
  for (int i = 0; i < terisi; i++) {
    float d = jendela[i] - rata;
    jumlah += d * d;
  }
  return sqrt(jumlah / terisi);
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Deteksi anomali dimulai. Hangatkan sensor untuk mencoba.");
}

void loop() {
  if (millis() - terakhirBaca < SELANG_BACA) return;
  terakhirBaca = millis();

  float x = dht.readTemperature();
  if (isnan(x)) return;

  // Jendela belum cukup terisi: kumpulkan dulu sebagai keadaan normal
  if (terisi < N_JENDELA) {
    masukkanJendela(x);
    Serial.print("Mengumpulkan data awal... ");
    Serial.println(x, 1);
    return;
  }

  float rata = hitungRata();                  // langkah 1
  float simpangan = hitungSimpangan(rata);    // langkah 2-3

  // PENTING: bila data sangat stabil, simpangan menjadi sangat kecil
  // sehingga batas normal ikut menyempit dan perubahan wajar pun
  // tertandai sebagai anomali (positif palsu). Karena itu ditetapkan
  // batas bawah simpangan yang masuk akal untuk besaran yang diukur.
  // Untuk suhu ruangan, 0.3 derajat lebih realistis daripada 0.05.
  const float SIMPANGAN_MIN = 0.3;
  if (simpangan < SIMPANGAN_MIN) simpangan = SIMPANGAN_MIN;

  if (fabs(x - rata) > PENGALI_K * simpangan) {   // langkah 4
    Serial.print("ANOMALI! nilai ");
    Serial.print(x, 1);
    Serial.print(" (rata ");
    Serial.print(rata, 1);
    Serial.print(", simpangan ");
    Serial.print(simpangan, 2);
    Serial.println(")");
    // langkah 8: sengaja TIDAK dimasukkan ke jendela
  } else {
    Serial.print("normal  ");
    Serial.println(x, 1);
    masukkanJendela(x);
  }
}
