# Bab 7 - Edge/Fog Computing dan Analitik Data IoT

- **Bab pada buku:** 7
- **Minggu (RPS):** 12
- **CPMK:** CPMK5

## Praktik pada bab ini
Menerapkan agregasi, penyaringan ambang, dan deteksi anomali langsung pada
ESP32, lalu mengukur seberapa besar pengurangan data yang dihasilkan.

## Isi folder
- `kode/edge_filtering.ino` - agregasi + penyaringan ambang + penghitung hemat.
- `kode/deteksi_anomali.ino` - implementasi Algoritma 7.1.
- `rangkaian/pengawatan.md` - tabel pengawatan.
- `latihan/lembar-kerja.md` - lembar kerja beserta tabel pembanding.
- `latihan/panduan-tflite-micro.md` - nama pustaka TFLite Micro yang berlaku
  saat ini beserta alur kerja lengkapnya (sengaja di repositori agar tidak
  cepat usang).
- `kunci-jawaban-bab-07.md` - kunci pilihan ganda & jawaban lengkap esai.

## Catatan
Bab ini tidak memerlukan rangkaian baru. Pengawatan sama seperti Bab 2
(DHT22 ke GPIO4), karena yang dipelajari adalah pengolahan datanya, bukan
perangkat kerasnya.

Kedua program dapat berjalan tanpa jaringan; hasilnya diamati melalui
Serial Monitor. Bila ingin mengukur penghematan data sungguhan, gabungkan
dengan kode pengiriman dari Bab 5 atau Bab 6.
