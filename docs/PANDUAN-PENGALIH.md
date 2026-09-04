# Panduan Halaman Pengalih (GitHub Pages)

Halaman pengalih membuat kode QR pada buku cetak tetap berfungsi meskipun
struktur folder repositori berubah.

## Cara kerjanya

```
QR di buku  ->  alamat pendek yang TETAP  ->  folder yang bisa BERUBAH
                (tercetak, tak bisa diubah)   (diatur lewat peta.txt)
```

Alamat pendeknya:
```
https://hendriyawanachmad-uty.github.io/Suplemen-Buku-Ajar-IoT/b7/
```

## Mengaktifkan sekali di awal

1. Unggah folder `docs/` ini ke repositori.
2. Buka repositori di GitHub, lalu pilih **Settings > Pages**.
3. Pada bagian **Build and deployment**:
   - Source: **Deploy from a branch**
   - Branch: **main**, folder: **/docs**
4. Simpan, lalu tunggu satu sampai dua menit.
5. Uji dengan membuka alamat pendek di atas pada peramban.

## Bila struktur folder berubah kelak

Cukup dua langkah:

1. Sunting `docs/peta.txt`, ubah nama folder tujuannya.
2. Jalankan dari dalam folder `docs/`:
   ```bash
   bash buat-pengalih.sh
   git add -A && git commit -m "Perbarui sasaran pengalih" && git push
   ```

Seluruh kode QR yang sudah tercetak otomatis mengarah ke tempat baru.
**Buku tidak perlu dicetak ulang.**

## Isi folder ini

| Berkas | Kegunaan |
|--------|----------|
| `peta.txt` | Sumber kebenaran: kode pendek dan folder tujuannya |
| `buat-pengalih.sh` | Membangkitkan ulang halaman pengalih dari `peta.txt` |
| `index.html` | Halaman muka berisi daftar seluruh bab |
| `b1/` … `b11/` | Halaman pengalih tiap bab |
| `.nojekyll` | Menonaktifkan pemrosesan Jekyll agar berkas disajikan apa adanya |
| `instalasi.md`, `daftar-komponen-BOM.md`, dll. | Dokumen pendukung (tetap dapat dibaca di GitHub) |

## Yang harus dijaga

Halaman pengalih melindungi dari perubahan **struktur folder**, tetapi tidak
melindungi dari hal berikut:

- **Mengganti nama akun GitHub** — seluruh alamat berubah.
- **Mengganti nama repositori** — seluruh alamat berubah.
- **Menghapus repositori** — seluruh alamat mati.
- **Mengubah repositori menjadi privat** — pembaca tidak dapat mengakses.

Ketiga hal pertama memutus semua kode QR yang sudah tercetak dan tidak dapat
diperbaiki. Karena itu tetapkan nama akun dan nama repositori sejak awal,
lalu jangan diubah selama buku masih beredar.

## Menguji sebelum buku dicetak

Pindai setiap kode QR memakai ponsel, bukan hanya membuka tautannya di
komputer. Pastikan halaman berpindah sendiri dalam beberapa detik dan
sampai ke folder yang benar.
