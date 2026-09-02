# Pengawatan: Praktik Cloud dan Dashboard (Bab 6)

| Komponen | Pin komponen | Pin ESP32 | Keterangan |
|----------|--------------|-----------|------------|
| DHT22 | VCC | 3V3 | |
| DHT22 | DATA | GPIO4 | sensor suhu & kelembaban |
| DHT22 | GND | GND | |
| LED / modul relai | anoda / IN | GPIO26 | aktuator yang dikendalikan cloud |
| LED | katoda | GND | lewat resistor 220-330 ohm |

Catatan:
- Untuk latihan, LED sudah cukup menggantikan relai.
- Sebagian modul relai bersifat aktif rendah; periksa lembar datanya.
- Pada Wokwi, gunakan SSID "Wokwi-GUEST" dengan kata sandi kosong.
