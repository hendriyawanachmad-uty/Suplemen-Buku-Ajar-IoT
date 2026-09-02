# Bab 5 - Protokol Komunikasi IoT

- **Bab pada buku:** 5
- **Minggu (RPS):** 9 (setelah UTS)
- **CPMK:** CPMK3

## Praktik pada bab ini
Mengirim pembacaan sensor DHT22 dari ESP32 ke broker MQTT, lalu memverifikasinya
menggunakan aplikasi klien MQTT.

## Isi folder
- `kode/mqtt_publish.ino` - kode lengkap praktik (publish telemetri).
- `kode/mqtt_subscribe.ino` - contoh berlangganan untuk kendali jarak jauh.
- `kode/secrets.h.contoh` - templat kredensial WiFi dan broker.
- `rangkaian/pengawatan.md` - tabel pengawatan.
- `rangkaian/diagram.json` - berkas rangkaian untuk Wokwi.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `latihan/panduan-klien-mqtt.md` - cara memakai aplikasi klien MQTT.
- `latihan/broker-publik.md` - daftar broker publik untuk latihan.
- `kunci-jawaban-bab-05.md` - kunci pilihan ganda & jawaban lengkap esai.

## Library yang diperlukan
- `PubSubClient` (Nick O'Leary) - klien MQTT.
- `DHT sensor library` (Adafruit) + `Adafruit Unified Sensor`.

## PENTING
1. **Pengenal klien harus unik.** Bila dua perangkat memakai pengenal yang sama,
   broker akan memutus hubungan yang lama. Gejalanya: koneksi putus-sambung terus.
2. **Panggil `mqtt.loop()` pada setiap putaran.** Bila terlupa, hubungan terputus
   sendiri setelah beberapa saat meski program tampak berjalan normal.
3. **Broker publik tidak aman.** Siapa pun dapat membaca data Anda. Gunakan hanya
   untuk latihan, jangan untuk data nyata. Pakailah topic berawalan unik agar
   tidak bentrok dengan pengguna lain.

## Cara menjalankan
1. Salin `kode/secrets.h.contoh` menjadi `kode/secrets.h`, isi kredensial.
2. Rangkai DHT22 ke GPIO4 (lihat `rangkaian/pengawatan.md`).
3. Unggah `kode/mqtt_publish.ino`, buka Serial Monitor pada 115200.
4. Buka aplikasi klien MQTT, berlangganan pada topic Anda, amati data masuk.
