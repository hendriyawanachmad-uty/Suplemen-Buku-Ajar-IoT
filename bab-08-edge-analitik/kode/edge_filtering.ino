/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 8 - Pemrosesan di edge: agregasi, penyaringan ambang, dan
 *         penghitungan penghematan data.
 *
 * Program mencatat berapa banyak pembacaan dilakukan dan berapa banyak
 * yang benar-benar perlu dikirim, sehingga penghematan dapat diukur.
 *
 * Lisensi kode: MIT
 * Library: DHT sensor library (Adafruit) + Adafruit Unified Sensor.
 */
#include <DHT.h>

#define PIN_DHT 4
#define DHTTYPE DHT22

const int   N_CUPLIKAN   = 10;     // agregasi: rata-rata 10 cuplikan
const float AMBANG_KIRIM = 0.5;    // kirim bila berubah >= 0.5 derajat
const unsigned long SELANG_BACA = 1000;   // baca tiap 1 detik

DHT dht(PIN_DHT, DHTTYPE);

float buf[N_CUPLIKAN];
int   isi = 0;
float nilaiTerakhirKirim = -999;

unsigned long jumlahDibaca = 0;
unsigned long jumlahTerkirim = 0;
unsigned long terakhirBaca = 0;

/* Agregasi: kembalikan rata-rata bila jendela sudah penuh, jika belum
 * kembalikan NAN sebagai penanda "belum siap". */
float agregasi(float nilai) {
  buf[isi++] = nilai;
  if (isi < N_CUPLIKAN) return NAN;

  float jumlah = 0;
  for (int i = 0; i < N_CUPLIKAN; i++) jumlah += buf[i];
  isi = 0;
  return jumlah / N_CUPLIKAN;
}

/* Di sini seharusnya pengiriman ke cloud/broker dilakukan.
 * Untuk latihan, cukup dicetak agar penghematan mudah diamati. */
void kirimKeCloud(float suhu) {
  Serial.print(">> DIKIRIM: ");
  Serial.println(suhu, 2);
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Pemrosesan di edge dimulai.");
}

void loop() {
  if (millis() - terakhirBaca < SELANG_BACA) return;
  terakhirBaca = millis();

  float suhu = dht.readTemperature();
  if (isnan(suhu)) return;          // penyaringan: buang bacaan gagal

  jumlahDibaca++;

  float rata = agregasi(suhu);
  if (isnan(rata)) return;          // jendela belum penuh

  // Penyaringan berbasis ambang: kirim hanya bila berubah berarti
  if (fabs(rata - nilaiTerakhirKirim) >= AMBANG_KIRIM) {
    kirimKeCloud(rata);
    nilaiTerakhirKirim = rata;
    jumlahTerkirim++;
  }

  // Laporan penghematan tiap 30 pembacaan
  if (jumlahDibaca % 30 == 0) {
    float hemat = 100.0 * (1.0 - (float) jumlahTerkirim / jumlahDibaca);
    Serial.print("Dibaca: ");   Serial.print(jumlahDibaca);
    Serial.print(" | Dikirim: "); Serial.print(jumlahTerkirim);
    Serial.print(" | Hemat: ");   Serial.print(hemat, 1);
    Serial.println(" %");
  }
}
