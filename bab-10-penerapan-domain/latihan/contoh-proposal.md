# Contoh Proposal Proyek IoT (terisi)

> Contoh acuan. Proposal Anda tidak harus sama, tetapi kelengkapan
> penalarannya sebaiknya setara.

**Judul:** Pemantauan dan Pengendalian Kualitas Udara Ruang Perpustakaan
**Kelompok / NIM:** Kelompok 3 / 21xxxx, 21xxxx, 21xxxx
**Tanggal:** 20 Mei 2026

---

## 1. Latar Belakang Masalah

Ruang perpustakaan sekolah berukuran sekitar 120 meter persegi dan pada jam
istirahat dapat menampung hingga 60 siswa sekaligus. Ventilasi ruangan
mengandalkan jendela yang sering ditutup karena kebisingan dari luar.
Beberapa siswa mengeluh pengap dan cepat mengantuk, sehingga enggan
berlama-lama membaca di sana.

**Siapa yang terdampak:** siswa yang memakai perpustakaan dan pustakawan
yang bertugas sepanjang hari.

**Mengapa perlu diselesaikan:** kenyamanan ruangan memengaruhi minat siswa
memanfaatkan perpustakaan; keluhan pengap sudah disampaikan berulang kali
tetapi belum pernah diukur secara obyektif.

**Bagaimana keadaannya sekarang:** kipas pembuang dinyalakan secara manual
berdasarkan perkiraan pustakawan, sering terlambat, dan tidak ada catatan
apa pun mengenai kondisi udara ruangan.

---

## 2. Tujuan dan Ruang Lingkup

**Tujuan:** mengurangi lama waktu ruangan berada pada kondisi pengap dengan
menyalakan kipas pembuang secara otomatis berdasarkan pengukuran.

**Yang akan dikerjakan:**
1. Memasang tiga titik pengukuran karbon dioksida, suhu, dan kelembaban.
2. Menyalakan kipas pembuang otomatis berdasarkan ambang dengan histeresis.
3. Menampilkan kondisi terkini dan riwayat pada dashboard.
4. Mengirim notifikasi kepada pustakawan bila kipas gagal menurunkan kadar.

**Yang TIDAK akan dikerjakan:**
1. Pengendalian pendingin ruangan (belum ada AC di perpustakaan).
2. Pemantauan ruangan lain di sekolah.
3. Aplikasi ponsel tersendiri; cukup dashboard berbasis web.
4. Pemasangan permanen ke instalasi listrik gedung; memakai stopkontak biasa.

---

## 3. Analisis Kebutuhan

| Besaran yang diukur | Selang pengiriman | Tindakan yang mengikuti |
|---------------------|-------------------|-------------------------|
| Kadar CO2 | 1 menit | Nyalakan kipas bila > 1000 ppm selama 10 menit |
| Suhu | 1 menit | Ditampilkan sebagai keterangan kenyamanan |
| Kelembaban | 1 menit | Ditampilkan sebagai keterangan kenyamanan |
| Status kipas | saat berubah | Ditampilkan pada dashboard |

---

## 4. Batasan Rancangan

| Pertanyaan | Jawaban |
|------------|---------|
| Jarak perangkat ke titik pusat | Dalam satu ruangan, kurang dari 20 meter |
| Ketersediaan jaringan listrik | Tersedia, stopkontak di tiap sudut |
| Tuntutan waktu tanggap | Menit, bukan detik; kondisi udara berubah lambat |
| Jumlah perangkat dan selang kirim | 3 perangkat, tiap 1 menit |
| Kepekaan data | Rendah; tidak memuat data pribadi siswa |
| Lama penyimpanan riwayat | Rinci 7 hari, ringkasan per jam 1 tahun |
| Anggaran | Maksimal Rp 1.500.000 |

---

## 5. Rancangan Solusi

**Arsitektur:**

```
Sensor CO2 + DHT22  ->  ESP32  ->  WiFi sekolah  ->  Broker MQTT
                          |                              |
                    relai kipas                    Basis data + Dashboard
                    (aturan lokal)                       |
                                                   Notifikasi pustakawan
```

**Pilihan teknologi dan alasannya:**

| Bagian | Pilihan | Alasan |
|--------|---------|--------|
| Sensor | Sensor CO2 + DHT22 | Kadar CO2 adalah penanda pengap yang paling langsung |
| Mikrokontroler | ESP32 | WiFi bawaan, cukup untuk tiga titik, tersedia di laboratorium |
| Konektivitas | WiFi | Jarak dalam satu ruangan dan listrik tersedia, sehingga LPWAN tidak diperlukan |
| Protokol | MQTT | Tiga perangkat mengirim tiap menit; lebih hemat daripada HTTP dan mendukung downlink |
| Penyimpanan | Basis data time-series | Data bercap waktu dan dibaca per rentang waktu |
| Letak pemrosesan | Edge untuk keputusan kipas | Kipas harus tetap bekerja meski WiFi sekolah terputus |
| Pengamanan | MQTT dengan autentikasi | Mencegah pihak lain menyalakan kipas atau mengirim data palsu |

**Perilaku ketika jaringan terputus:** ESP32 tetap menyalakan kipas
berdasarkan aturan lokal dengan histeresis. Data yang belum terkirim
disimpan sementara dan dikirim ulang setelah jaringan pulih.

---

## 6. Ukuran Keberhasilan

| No | Pernyataan terukur | Cara membuktikan |
|----|--------------------|------------------|
| 1 | Data tercatat setiap menit selama 7 hari berturut-turut dengan kehilangan tidak lebih dari 10 menit | Menghitung jumlah baris pada basis data dan membandingkannya dengan jumlah seharusnya |
| 2 | Lama waktu kadar CO2 di atas 1000 ppm berkurang minimal 40 persen dibanding pengukuran awal | Membandingkan catatan minggu pertama (tanpa kendali otomatis) dengan minggu kedua |
| 3 | Kipas menyala kurang dari 1 menit setelah syarat ambang terpenuhi | Mencocokkan cap waktu data dengan catatan status kipas |
| 4 | Sistem tetap mengendalikan kipas saat WiFi dimatikan selama 30 menit | Pengujian langsung dengan mematikan titik akses |

**Catatan:** minggu pertama sengaja dijalankan **tanpa** kendali otomatis
untuk memperoleh data pembanding. Tanpa data awal, keberhasilan tidak dapat
dibuktikan.

---

## 7. Rencana Kerja

| Minggu | Kegiatan | Luaran | Penanggung jawab |
|--------|----------|--------|------------------|
| 1 | Pengadaan komponen, uji sensor di meja | Sensor terbaca benar | A |
| 2 | Pemasangan tiga titik, pengukuran awal tanpa kendali | Data pembanding 7 hari | B |
| 3 | Aturan lokal kipas dan pengujian histeresis | Kipas otomatis berfungsi | C |
| 4 | Basis data, dashboard, dan notifikasi | Dashboard dapat diakses | A, B |
| 5 | Pengujian menyeluruh dan penyusunan laporan | Laporan dan bahan presentasi | Semua |

---

## 8. Kebutuhan Alat dan Bahan

| Komponen | Jumlah | Perkiraan biaya | Sudah tersedia? |
|----------|--------|-----------------|-----------------|
| ESP32 | 3 | Rp 300.000 | Ya, laboratorium |
| Sensor CO2 | 3 | Rp 900.000 | Belum |
| DHT22 | 3 | Rp 150.000 | Ya, laboratorium |
| Modul relai | 1 | Rp 25.000 | Belum |
| Kabel, kotak, catu daya | - | Rp 200.000 | Belum |

---

## 9. Risiko dan Penanggulangannya

| Risiko | Kemungkinan | Penanggulangan |
|--------|-------------|----------------|
| Sensor CO2 terlambat datang | Sedang | Mulai dengan DHT22 lebih dahulu; alur sistem tetap dapat diuji |
| WiFi sekolah membatasi perangkat baru | Sedang | Minta izin pengelola jaringan sejak minggu pertama |
| Kipas yang ada tidak memadai | Rendah | Ukur penurunan kadar pada pengujian awal; bila kurang, laporkan sebagai temuan |
| Data pembanding gagal terkumpul | Rendah | Simpan salinan lokal pada gateway |

---

## 10. Daftar Pustaka

[ Sesuaikan dengan rujukan yang Anda pakai. ]
