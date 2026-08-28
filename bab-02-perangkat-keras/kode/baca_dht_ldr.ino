/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 2 - Praktik: membaca DHT22 (suhu & kelembaban) dan LDR (cahaya).
 * Lisensi kode: MIT
 *
 * Kebutuhan library: "DHT sensor library" (Adafruit) + "Adafruit Unified Sensor".
 * Pengawatan: DHT22 DATA -> GPIO4 ; LDR AO -> GPIO34 ; VCC -> 3V3 ; GND -> GND.
 */
#include <DHT.h>

#define PIN_DHT   4        // pin data DHT22
#define DHTTYPE   DHT22
#define PIN_LDR   34       // pin ADC (input-only) untuk LDR

DHT dht(PIN_DHT, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  analogReadResolution(12);          // ADC 12-bit: 0..4095
  Serial.println("Pembacaan DHT22 + LDR dimulai...");
}

void loop() {
  float suhu = dht.readTemperature();   // derajat Celsius
  float rh   = dht.readHumidity();      // persen
  int   ldr  = analogRead(PIN_LDR);     // 0..4095

  if (isnan(suhu) || isnan(rh)) {
    Serial.println("Gagal membaca DHT22, periksa pengawatan.");
  } else {
    Serial.printf("Suhu %.1f C  RH %.1f %%  Cahaya(ADC) %d\n", suhu, rh, ldr);
  }
  delay(2000);                          // baca tiap 2 detik
}
