# Bab 6 - Integrasi Platform Cloud IoT

- **Bab pada buku:** 6
- **Minggu (RPS):** 10
- **CPMK:** CPMK5

## Praktik pada bab ini
Mendaftarkan perangkat pada platform cloud IoT, mengirim telemetri, dan
menambahkan kendali jarak jauh melalui jalur downlink.

Penyimpanan data dan dashboard dibahas pada Bab 7 (`../bab-07-basisdata/`).

## Isi folder
- `kode/kirim_cloud_http.ino` - kirim telemetri via HTTP (paling sederhana).
- `kode/kirim_cloud_mqtt.ino` - kirim telemetri via MQTT + terima perintah.
- `kode/secrets.h.contoh` - templat kredensial.
- `rangkaian/pengawatan.md` - tabel pengawatan.
- `rangkaian/diagram.json` - berkas rangkaian untuk Wokwi.
- `latihan/panduan-thingspeak.md` - langkah membuat akun dan dashboard.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `kunci-jawaban-bab-06.md` - kunci pilihan ganda & jawaban lengkap esai.

## Library yang diperlukan
- `PubSubClient` (untuk versi MQTT).
- `DHT sensor library` (Adafruit) + `Adafruit Unified Sensor`.
- `HTTPClient` sudah termasuk dalam inti Arduino-ESP32.

## PENTING
1. **Jaga kerahasiaan kredensial.** Kunci API atau token yang bocor
   memungkinkan orang lain mengirim data palsu atas nama perangkat Anda.
   Bila terlanjur tersebar, **batalkan token itu dan terbitkan yang baru**;
   menghapus riwayat unggahan saja tidak cukup.
2. **Panggil `http.end()`** setelah setiap pengiriman HTTP. Bila terlupa,
   perangkat dapat kehabisan memori lalu memulai ulang sendiri setelah
   beberapa ratus pengiriman. Gejalanya mirip kerusakan perangkat keras.
3. **Perhatikan batas pengiriman.** Platform versi gratis membatasi selang
   waktu minimum antar pengiriman. Mengirim terlalu cepat membuat sebagian
   data ditolak diam-diam.
4. **Sediakan aturan lokal.** Perangkat harus tetap bekerja ketika jaringan
   terputus; kendali cloud diposisikan sebagai pelengkap.

## Cara menjalankan
1. Buat akun platform, daftarkan perangkat, catat kredensial.
2. Salin `kode/secrets.h.contoh` menjadi `kode/secrets.h`, isi kredensial.
3. Rangkai DHT22 ke GPIO4 dan LED/relai ke GPIO26.
4. Unggah salah satu berkas kode, buka Serial Monitor pada 115200.
5. Susun dashboard sesuai `latihan/panduan-thingspeak.md`.
