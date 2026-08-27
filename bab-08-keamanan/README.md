# Bab 8 — Keamanan dan Privasi Sistem IoT

- **Bab pada buku:** 08-keamanan
- **Minggu (RPS):** 13
- **CPMK:** CPMK6

## Praktik pada bab ini
Mengamankan komunikasi (MQTT over TLS atau autentikasi token) dan menganalisis dampaknya.

## Isi folder
- `kode/` — program komunikasi aman (mis. mqtt_tls.ino). Jangan commit sertifikat/kredensial asli.
- `rangkaian/` — berkas/gambar rangkaian dan proyek Wokwi (`diagram.json`).
- `latihan/` — berkas pendukung latihan dan self-assessment.

## Cara menjalankan
1. Buka berkas pada `kode/` menggunakan Arduino IDE / PlatformIO / Wokwi.
2. Salin `secrets.h.contoh` menjadi `secrets.h` dan isi kredensial bila diperlukan.
3. Sesuaikan pin sesuai rangkaian, unggah ke ESP32, amati Serial Monitor.

## Prasyarat
Selesaikan instalasi pada [`../docs/instalasi.md`](../docs/instalasi.md).
