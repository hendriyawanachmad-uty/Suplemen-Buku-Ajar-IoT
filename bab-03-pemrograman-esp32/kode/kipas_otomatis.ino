/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 3 - Praktik: Kipas otomatis berbasis suhu.
 *
 * Menyatukan seluruh konsep Bab 3:
 *   - penjadwalan tanpa penghambatan dengan millis()
 *   - penyaringan data (rata-rata cuplikan)
 *   - kendali dua ambang / histeresis  (implementasi Algoritma 3.1)
 *   - keluaran PWM untuk LED indikator
 *   - debouncing tombol untuk mode manual
 *
 * Lisensi kode: MIT
 * Library: "DHT sensor library" (Adafruit) + "Adafruit Unified Sensor".
 * CATATAN: kode ini memakai API PWM Arduino-ESP32 inti 3.x.
 *          Untuk inti 2.x, lihat pwm_core2.ino.
 */
#include <DHT.h>

// ---------- Pin ----------
#define PIN_DHT     4
#define DHTTYPE     DHT22
#define PIN_RELAI   26
#define PIN_LED     27
#define PIN_TOMBOL  15

// ---------- Parameter kendali ----------
const float AMBANG_ATAS  = 30.0;   // nyalakan kipas di atas nilai ini
const float AMBANG_BAWAH = 28.0;   // matikan kipas di bawah nilai ini
const unsigned long SELANG_BACA = 2000;   // baca sensor tiap 2 detik
const unsigned long JEDA_DEBOUNCE = 50;   // abaikan pantulan < 50 ms

DHT dht(PIN_DHT, DHTTYPE);

// ---------- Keadaan sistem ----------
bool kipasNyala = false;           // status aktuator (ingatan histeresis)
bool modeOtomatis = true;          // mode otomatis / manual
float suhuTerakhir = 0.0;

unsigned long terakhirBaca = 0;
unsigned long terakhirTombol = 0;
int tombolSebelumnya = HIGH;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(PIN_RELAI, OUTPUT);
  pinMode(PIN_TOMBOL, INPUT_PULLUP);   // tombol ke GND, pakai pull-up internal
  ledcAttach(PIN_LED, 5000, 8);        // LED PWM: 5 kHz, resolusi 8-bit

  digitalWrite(PIN_RELAI, LOW);
  Serial.println("Sistem kipas otomatis siap.");
}

/* Implementasi Algoritma 3.1: kendali aktuator dengan histeresis.
 * Status sebelumnya ikut menentukan keputusan, sehingga tidak berkedip
 * ketika suhu bergoyang di sekitar ambang. */
bool terapkanHisteresis(float nilai, bool status) {
  if (!status && nilai > AMBANG_ATAS)        status = true;    // langkah 1-2
  else if (status && nilai < AMBANG_BAWAH)   status = false;   // langkah 3-4
  // di dalam pita histeresis status dibiarkan tetap            // langkah 6
  return status;
}

/* Atur kecerahan LED sesuai seberapa jauh suhu melewati ambang bawah. */
void perbaruiIndikator(float suhu) {
  float rentang = AMBANG_ATAS - AMBANG_BAWAH;
  float rasio = (suhu - AMBANG_BAWAH) / rentang;
  if (rasio < 0) rasio = 0;
  if (rasio > 1) rasio = 1;
  ledcWrite(PIN_LED, (int)(rasio * 255));
}

/* Baca tombol dengan debouncing; kembalikan true bila baru saja ditekan. */
bool tombolDitekan() {
  int kini = digitalRead(PIN_TOMBOL);
  bool ditekan = false;

  if (kini != tombolSebelumnya) {
    if (millis() - terakhirTombol > JEDA_DEBOUNCE) {
      terakhirTombol = millis();
      if (kini == LOW) ditekan = true;   // LOW = tertekan (pull-up)
      tombolSebelumnya = kini;
    }
  }
  return ditekan;
}

void loop() {
  // --- Tugas cepat: selalu dilayani setiap putaran ---
  if (tombolDitekan()) {
    modeOtomatis = !modeOtomatis;
    if (!modeOtomatis) {
      kipasNyala = !kipasNyala;        // manual: langsung balik status
      if (kipasNyala) digitalWrite(PIN_RELAI, HIGH);
      else            digitalWrite(PIN_RELAI, LOW);
    }
      if (modeOtomatis) Serial.println("Mode: OTOMATIS");
    else              Serial.println("Mode: MANUAL");
  }

  // --- Tugas berkala: hanya saat selang waktu terpenuhi ---
  if (millis() - terakhirBaca >= SELANG_BACA) {
    terakhirBaca = millis();

    float suhu = dht.readTemperature();
    if (isnan(suhu)) {
      Serial.println("Gagal baca sensor, cek kabel.");
      return;
    }
    suhuTerakhir = suhu;

    if (modeOtomatis) {
      kipasNyala = terapkanHisteresis(suhu, kipasNyala);
      if (kipasNyala) digitalWrite(PIN_RELAI, HIGH);
      else            digitalWrite(PIN_RELAI, LOW);
    }
    perbaruiIndikator(suhu);

    Serial.print("Suhu "); Serial.print(suhu, 1);
    Serial.print(" C | Kipas ");
    Serial.print(kipasNyala ? "NYALA" : "MATI");
    Serial.print(" | Mode ");
    Serial.println(modeOtomatis ? "OTO" : "MAN");
  }
}
