# Pengawatan: Web Server Penampil Data Sensor (Bab 4)

| Komponen | Pin komponen | Pin ESP32 |
|----------|--------------|-----------|
| DHT22 | VCC | 3V3 |
| DHT22 | DATA | GPIO4 |
| DHT22 | GND | GND |

Catatan:
- Rangkaian sama seperti Bab 2; yang bertambah pada bab ini adalah sisi
  perangkat lunaknya, yaitu koneksi WiFi dan web server.
- Jika memakai DHT22 tanpa modul, tambahkan resistor pull-up ~10k antara
  DATA dan VCC.
- Pada Wokwi, jaringan WiFi disimulasikan; gunakan SSID "Wokwi-GUEST"
  dengan kata sandi kosong.
