# Bab 8 - Keamanan dan Privasi Sistem IoT

- **Bab pada buku:** 8
- **Minggu (RPS):** 13
- **CPMK:** CPMK6

## Praktik pada bab ini
Membandingkan komunikasi MQTT tanpa dan dengan TLS, lalu memperbaiki
pengelolaan kredensial pada sistem yang telah dibangun.

## Isi folder
- `kode/mqtt_tls.ino` - komunikasi MQTT terenkripsi dengan pemeriksaan sertifikat.
- `kode/secrets.h.contoh` - templat kredensial.
- `latihan/panduan-sertifikat.md` - cara memperoleh dan menyematkan sertifikat.
- `latihan/daftar-periksa-keamanan.md` - daftar periksa yang dapat dicetak.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `kunci-jawaban-bab-08.md` - kunci pilihan ganda & jawaban lengkap esai.

## Catatan penting

**Materi ini bersifat defensif.** Isinya adalah cara melindungi sistem milik
sendiri. Menguji keamanan sistem yang bukan milik Anda, tanpa izin tertulis
dari pemiliknya, merupakan pelanggaran hukum di banyak negara termasuk
Indonesia. Lakukan seluruh percobaan hanya pada perangkat dan akun Anda sendiri.

**Rangkaian.** Bab ini tidak menambah perangkat keras. Pengawatan sama seperti
Bab 5 (DHT22 ke GPIO4); yang berubah adalah cara data diamankan.

## Cara menjalankan
1. Salin `kode/secrets.h.contoh` menjadi `kode/secrets.h`, isi kredensial.
2. Ikuti `latihan/panduan-sertifikat.md` untuk memperoleh sertifikat broker.
3. Unggah `kode/mqtt_tls.ino`, buka Serial Monitor pada 115200.
4. Bandingkan hasil pengamatan dengan program tanpa TLS dari Bab 5.
