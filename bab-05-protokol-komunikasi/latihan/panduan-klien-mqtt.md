# Panduan Aplikasi Klien MQTT

Aplikasi klien MQTT dipakai untuk memeriksa apakah data dari ESP32 benar-benar
sampai ke broker, dan untuk mengirim perintah ke perangkat.

## Pilihan aplikasi
- **MQTTX** (Windows, macOS, Linux) - antarmuka grafis, mudah untuk pemula.
- **MQTT Explorer** (Windows, macOS, Linux) - menampilkan pohon topic.
- **IoT MQTT Panel** (Android) - praktis untuk pengujian dari ponsel.
- **mosquitto_sub / mosquitto_pub** (baris perintah) - ringan, cocok untuk
  yang terbiasa terminal.

## Langkah dasar (MQTTX)
1. Buat koneksi baru.
2. Isi **Host** dengan alamat broker, mis. `broker.emqx.io`, dan **Port** 1883.
3. Isi **Client ID** dengan nama unik apa pun.
4. Tekan Connect.
5. Tekan **New Subscription**, isi topic Anda, mis. `kelasA-nim123/labA/#`.
6. Data dari ESP32 akan muncul begitu diterbitkan.

## Menguji arah sebaliknya
Untuk mencoba `mqtt_subscribe.ino`:
1. Pada aplikasi klien, pilih menu publish.
2. Isi topic dengan `TOPIC_PERINTAH` yang Anda pakai.
3. Kirim pesan `NYALA`, lalu `MATI`, dan amati LED pada ESP32.

## Bila data tidak muncul
- Pastikan alamat broker dan porta sama persis dengan yang ada di `secrets.h`.
- Pastikan topic yang dilanggan sama persis, termasuk huruf besar-kecil.
- Periksa Serial Monitor: apakah ESP32 benar-benar berhasil tersambung?
- Coba berlangganan `#` sementara waktu untuk melihat seluruh lalu lintas
  broker, lalu cari topic Anda di antaranya.

## Perintah baris perintah (alternatif)
```
mosquitto_sub -h broker.emqx.io -t "kelasA-nim123/labA/#" -v
mosquitto_pub -h broker.emqx.io -t "kelasA-nim123/labA/esp32-01/perintah" -m "NYALA"
```
