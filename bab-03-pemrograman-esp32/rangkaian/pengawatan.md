# Pengawatan: Sistem Kipas Otomatis (Bab 3)

| Komponen | Pin komponen | Pin ESP32 | Keterangan |
|----------|--------------|-----------|------------|
| DHT22 | VCC | 3V3 | |
| DHT22 | DATA | GPIO4 | sensor suhu |
| DHT22 | GND | GND | |
| Modul relai | IN | GPIO26 | ke kipas/pompa |
| Modul relai | VCC / GND | 5V (VIN) / GND | perhatikan kebutuhan tegangan modul |
| LED indikator | anoda (+) | GPIO27 | lewat resistor 220-330 ohm |
| LED indikator | katoda (-) | GND | |
| Tombol | kaki 1 | GPIO15 | memakai INPUT_PULLUP |
| Tombol | kaki 2 | GND | |

Catatan penting:
- Sebagian modul relai bersifat AKTIF RENDAH: relai justru aktif saat diberi LOW.
  Periksa lembar data modul, lalu balik logika pada `digitalWrite` bila perlu.
- Tombol memakai resistor pull-up internal, sehingga keadaan normal = HIGH
  dan tertekan = LOW.
- Untuk latihan tanpa beban listrik AC, relai dapat diganti LED kedua.
