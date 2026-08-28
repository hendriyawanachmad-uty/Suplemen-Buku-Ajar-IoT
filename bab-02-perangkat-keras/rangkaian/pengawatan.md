# Pengawatan: ESP32 + DHT22 + LDR

| Komponen | Pin komponen | Pin ESP32 |
|----------|--------------|-----------|
| DHT22 | VCC | 3V3 |
| DHT22 | DATA | GPIO4 |
| DHT22 | GND | GND |
| Modul LDR | VCC | 3V3 |
| Modul LDR | AO (analog out) | GPIO34 |
| Modul LDR | GND | GND |

Catatan:
- GPIO34 bersifat input-only dan cocok untuk masukan ADC.
- Jika memakai DHT22 tanpa modul, tambahkan resistor pull-up ~10k antara DATA dan VCC.
