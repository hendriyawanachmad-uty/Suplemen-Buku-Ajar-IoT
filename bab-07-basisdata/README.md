# Bab 7 - Basis Data dan Visualisasi Data IoT

- **Bab pada buku:** 7
- **Minggu (RPS):** 11
- **CPMK:** CPMK5

## Praktik pada bab ini
Menyimpan telemetri ke dalam basis data, menyusun kueri ringkasan, mengukur
pengaruh indeks, merancang kebijakan retensi, lalu menampilkan datanya pada
dashboard.

## Isi folder
- `kode/skema.sql` - skema tabel untuk data sensor (SQLite/MySQL).
- `kode/kueri-contoh.sql` - kueri ringkasan, indeks, dan retensi.
- `kode/influx-line-protocol.txt` - contoh penulisan data InfluxDB.
- `kode/influx-kueri.txt` - contoh kueri InfluxQL dan Flux.
- `kode/mongo-contoh.js` - contoh dokumen dan kueri MongoDB.
- `kode/gateway_penyangga.py` - penyangga SQLite pada gateway.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `kunci-jawaban-bab-07.md` - kunci pilihan ganda & jawaban lengkap esai.

## Perangkat lunak yang diperlukan
Untuk latihan, **SQLite sudah memadai** dan tidak perlu dipasang secara
khusus karena tersedia bawaan pada Python. InfluxDB dan MongoDB bersifat
opsional; berkas contohnya disediakan agar dapat dipelajari meski tidak
dipasang.

## PENTING
1. **Indeks menentukan kecepatan.** Tanpa indeks pada kolom waktu, kueri
   rentang waktu harus memeriksa seluruh baris. Bandingkan sendiri melalui
   `kueri-contoh.sql`.
2. **Tag bukan tempat menyimpan hasil pengukuran.** Pada InfluxDB, menempatkan
   nilai suhu sebagai tag membuat jumlah deret membengkak tak terkendali.
3. **Penghapusan bersifat tetap.** Tetapkan kebijakan retensi setelah
   mempertimbangkan kemungkinan kebutuhan di kemudian hari, misalnya audit.
4. **Penyangga gateway ada batasnya.** Tentukan sejak awal apa yang dilakukan
   ketika penyimpanan lokal penuh.
