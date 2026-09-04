# Kunci Jawaban Self-Assessment - Bab 7

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | c | 7 | b |
| 2 | b | 8 | c |
| 3 | d | 9 | d |
| 4 | b | 10 | a |
| 5 | c | 11 | c |
| 6 | a | 12 | a |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Ciri data IoT dan kesesuaian basis data time-series

**Ciri khas data IoT:**
1. Setiap catatan disertai **cap waktu**.
2. Baris baru **terus bertambah**, sedangkan baris lama hampir tidak pernah
   diubah maupun dihapus satu per satu.
3. Pembacaan umumnya berupa **rentang waktu** (mis. suhu 24 jam terakhir),
   bukan pencarian satu baris tertentu.
4. **Volumenya tumbuh cepat**; satu sensor tiap 10 detik menghasilkan lebih
   dari 8.000 baris per hari.

**Mengapa time-series lebih sesuai untuk telemetri:**
- Basis data time-series dioptimalkan justru untuk pola tersebut, yaitu
  penulisan berurutan dan pembacaan per rentang waktu, sehingga jauh lebih
  cepat pada pekerjaan itu.
- Menyediakan **kebijakan retensi bawaan**, sehingga data lama terhapus
  otomatis tanpa program tambahan. Pada basis data relasional, penghapusan
  harus dijadwalkan sendiri.
- Menyediakan fungsi agregasi berbasis waktu (mis. `GROUP BY time(1h)`) yang
  ringkas, sedangkan pada SQL harus ditulis dengan fungsi pemformatan tanggal.
- Penyimpanannya lebih padat karena strukturnya seragam.

Namun basis data relasional tetap diperlukan untuk data yang saling berelasi
seperti daftar perangkat, lokasi, dan pengguna. Keduanya lazim dipakai
bersama dalam satu sistem.

### Esai 2 - Tag dan field pada InfluxDB

**Tag** adalah keterangan yang dipakai untuk **menyaring dan mengelompokkan**,
misalnya gedung, ruang, atau nama perangkat. Tag **diindeks**, sehingga
penyaringan berdasarkan tag berlangsung cepat. Nilainya berupa teks dan
jumlah kemungkinannya terbatas.

**Field** adalah **nilai yang diukur**, misalnya suhu dan kelembaban. Field
**tidak diindeks**, tetapi dapat dihitung rata-rata, minimum, maksimum, dan
seterusnya.

Aturan praktisnya: yang dipakai untuk **menyaring** menjadi tag, yang
**diukur dan dihitung** menjadi field.

**Akibat bila nilai pengukuran keliru ditempatkan sebagai tag:**

Setiap nilai suhu yang berbeda akan membentuk **deret (series) baru**. Nilai
28,4 membentuk satu deret, 28,5 membentuk deret lain, dan seterusnya. Dalam
sehari saja dapat muncul ribuan deret untuk satu sensor.

Dampaknya:
1. **Memori membengkak**, sebab InfluxDB menyimpan indeks seluruh deret di
   memori.
2. **Kueri melambat drastis**, karena harus menelusuri sangat banyak deret.
3. Basis data dapat **berhenti bekerja** ketika memori habis.

Persoalan ini dikenal sebagai *high cardinality*, dan termasuk kesalahan
paling umum sekaligus paling merusak pada penggunaan basis data time-series.
Kekeliruannya juga sulit diperbaiki setelah data telanjur banyak.

### Esai 3 - Rancangan retensi dan agregasi 30 ruang kelas

**Perhitungan volume:**
- 1 perangkat, tiap 10 detik = 6 baris/menit = 8.640 baris/hari
- 30 perangkat = **259.200 baris/hari** = sekitar 94,6 juta baris/tahun

Menyimpan seluruhnya jelas tidak praktis, baik dari sisi penyimpanan maupun
kecepatan tampilan grafik.

**Rancangan bertingkat:**

| Tingkat | Rincian | Lama simpan | Baris/tahun |
|---------|---------|-------------|-------------|
| Data mentah | tiap 10 detik | 7 hari | ~1,8 juta |
| Ringkasan per jam | rata, min, maks | 1 tahun | ~262.800 |
| Ringkasan per hari | rata, min, maks | 5 tahun | ~54.750 |

Total jauh di bawah 94,6 juta baris, dengan penghematan lebih dari 97 persen.

**Pertimbangan:**
1. **Data mentah 7 hari** cukup untuk menelusuri kejadian yang baru saja
   terjadi, misalnya keluhan ruangan panas minggu ini.
2. **Ringkasan per jam 1 tahun** memadai untuk melihat tren musiman dan
   membandingkan antar-semester.
3. **Ringkasan per hari 5 tahun** cukup untuk laporan tahunan tanpa memakan
   banyak tempat.
4. **Agregasi harus berhasil sebelum penghapusan.** Urutannya wajib: ringkas
   dahulu, periksa hasilnya, baru hapus data mentah.
5. **Penghapusan bersifat tetap.** Perlu dipertimbangkan kemungkinan audit
   atau keluhan yang baru muncul berbulan-bulan kemudian. Bila ada kewajiban
   menyimpan bukti, jangka waktunya harus disesuaikan.
6. Simpan juga **minimum dan maksimum**, bukan hanya rata-rata, sebab lonjakan
   sesaat akan tersamar bila hanya rata-rata yang disimpan.

Jawaban lain dapat diterima sepanjang perhitungan volumenya benar dan
pertimbangannya masuk akal.
