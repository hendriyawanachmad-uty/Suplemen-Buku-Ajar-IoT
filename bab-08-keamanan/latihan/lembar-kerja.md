# Lembar Kerja Praktik Bab 8 - Mengamankan Komunikasi

**Nama / NIM:** [ ... ]  **Tanggal:** [ ... ]

> **Peringatan.** Seluruh percobaan hanya boleh dilakukan pada perangkat,
> jaringan, dan akun milik Anda sendiri.

## 1. Tujuan
Membandingkan komunikasi tanpa dan dengan TLS, serta memperbaiki pengelolaan
kredensial.

## 2. Pengamatan tanpa TLS (porta 1883)
Jalankan program MQTT dari Bab 5, lalu amati muatan pesan melalui aplikasi klien.

| Butir | Hasil |
|-------|-------|
| Isi pesan yang terlihat | |
| Apakah nilai suhu terbaca jelas? | |

## 3. Pengamatan dengan TLS (porta 8883)
| Butir | Hasil |
|-------|-------|
| Apakah koneksi berhasil? | |
| Berapa lama proses penyambungan? | |
| Apakah isi pesan masih terbaca dari luar? | |

[ Apa yang berubah, dan apa yang tetap sama? ]

## 4. Percobaan kegagalan TLS
Ubah satu karakter pada sertifikat, lalu jalankan kembali.

| Butir | Hasil |
|-------|-------|
| Pesan galat yang muncul | |
| Apakah pesannya menjelaskan penyebabnya? | |

[ Mengapa kegagalan TLS sering sulit ditelusuri? ]

## 5. Pengaruh waktu perangkat
Hapus sementara pemanggilan `configTime()`, lalu jalankan setelah perangkat
dimatikan dan dinyalakan kembali.

[ Apa yang terjadi? Mengapa waktu memengaruhi pemeriksaan sertifikat? ]

## 6. Pengelolaan kredensial
| Butir | Sebelum | Sesudah |
|-------|---------|---------|
| Tempat kredensial disimpan | | |
| Jumlah perangkat yang memakai kredensial sama | | |
| Dapatkah satu kredensial dibatalkan sendiri? | | |

## 7. Daftar periksa keamanan
Isi `daftar-periksa-keamanan.md` untuk sistem Anda.

| Bagian | Jumlah butir terpenuhi | Butir yang belum terpenuhi |
|--------|------------------------|----------------------------|
| Perangkat | | |
| Jaringan | | |
| Cloud/Broker | | |
| Firmware | | |
| Privasi | | |

## 8. Analisis privasi
Tuliskan seluruh data yang dikumpulkan sistem Anda.

| Data yang dikumpulkan | Benar-benar dibutuhkan? | Alasan |
|-----------------------|-------------------------|--------|
| | | |
| | | |

[ Data apa yang sebenarnya dapat dihapus tanpa mengurangi fungsi sistem? ]

## 9. Kesimpulan
[ ... ]
