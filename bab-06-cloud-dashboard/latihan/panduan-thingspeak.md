# Panduan Membuat Akun dan Dashboard (ThingSpeak)

Panduan ini memakai ThingSpeak karena paling mudah untuk latihan. Prinsipnya
sama pada platform lain: daftarkan perangkat, ambil kredensial, kirim data,
lalu susun tampilan.

> Tampilan antarmuka platform dapat berubah sewaktu-waktu. Bila menu tidak
> persis sama, cari istilah yang serupa.

## 1. Membuat akun dan channel
1. Daftar akun gratis pada situs ThingSpeak.
2. Buat **Channel** baru. Satu channel mewakili satu perangkat.
3. Aktifkan **Field 1** (beri nama "Suhu") dan **Field 2** (beri nama "Kelembaban").
4. Simpan channel.

## 2. Mengambil kredensial (provisioning)
1. Buka tab **API Keys** pada channel Anda.
2. Salin **Write API Key**. Inilah kredensial yang dipakai perangkat.
3. Tempelkan pada `secrets.h` sebagai `KUNCI_API`.

**Jangan bagikan Write API Key.** Siapa pun yang memilikinya dapat mengirim
data palsu ke channel Anda.

## 3. Mengirim data
1. Unggah `kode/kirim_cloud_http.ino`.
2. Buka Serial Monitor. Kode HTTP **200** berarti berhasil.
3. Buka tab **Private View** pada channel; grafik akan terisi.

Bila kode yang muncul **0** atau negatif, biasanya WiFi belum tersambung.
Bila muncul **400**, periksa kembali Write API Key dan nama field.

## 4. Menyusun dashboard
1. Grafik garis sudah tersedia otomatis untuk setiap field.
2. Tambahkan widget **Gauge**: pilih Add Widgets > Gauge, arahkan ke Field 1,
   lalu tetapkan rentang minimum dan maksimum.
3. Atur judul dan rentang waktu tampilan sesuai kebutuhan.

## 5. Membuat notifikasi (React)
1. Buka menu **Apps > React**.
2. Buat React baru dengan kondisi, misalnya Field 1 lebih besar dari 30.
3. Pilih tindakan, misalnya mengirim surel melalui ThingHTTP.
4. Simpan, lalu uji dengan menghangatkan sensor.

## Batas versi gratis
ThingSpeak versi gratis membatasi pengiriman menjadi **satu kali tiap 15 detik**.
Karena itu kode contoh memakai selang 20 detik. Mengirim lebih cepat membuat
sebagian data ditolak tanpa pemberitahuan yang jelas.

## Alternatif platform
- **Blynk** bila ingin aplikasi ponsel dan tombol kendali yang mudah.
- **Antares** bila ingin layanan lokal dengan dokumentasi berbahasa Indonesia.
- Untuk latihan MQTT dua arah, gunakan `kode/kirim_cloud_mqtt.ino` dengan
  broker seperti pada Bab 5.
