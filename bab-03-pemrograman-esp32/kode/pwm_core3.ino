/*
 * Bab 3 - Contoh PWM untuk Arduino-ESP32 inti versi 3.x
 * Lisensi: MIT
 */
const int PIN_LED = 27;

void setup() {
  ledcAttach(PIN_LED, 5000, 8);   // pin, frekuensi 5 kHz, resolusi 8-bit
}

void loop() {
  ledcWrite(PIN_LED, 64);         // duty 25% (64 dari 255)
  delay(1000);
  ledcWrite(PIN_LED, 191);        // duty 75% (191 dari 255)
  delay(1000);
}
