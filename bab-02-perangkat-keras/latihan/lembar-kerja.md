# Lembar Kerja Praktik Bab 2

**Nama / NIM:** [ ... ]  **Tanggal:** [ ... ]

## 1. Tujuan
Menyiapkan toolchain dan membaca sensor DHT22 serta LDR pada ESP32.

## 2. Alat dan bahan
[ ESP32, DHT22, modul LDR, breadboard, kabel jumper / atau Wokwi ]

## 3. Pengawatan
[ Lampirkan foto/tangkapan rangkaian; rujuk rangkaian/pengawatan.md ]

## 4. Hasil pembacaan (Serial Monitor)
| Waktu | Suhu (C) | Kelembaban (%) | Cahaya mentah (ADC) | Cahaya terkalibrasi (%) |
|-------|----------|----------------|---------------------|--------------------------|
|       |          |                |                     |                          |
|       |          |                |                     |                          |

## 5. Analisis
[ Apa yang terjadi pada nilai cahaya saat sensor ditutup/diterangi? Apakah suhu wajar? ]

## 5b. Eksperimen pengondisian sinyal (Algoritma 2.1)
Ubah nilai `N_CUPLIKAN` pada kode menjadi 1, 10, lalu 50. Amati kestabilan pembacaan.

| N_CUPLIKAN | Nilai terendah | Nilai tertinggi | Selisih (kestabilan) |
|------------|----------------|-----------------|----------------------|
| 1          |                |                 |                      |
| 10         |                |                 |                      |
| 50         |                |                 |                      |

[ Apa pengaruh penambahan N terhadap derau? Apa kerugiannya jika N terlalu besar? ]

## 6. Tugas setup (terdokumentasi)
[ Tuliskan langkah instalasi toolchain dan library yang Anda lakukan, sertakan tangkapan layar ]

## 7. Kesimpulan
[ ... ]
