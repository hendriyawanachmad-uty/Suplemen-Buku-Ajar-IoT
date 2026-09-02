# Bab 4 - Konektivitas dan Jaringan IoT

- **Bab pada buku:** 4
- **Minggu (RPS):** 7 (sebelum UTS)
- **CPMK:** CPMK3

## Praktik pada bab ini
Menghubungkan ESP32 ke jaringan WiFi, lalu menjadikannya web server yang
menampilkan pembacaan sensor DHT22 pada peramban.

## Isi folder
- `kode/wifi_web_server.ino` - kode lengkap praktik.
- `kode/secrets.h.contoh` - templat kredensial (salin menjadi `secrets.h`).
- `rangkaian/pengawatan.md` - tabel pengawatan.
- `rangkaian/diagram.json` - berkas rangkaian untuk Wokwi.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `latihan/latihan-pemilihan-teknologi.md` - latihan penerapan Algoritma 4.1.
- `kunci-jawaban-bab-04.md` - kunci pilihan ganda & jawaban lengkap esai.

## PENTING: jangan pernah commit kredensial
Berkas `secrets.h` sudah masuk `.gitignore`. Yang boleh diunggah hanya
`secrets.h.contoh`. Nama dan kata sandi WiFi Anda jangan sampai ikut tersebar.

## Cara menjalankan
1. Salin `kode/secrets.h.contoh` menjadi `kode/secrets.h`, isi SSID dan kata sandi.
2. Rangkai DHT22 ke GPIO4 (lihat `rangkaian/pengawatan.md`).
3. Unggah `kode/wifi_web_server.ino`, buka Serial Monitor pada 115200.
4. Catat alamat IP yang muncul, lalu buka alamat itu pada peramban yang
   terhubung ke jaringan WiFi yang sama.

## Catatan
Alamat IP yang diperoleh bersifat LOKAL. Halaman hanya dapat dibuka dari
jaringan yang sama, bukan dari internet. Pemantauan dari mana saja memerlukan
platform awan, yang dibahas pada bab berikutnya.
