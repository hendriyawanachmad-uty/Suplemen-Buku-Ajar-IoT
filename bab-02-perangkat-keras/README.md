# Bab 2 - Perangkat Keras IoT: ESP32, Sensor, dan Aktuator

- **Bab pada buku:** 2
- **Minggu (RPS):** 3-4
- **CPMK:** CPMK2

## Praktik pada bab ini
Menyiapkan lingkungan pengembangan, lalu membaca sensor DHT22 (suhu & kelembaban)
dan LDR (cahaya) pada ESP32. Dapat dikerjakan pada perangkat keras nyata maupun Wokwi.

## Isi folder
- `kode/blink.ino` - uji toolchain (kedip LED bawaan).
- `kode/baca_dht_ldr.ino` - kode lengkap pembacaan DHT22 + LDR;
  merupakan implementasi Algoritma 2.1 (pengondisian sinyal + kalibrasi).
- `rangkaian/pengawatan.md` - tabel pengawatan.
- `rangkaian/diagram.json` - berkas rangkaian untuk Wokwi.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `kunci-jawaban-bab-02.md` - kunci pilihan ganda & jawaban lengkap esai.

## Library yang diperlukan
- DHT sensor library (Adafruit) beserta dependensinya (Adafruit Unified Sensor).

## Cara menjalankan
1. Pasang toolchain (lihat `../docs/instalasi.md`) dan library DHT.
2. Rangkai sesuai `rangkaian/pengawatan.md` (DHT22 -> GPIO4, LDR AO -> GPIO34).
3. Unggah `kode/baca_dht_ldr.ino`, buka Serial Monitor pada 115200.

## Catatan: hubungan dengan Algoritma 2.1
Buku menyajikan Algoritma 2.1 dalam bentuk pseudocode agar bebas bahasa pemrograman.
Berkas `kode/baca_dht_ldr.ino` adalah implementasinya dalam Arduino/C++:

| Langkah Algoritma 2.1 | Bagian pada kode |
|-----------------------|------------------|
| 1-6 (rata-rata N cuplikan) | perulangan di dalam `bacaTerkalibrasi()` |
| 7 (pengondisian: rata-rata) | `float rata = (float) jumlah / n;` |
| 8 (kalibrasi ke satuan fisik) | pemanggilan `peta(...)` |
| 9 (kembalikan nilai) | `return nilai;` |

Parameter `N_CUPLIKAN`, `ADC_MAKS`, `CAHAYA_MIN`, dan `CAHAYA_MAKS` dapat diubah
untuk bereksperimen dengan tingkat penghalusan dan rentang kalibrasi.
