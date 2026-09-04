# Lembar Kerja Praktik Bab 7 - Basis Data dan Visualisasi

**Nama / NIM:** [ ... ]  **Tanggal:** [ ... ]

## 1. Tujuan
Menyimpan telemetri ke basis data, menyusun kueri ringkasan, mengukur
pengaruh indeks, merancang kebijakan retensi, dan menampilkan data pada
dashboard.

## 2. Rancangan skema
| Tabel | Kolom | Alasan |
|-------|-------|--------|
| | | |
| | | |

[ Mengapa data perangkat dipisahkan dari data pembacaan? ]

## 3. Pengumpulan data
| Butir | Hasil |
|-------|-------|
| Lama pengumpulan | 30 menit |
| Selang pengiriman | |
| Jumlah baris terkumpul | |
| Perkiraan baris per hari | |
| Perkiraan baris per tahun | |

## 4. Kueri ringkasan
Tulis kueri untuk rata-rata, minimum, dan maksimum per lima menit.

```sql
[ tulis kueri Anda di sini ]
```

| Waktu | Rata | Min | Maks | Jumlah data |
|-------|------|-----|------|-------------|
| | | | | |

## 5. Pengaruh indeks
Jalankan `EXPLAIN QUERY PLAN` sebelum dan sesudah membuat indeks.
Gunakan **koneksi baru** setelah membuat indeks.

| Keadaan | Rencana kueri | Waktu eksekusi |
|---------|---------------|----------------|
| Tanpa indeks | | |
| Dengan indeks | | |

[ Berapa kali lipat perbedaannya? Apa yang terjadi bila jumlah baris
  bertambah sepuluh kali lipat? ]

## 6. Rancangan retensi
| Tingkat | Rincian | Lama simpan | Perkiraan jumlah baris |
|---------|---------|-------------|------------------------|
| Data mentah | | | |
| Ringkasan per jam | | | |
| Ringkasan per hari | | | |

[ Berapa penghematan penyimpanan yang Anda peroleh? ]
[ Data apa yang hilang selamanya akibat kebijakan ini? ]

## 7. Percobaan tag dan field (bila memakai InfluxDB)
| Penempatan | Jumlah deret setelah 1 jam | Catatan |
|------------|----------------------------|---------|
| suhu sebagai field (benar) | | |
| suhu sebagai tag (keliru) | | |

[ Mengapa menempatkan nilai ukur sebagai tag berbahaya? ]

## 8. Penyangga gateway
Jalankan `gateway_penyangga.py`, lalu ubah `kirim_ke_cloud` agar
mengembalikan `False` untuk meniru jaringan terputus.

| Keadaan | Jumlah baris menunggu | Apakah data hilang? |
|---------|----------------------|---------------------|
| Jaringan normal | | |
| Jaringan terputus 2 menit | | |
| Setelah jaringan pulih | | |

## 9. Dashboard
| Widget | Data | Alasan pemilihan |
|--------|------|------------------|
| | | |
| | | |

## 10. Uji membedakan keadaan (penting)
Matikan perangkat beberapa menit.

[ Apakah dashboard Anda dapat membedakan "suhu stabil" dari "perangkat mati"?
  Bila belum, apa yang perlu ditambahkan? ]

## 11. Kesimpulan
[ ... ]
