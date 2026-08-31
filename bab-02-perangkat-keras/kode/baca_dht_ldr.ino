/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 2 - Praktik: membaca DHT22 (suhu & kelembaban) dan LDR (cahaya).
 *
 * Kode ini merupakan implementasi dari Algoritma 2.1 pada buku
 * (pengondisian sinyal dengan rata-rata cuplikan, lalu kalibrasi ke satuan fisik).
 *
 * Lisensi kode: MIT
 *
 * Kebutuhan library: "DHT sensor library" (Adafruit) + "Adafruit Unified Sensor".
 * Pengawatan: DHT22 DATA -> GPIO4 ; LDR AO -> GPIO34 ; VCC -> 3V3 ; GND -> GND.
 */
#include <DHT.h>

#define PIN_DHT       4        // pin data DHT22
#define DHTTYPE       DHT22
#define PIN_LDR       34       // pin ADC (input-only) untuk LDR

// --- Parameter Algoritma 2.1 ---
#define N_CUPLIKAN    10       // jumlah cuplikan untuk rata-rata (N)
#define JEDA_CUPLIKAN 5        // jeda antar cuplikan (ms)
#define ADC_MIN       0        // batas bawah nilai mentah ADC
#define ADC_MAKS      4095     // batas atas nilai mentah ADC (resolusi 12-bit)
#define CAHAYA_MIN    0.0      // batas bawah satuan fisik (persen)
#define CAHAYA_MAKS   100.0    // batas atas satuan fisik (persen)

DHT dht(PIN_DHT, DHTTYPE);

/* Fungsi peta(): mengubah rentang nilai mentah menjadi rentang fisik secara linier.
 * Untuk sensor yang tidak linier, ganti dengan tabel acuan atau persamaan kalibrasi. */
float peta(float nilai, float dariMin, float dariMaks, float keMin, float keMaks) {
  return (nilai - dariMin) * (keMaks - keMin) / (dariMaks - dariMin) + keMin;
}

/*
 * Implementasi Algoritma 2.1.
 * Langkah 1-6 : pengondisian sinyal (rata-rata N cuplikan untuk menekan derau).
 * Langkah 7-9 : kalibrasi (memetakan nilai mentah ke satuan fisik).
 */
float bacaTerkalibrasi(int pin, int n, float minFisik, float maksFisik) {
  long jumlah = 0;                                  // langkah 1

  for (int i = 0; i < n; i++) {                     // langkah 2
    int mentah = analogRead(pin);                   // langkah 3: nilai 0..4095
    jumlah += mentah;                               // langkah 4
    delay(JEDA_CUPLIKAN);                           // langkah 5: jeda antar cuplikan
  }                                                 // langkah 6

  float rata = (float) jumlah / n;                  // langkah 7: pengondisian
  float nilai = peta(rata, ADC_MIN, ADC_MAKS,
                     minFisik, maksFisik);          // langkah 8: kalibrasi
  return nilai;                                     // langkah 9
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  analogReadResolution(12);          // ADC 12-bit: 0..4095
  Serial.println("Pembacaan DHT22 + LDR dimulai (dengan pengondisian & kalibrasi)...");
}

void loop() {
  float suhu = dht.readTemperature();   // derajat Celsius (sudah digital)
  float rh   = dht.readHumidity();      // persen (sudah digital)

  // Sensor analog diproses mengikuti Algoritma 2.1
  int   ldrMentah = analogRead(PIN_LDR);
  float cahaya    = bacaTerkalibrasi(PIN_LDR, N_CUPLIKAN,
                                     CAHAYA_MIN, CAHAYA_MAKS);

  if (isnan(suhu) || isnan(rh)) {
    Serial.println("Gagal membaca DHT22, periksa pengawatan.");
  } else {
    Serial.printf("Suhu %.1f C  RH %.1f %%  Cahaya %.1f %% (mentah %d)\n",
                  suhu, rh, cahaya, ldrMentah);
  }
  delay(2000);                          // baca tiap 2 detik
}
