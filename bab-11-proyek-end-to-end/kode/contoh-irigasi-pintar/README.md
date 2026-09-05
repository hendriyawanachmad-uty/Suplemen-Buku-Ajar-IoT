# Contoh Proyek: Sistem Irigasi Pintar

Contoh acuan yang menunjukkan bagaimana seluruh bab disatukan menjadi satu
sistem. Bukan untuk disalin apa adanya, melainkan untuk dipelajari polanya.

## Masalah
Petani harus datang ke lahan untuk memeriksa kelembaban tanah dan menyalakan
pompa, padahal lahan jauh dari rumah dan tanpa jaringan listrik.

## Spesifikasi

| No | Spesifikasi | Nilai | Cara memeriksa |
|----|-------------|-------|----------------|
| 1 | Kelembaban tanah diukur | tiap 15 menit | Hitung jumlah baris per jam pada basis data |
| 2 | Pompa menyala otomatis | di bawah 30% | Amati status relai saat sensor dibasahi/dikeringkan |
| 3 | Pompa mati | di atas 45% | Histeresis; amati tidak berkedip di sekitar ambang |
| 4 | Sistem tetap bekerja tanpa jaringan | ya | Matikan gateway 30 menit, amati pompa |
| 5 | Baterai bertahan | minimal 30 hari | Ukur konsumsi arus, hitung dari kapasitas baterai |

## Arsitektur

```
Sensor kelembaban  ->  ESP32  ->  LoRa  ->  Gateway  ->  Cloud  ->  Dashboard
                         |                     |
                    relai pompa           SQLite lokal
                  (aturan lokal,         (penyangga saat
                   Bab 3 histeresis)      jaringan putus)
```

## Pemilihan komponen dan alasannya

| Bagian | Pilihan | Alasan | Bab |
|--------|---------|--------|-----|
| Sensor | Kelembaban tanah kapasitif | Lebih awet daripada jenis resistif di tanah basah | 2 |
| Mikrokontroler | ESP32 | Mendukung deep sleep untuk menghemat baterai | 2, 3 |
| Konektivitas | LoRa | Jarak 1,5 km tanpa listrik; WiFi tidak menjangkau | 4 |
| Protokol | MQTT di sisi gateway | Hemat dan mendukung perintah balik | 5 |
| Penyimpanan | Time-series + SQLite di gateway | Data bercap waktu; penyangga saat jaringan putus | 7 |
| Pemrosesan | Edge di ESP32 | Pompa harus tetap bekerja tanpa jaringan | 8 |
| Keamanan | Autentikasi pada broker | Mencegah pihak lain menyalakan pompa | 9 |

## Tahapan integrasi yang ditempuh

| Tahap | Yang ditambahkan | Cara memastikan berhasil |
|-------|------------------|--------------------------|
| 1 | Baca sensor kelembaban | Nilai berubah saat sensor dibasahi |
| 2 | Kendali relai + histeresis | Pompa tidak berkedip di sekitar ambang |
| 3 | Deep sleep | Konsumsi arus turun; perangkat bangun tepat waktu |
| 4 | Kirim via LoRa | Paket diterima gateway |
| 5 | Penyangga SQLite di gateway | Data tersimpan saat internet dimatikan |
| 6 | Cloud dan dashboard | Grafik terisi, kendali jarak jauh berfungsi |

## Hasil pengujian ketahanan

| Gangguan | Perilaku | Sesuai harapan? |
|----------|----------|-----------------|
| Internet mati 2 jam | Pompa tetap otomatis; data mengantre di gateway | Ya |
| Gateway dimatikan | Pompa tetap otomatis; data node hilang pada rentang itu | Ya, sesuai rancangan |
| Menyala 7 hari | 668 dari 672 data tersimpan (99,4%) | Ya |

## Keterbatasan yang dilaporkan

1. Data node hilang bila gateway mati, sebab node tidak memiliki penyangga.
2. Umur baterai baru diperkirakan dari pengukuran arus, belum diuji 30 hari penuh.
3. Kalibrasi sensor kelembaban bersifat relatif, belum terhadap alat ukur baku.

> Keterbatasan yang dilaporkan jujur bernilai lebih tinggi daripada klaim
> keberhasilan yang tidak dapat dibuktikan.
