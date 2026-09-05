# Bab 11 - Perancangan Proyek IoT End-to-End

- **Bab pada buku:** 11
- **Minggu (RPS):** 15 (dinilai pada UAS)
- **CPMK:** CPMK7

## Praktik pada bab ini
Membangun proyek akhir: dari spesifikasi, integrasi bertahap, pengujian empat
lapis, evaluasi, hingga dokumentasi dan demonstrasi.

## Isi folder
- `latihan/templat-laporan-akhir.md` - susunan laporan proyek.
- `latihan/lembar-uji.md` - lembar pencatatan keempat lapis pengujian.
- `latihan/daftar-periksa-demo.md` - kesiapan sebelum presentasi.
- `latihan/rubrik-penilaian.md` - rubrik rinci tiap tingkat capaian.
- `kode/contoh-irigasi-pintar/` - contoh proyek lengkap sebagai acuan.
- `kode/kelompok-XX/` - tempat kode proyek mahasiswa (buat subfolder sendiri).

## Cara kerja yang dianjurkan

**Bangun bertahap, simpan tiap tahap.** Jangan merakit seluruh bagian
sekaligus. Tambah satu bagian, uji, pastikan berjalan, commit, baru lanjut.

Urutan yang disarankan:
```
1. Sensor            -> nilai terbaca benar di Serial Monitor
2. + WiFi            -> alamat IP diperoleh, koneksi stabil
3. + MQTT / HTTP     -> pesan terlihat pada aplikasi klien
4. + Penyimpanan     -> baris bertambah pada basis data
5. + Dashboard       -> grafik dan kendali berfungsi
6. + Aturan lokal    -> tetap bekerja saat jaringan dimatikan
```

Dengan cara ini Anda selalu punya versi yang berfungsi, sehingga demonstrasi
tetap dapat dilakukan meski belum seluruh fitur selesai.

## Peringatan yang paling sering terbukti

1. **Uji berjam-jam, bukan beberapa menit.** Kebocoran memori dan hubungan
   yang terputus tanpa disambung ulang baru muncul setelah lama menyala.
2. **Uji pada jaringan selain jaringan laboratorium.** Ini penyebab
   kegagalan demonstrasi yang paling umum.
3. **Siapkan rekaman cadangan demonstrasi.**
4. **Jangan commit kredensial.** Periksa `git status` sebelum `git add`.
5. **Laporkan hasil yang tidak sesuai harapan.** Temuan negatif tetap sah
   sepanjang disertai analisis.
