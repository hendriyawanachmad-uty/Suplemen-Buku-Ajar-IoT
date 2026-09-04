# Changelog

Semua perubahan penting pada repositori ini dicatat di sini.
Rilis (tag) ditautkan ke edisi buku agar kode selalu cocok dengan yang tercetak.

Format mengacu pada [Keep a Changelog](https://keepachangelog.com/id/1.0.0/)
dan penomoran mengikuti [Semantic Versioning](https://semver.org/lang/id/).

## [Belum dirilis]

### Diubah
- **Struktur bab berubah dari 10 menjadi 11.** Bab 6 dipecah menjadi
  integrasi platform cloud (Bab 6, minggu 10) dan basis data serta
  visualisasi (Bab 7, minggu 11).
- Folder diganti nama mengikuti penomoran baru:
  `bab-06-cloud-dashboard` menjadi `bab-06-platform-cloud`,
  `bab-07-edge-analitik` menjadi `bab-08-edge-analitik`,
  `bab-08-keamanan` menjadi `bab-09-keamanan`,
  `bab-09-penerapan-domain` menjadi `bab-10-penerapan-domain`,
  `bab-10-proyek-end-to-end` menjadi `bab-11-proyek-end-to-end`.
- Materi penyimpanan data dan dashboard dipindahkan dari Bab 6 ke Bab 7.

### Ditambahkan
- **`bab-07-basisdata/`** (baru): skema dan kueri SQL, contoh line protocol
  serta kueri InfluxDB, contoh dokumen MongoDB, kode penyangga SQLite pada
  gateway, lembar kerja, dan kunci jawaban.
- `bab-06-platform-cloud/`: kode telemetri HTTP dan MQTT, panduan platform.
- `bab-08-edge-analitik/`: kode penyaringan di edge, deteksi anomali, dan
  panduan TensorFlow Lite for Microcontrollers.
- `bab-09-keamanan/`: kode MQTT over TLS, panduan sertifikat, dan daftar
  periksa keamanan.

### Catatan bagi pengguna buku cetak
Kode QR pada buku menunjuk ke commit tertentu, sehingga QR pada edisi yang
sudah dicetak tetap mengarah ke struktur folder saat itu. Hal ini disengaja
agar buku dan kodenya tetap cocok.

## [0.1.0] - 2026-01-01  (menyertai Buku Edisi 1, draf)
### Ditambahkan
- Struktur awal companion untuk 10 bab sesuai Rencana Materi revisi.
