# Lembar Kerja Praktik Bab 8 - Pemrosesan di Edge

**Nama / NIM:** [ ... ]  **Tanggal:** [ ... ]

## 1. Tujuan
Menerapkan agregasi, penyaringan ambang, dan deteksi anomali di sisi perangkat,
lalu mengukur pengurangan volume data yang dihasilkan.

## 2. Pengukuran penghematan data
Jalankan selama 10 menit untuk setiap perlakuan.

| Perlakuan | Jumlah dibaca | Jumlah dikirim | Penghematan (%) |
|-----------|---------------|----------------|-----------------|
| Tanpa pemrosesan (kirim semua) | | | 0 |
| Agregasi rata-rata 10 cuplikan | | | |
| Agregasi + penyaringan ambang | | | |

[ Berapa persen total penghematan yang Anda peroleh? ]

## 3. Pengaruh nilai ambang
Ubah `AMBANG_KIRIM` lalu amati.

| AMBANG_KIRIM | Jumlah dikirim | Penghematan (%) | Apakah ada perubahan yang terlewat? |
|--------------|----------------|-----------------|--------------------------------------|
| 0.2 | | | |
| 0.5 | | | |
| 2.0 | | | |

## 4. Deteksi anomali
Jalankan `deteksi_anomali.ino`, lalu picu anomali dengan menghangatkan sensor.

| Pengali k | Jumlah anomali terdeteksi | Ada anomali palsu? | Ada yang terlewat? |
|-----------|---------------------------|--------------------|--------------------|
| 2.0 | | | |
| 3.0 | | | |

[ Apa akibat memilih k terlalu kecil? Apa akibat memilih k terlalu besar? ]

## 4b. Positif palsu pada data yang sangat stabil
Bila sensor sangat stabil, simpangan baku menjadi kecil sehingga batas normal
ikut menyempit. Akibatnya perubahan yang sebenarnya wajar dapat tertandai
sebagai anomali.

Ubah `SIMPANGAN_MIN` pada program, lalu amati.

| SIMPANGAN_MIN | Jumlah anomali | Apakah ada yang tampak wajar tetapi tertandai? |
|---------------|----------------|-----------------------------------------------|
| 0.05 | | |
| 0.30 | | |
| 1.00 | | |

[ Mengapa menetapkan batas bawah simpangan diperlukan? Apa risikonya bila
  batas itu ditetapkan terlalu besar? ]

## 5. Percobaan penting
Ubah program sehingga nilai anomali IKUT dimasukkan ke jendela. Jalankan
beberapa menit sambil terus menghangatkan sensor.

[ Apa yang terjadi pada rata-rata? Mengapa sistem lambat laun berhenti
  menandai anomali? ]

## 6. Analisis kehilangan informasi
[ Informasi apa yang hilang akibat penyaringan yang Anda terapkan?
  Dalam keadaan apa kehilangan itu dapat menjadi masalah? ]

## 7. Kesimpulan
[ ... ]
