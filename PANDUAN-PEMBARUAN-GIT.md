# Panduan Memperbarui Repositori (Bab 6 sampai Bab 9)

Berkas ini menjelaskan cara memasukkan perubahan struktur bab ke repositori
GitHub Anda yang sudah ada.

---

## Ringkasan perubahan

| Yang berubah | Keterangan |
|--------------|------------|
| Folder diganti nama | `bab-06-cloud-dashboard` → `bab-06-platform-cloud` |
| | `bab-07-edge-analitik` → `bab-08-edge-analitik` |
| | `bab-08-keamanan` → `bab-09-keamanan` |
| | `bab-09-penerapan-domain` → `bab-10-penerapan-domain` |
| | `bab-10-proyek-end-to-end` → `bab-11-proyek-end-to-end` |
| Folder baru | `bab-07-basisdata` |
| Berkas akar diperbarui | `README.md`, `CHANGELOG.md`, `.gitignore` |

---

## Pilihan A: memakai Git (dianjurkan)

Cara ini menjaga riwayat perubahan sehingga penggantian nama folder tercatat
sebagai *rename*, bukan sebagai penghapusan lalu penambahan.

```bash
# 1. Masuk ke salinan lokal repositori Anda
cd buku-ajar-iot-esp32
git pull                       # pastikan salinan terbaru

# 2. Ganti nama folder MULAI DARI NOMOR BESAR
#    (urutan ini penting agar nama tidak bentrok)
git mv bab-10-proyek-end-to-end  bab-11-proyek-end-to-end
git mv bab-09-penerapan-domain   bab-10-penerapan-domain
git mv bab-08-keamanan           bab-09-keamanan
git mv bab-07-edge-analitik      bab-08-edge-analitik
git mv bab-06-cloud-dashboard    bab-06-platform-cloud

# 3. Salin isi baru dari paket yang disediakan
#    (timpa folder bab-06 s/d bab-09, lalu tambahkan bab-07-basisdata)
#    Salin pula README.md, CHANGELOG.md, dan .gitignore dari paket.

# 4. Periksa apa saja yang berubah SEBELUM dikirim
git status
git diff --stat

# 5. Pastikan tidak ada kredensial yang ikut
git status --porcelain | grep -i "secrets.h$"    # harus KOSONG
git status --porcelain | grep -iE "\.db$"        # harus KOSONG

# 6. Kirim
git add -A
git commit -m "Struktur 11 bab: pecah Bab 6, tambah Bab 7 basis data"
git push
```

### Bila nama berkas kunci jawaban juga berubah
```bash
git mv bab-08-edge-analitik/kunci-jawaban-bab-07.md \
       bab-08-edge-analitik/kunci-jawaban-bab-08.md
git mv bab-09-keamanan/kunci-jawaban-bab-08.md \
       bab-09-keamanan/kunci-jawaban-bab-09.md
```
(Bila Anda menyalin dari paket, langkah ini sudah termasuk.)

---

## Pilihan B: melalui peramban, tanpa Git

Cukup untuk yang belum terbiasa dengan Git, tetapi riwayat penggantian nama
tidak tercatat rapi.

1. Buka repositori di GitHub.
2. Hapus folder `bab-06-cloud-dashboard`, `bab-07-edge-analitik`, dan
   `bab-08-keamanan` melalui menu tiap berkas.
3. Pilih **Add file > Upload files**, lalu seret folder baru
   (`bab-06-platform-cloud`, `bab-07-basisdata`, `bab-08-edge-analitik`,
   `bab-09-keamanan`) ke jendela peramban sekaligus.
4. Unggah pula `README.md`, `CHANGELOG.md`, dan `.gitignore` yang baru.
5. Tulis pesan commit, lalu simpan.

---

## Setelah berhasil diunggah

### 1. Buat rilis bertanda
Agar kode QR pada buku menunjuk versi yang tetap:
```bash
git tag -a v0.2.0 -m "Struktur 11 bab"
git push origin v0.2.0
```

### 2. Ambil URL commit untuk kode QR
Untuk setiap bab, buka foldernya di GitHub lalu salin URL yang memuat
**commit hash**, bukan `main`. Bentuknya:
```
https://github.com/USERNAME/REPO/tree/<commit-hash>/bab-07-basisdata
```
Kirimkan URL tersebut agar kode QR tiap bab dapat dibuatkan.

### 3. Yang PERLU diperhatikan tentang QR lama
Kode QR Bab 1 dan Bab 2 yang sudah tertanam di buku menunjuk ke commit lama.
QR itu **tetap berfungsi** dan mengarah ke struktur folder saat itu. Hal ini
disengaja: buku yang sudah dicetak tetap cocok dengan kodenya. Jangan
menghapus commit lama dari repositori.

---

## Daftar periksa sebelum push

- [ ] Tidak ada berkas `secrets.h` (hanya `secrets.h.contoh`)
- [ ] Tidak ada berkas `*.db` hasil latihan
- [ ] `.gitignore` yang baru sudah disalin
- [ ] `README.md` memuat pemetaan 11 bab
- [ ] `CHANGELOG.md` mencatat perubahan struktur
- [ ] `git status` sudah diperiksa sebelum `git add`
