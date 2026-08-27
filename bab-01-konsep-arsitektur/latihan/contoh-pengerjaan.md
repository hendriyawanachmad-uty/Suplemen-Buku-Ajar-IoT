# Contoh Pengerjaan: Pemetaan Sistem Rumah Pintar

> Contoh acuan. Jawaban mahasiswa dapat berbeda selama argumentasinya tepat.

## 1. Sistem IoT yang dipilih
Sistem rumah pintar untuk pencahayaan dan pendingin ruangan otomatis.

## 2. Deskripsi masalah
Penghuni ingin lampu dan AC menyala otomatis saat ada orang dan mati saat ruangan kosong,
serta dapat dikontrol dari ponsel untuk menghemat energi.

## 3. Pemetaan komponen ekosistem
| Komponen ekosistem | Bagian pada sistem |
|--------------------|--------------------|
| Perangkat | Sensor gerak (PIR), sensor suhu, relai lampu & AC, mikrokontroler ESP32 |
| Konektivitas | WiFi rumah |
| Pemrosesan | Edge di ESP32 (aturan sederhana) + cloud (riwayat & jadwal) |
| Aplikasi / analitik | Aplikasi ponsel / dashboard, notifikasi |
| Pengguna | Penghuni rumah |

## 4. Arsitektur tiga lapis
| Lapisan | Komponen |
|---------|----------|
| Persepsi | Sensor gerak, sensor suhu, relai lampu & AC |
| Jaringan | WiFi ESP32 menuju gateway/router |
| Aplikasi | Aplikasi ponsel yang memantau dan mengendalikan |

## 5. Arsitektur lima lapis
| Lapisan | Komponen |
|---------|----------|
| Persepsi | Sensor gerak & suhu, relai |
| Transport | WiFi, router rumah |
| Pemrosesan | Aturan on/off di ESP32 (edge); penyimpanan riwayat di cloud |
| Aplikasi | Dashboard/aplikasi ponsel, notifikasi |
| Bisnis | Kebijakan penghematan energi, laporan konsumsi |

## 6. Aliran data end-to-end
1. Sensor gerak mendeteksi kehadiran dan sensor suhu membaca suhu ruangan.
2. ESP32 membaca data dan menerapkan aturan (mis. jika ada orang dan suhu tinggi, nyalakan AC).
3. Perintah dikirim ke relai untuk menyalakan lampu/AC (aksi di edge, cepat).
4. Data dikirim via WiFi ke cloud untuk disimpan sebagai riwayat.
5. Penghuni memantau dan mengganti mode melalui aplikasi ponsel.

## 7. Refleksi
Keputusan menyalakan lampu/AC dilakukan di edge (ESP32) agar responsif dan tetap bekerja
walau internet terputus. Penyimpanan riwayat dan analisis pola dilakukan di cloud karena
membutuhkan kapasitas lebih besar dan tidak menuntut kecepatan tinggi.
