# Lembar Kerja Praktik Bab 3 - Kipas Otomatis

**Nama / NIM:** [ ... ]  **Tanggal:** [ ... ]

## 1. Tujuan
Membangun sistem kipas otomatis berbasis suhu yang menerapkan penjadwalan
`millis()`, histeresis, PWM, dan debouncing.

## 2. Alat dan bahan
[ ESP32, DHT22, modul relai (atau LED pengganti), LED indikator + resistor,
  tombol, breadboard, kabel jumper / atau Wokwi ]

## 3. Pengawatan
[ Lampirkan foto atau tangkapan rangkaian; rujuk rangkaian/pengawatan.md ]

## 4. Pengujian histeresis
Hangatkan sensor perlahan, lalu biarkan mendingin. Catat pada suhu berapa
kipas berpindah status.

| Peristiwa | Suhu tercatat (C) | Status kipas |
|-----------|-------------------|--------------|
| Kipas mulai NYALA |  |  |
| Kipas kembali MATI |  |  |

[ Apakah kipas berpindah status tepat pada ambang yang Anda tetapkan? ]

## 5. Eksperimen lebar pita histeresis
Ubah nilai `AMBANG_BAWAH` sehingga jarak antar-ambang berubah, lalu amati.

| AMBANG_ATAS | AMBANG_BAWAH | Lebar pita | Jumlah pergantian status dalam 5 menit |
|-------------|--------------|------------|-----------------------------------------|
| 30 | 29.5 | 0.5 |  |
| 30 | 28   | 2.0 |  |
| 30 | 25   | 5.0 |  |

[ Apa yang terjadi bila pita terlalu sempit? Apa kerugian bila terlalu lebar? ]

## 6. Eksperimen delay() vs millis()
Ganti sementara penjadwalan `millis()` dengan `delay(2000)`, lalu coba tekan
tombol beberapa kali.

[ Apakah tombol tetap responsif? Jelaskan mengapa. ]

## 7. Pengamatan PWM
[ Bagaimana kecerahan LED berubah saat suhu mendekati ambang atas? ]

## 8. Kesimpulan
[ ... ]
