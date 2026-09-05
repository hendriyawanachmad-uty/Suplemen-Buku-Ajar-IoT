# Kode Proyek Akhir

## Struktur yang disarankan

```
kode/
├── contoh-irigasi-pintar/    <- proyek contoh sebagai acuan
└── kelompok-XX/              <- buat subfolder untuk kelompok Anda
    ├── README.md             <- cara membangun ulang dari nol
    ├── secrets.h.contoh       <- templat kredensial (JANGAN yang asli)
    ├── src/                  <- kode program
    └── rangkaian/            <- diagram dan berkas Wokwi
```

## Aturan penting

1. **Jangan commit `secrets.h` yang asli.** Hanya `secrets.h.contoh`.
   Periksa `git status` sebelum `git add`.
2. **Commit setiap tahap yang berjalan**, jangan menunggu selesai semuanya.
   Pesan commit yang baik: "Tahap 3: publish MQTT berhasil".
3. **README kelompok wajib memuat cara membangun ulang dari nol**, sehingga
   orang lain dapat menjalankan sistem Anda tanpa bertanya.
