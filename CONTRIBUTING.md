# Panduan Kontribusi

Terima kasih atas minat Anda memperbaiki repositori ini.

## Melaporkan kesalahan
- Buka **Issue** dengan menyebutkan bab, nama berkas, dan langkah untuk menghasilkan masalah.
- Kesalahan pada isi buku dapat pula dicatat di [`docs/erata.md`](docs/erata.md).

## Menamb/memperbaiki kode
1. Fork repositori, buat branch baru (`git checkout -b perbaikan-bab-03`).
2. Ikuti konvensi header berkas kode (lihat berkas contoh pada `bab-*/kode/`).
3. Jangan pernah meng-commit kredensial (SSID, password, token). Gunakan `secrets.h` yang
   sudah masuk `.gitignore`, dan sediakan `secrets.h.contoh`.
4. Uji kode pada ESP32 atau Wokwi sebelum mengirim Pull Request.
5. Perbarui `CHANGELOG.md` bila relevan.

## Gaya penulisan
- Bahasa Indonesia baku untuk dokumentasi; komentar kode boleh dwibahasa.
- Nama berkas: huruf kecil, pisahkan dengan tanda hubung, deskriptif.
