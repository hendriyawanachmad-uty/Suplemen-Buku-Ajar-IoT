/*
 * Bab 3 - Contoh PWM untuk Arduino-ESP32 inti versi 2.x
 * Pada inti 2.x, PWM diatur melalui KANAL, bukan langsung ke pin.
 * Lisensi: MIT
 */
const int PIN_LED = 27;
const int KANAL   = 0;

void setup() {
  ledcSetup(KANAL, 5000, 8);      // kanal, frekuensi 5 kHz, resolusi 8-bit
  ledcAttachPin(PIN_LED, KANAL);  // pasangkan pin ke kanal
}

void loop() {
  ledcWrite(KANAL, 64);           // duty 25% -> tulis ke KANAL
  delay(1000);
  ledcWrite(KANAL, 191);          // duty 75%
  delay(1000);
}
