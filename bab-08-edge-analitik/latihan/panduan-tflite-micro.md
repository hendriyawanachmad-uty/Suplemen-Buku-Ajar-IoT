# Panduan TensorFlow Lite for Microcontrollers (TFLite Micro)

Berkas ini memuat nama pustaka dan langkah yang berlaku saat ini. Sengaja
diletakkan di repositori, bukan di buku, karena nama dan status pemeliharaan
pustaka TinyML cukup sering berubah.

> **Periksa dahulu.** Sebelum memakai, cari nama pustaka pada Library Manager
> Arduino IDE. Bila nama di bawah ini sudah tidak tersedia, gunakan nama yang
> muncul pada hasil pencarian dengan kata kunci "TensorFlow Lite".

## 1. Pilihan pustaka

| Sasaran | Pustaka | Catatan |
|---------|---------|---------|
| ESP32 | `esp-tflite-micro` (Espressif) | Kemasan resmi dari pengembang cip, untuk ESP-IDF maupun Arduino |
| ESP32 | `TensorFlowLite_ESP32` | Port komunitas, dipasang lewat Library Manager |
| Arduino umum | `Arduino_TensorFlowLite` | Pustaka lama dari TensorFlow Authors; sudah tidak dipelihara aktif |
| Arduino umum | Fork komunitas yang aktif | Cari "TensorFlow Lite" pada Library Manager |

## 2. Alur kerja lengkap

### Langkah 1 - Latih model (di komputer)
```python
import tensorflow as tf
model = tf.keras.Sequential([...])
model.compile(optimizer='adam', loss='mse')
model.fit(x_latih, y_latih, epochs=100)
```

### Langkah 2 - Ubah ke TensorFlow Lite + kuantisasi
```python
konverter = tf.lite.TFLiteConverter.from_keras_model(model)
konverter.optimizations = [tf.lite.Optimize.DEFAULT]   # kuantisasi
model_tflite = konverter.convert()
open("model.tflite", "wb").write(model_tflite)
```

Kuantisasi mengubah bilangan pecahan 32 bit menjadi bilangan bulat 8 bit,
sehingga ukuran model turun sekitar empat kali lipat dan inferensinya lebih
cepat pada mikrokontroler.

### Langkah 3 - Ubah menjadi larik C
Pada Linux atau macOS:
```
xxd -i model.tflite > model.h
```
Sunting `model.h`, ubah deklarasinya menjadi:
```c
const unsigned char model_tflite[] = { ... };
const int model_tflite_len = ...;
```

### Langkah 4 - Jalankan inferensi pada ESP32
Pola tetapnya:
1. Muat model dari larik C.
2. Daftarkan operasi (op resolver) yang dipakai model.
3. Siapkan interpreter beserta **tensor arena**.
4. Panggil `AllocateTensors()`.
5. Isi tensor masukan dengan data sensor.
6. Panggil `Invoke()`.
7. Baca tensor keluaran.

## 3. Menentukan ukuran tensor arena

Tensor arena adalah blok memori tetap tempat model bekerja. Ukurannya harus
ditentukan sendiri dan **tidak dapat bertambah** saat program berjalan.

- Terlalu kecil: `AllocateTensors()` gagal.
- Terlalu besar: memori terbuang, padahal SRAM ESP32 terbatas.

Cara praktis: mulai dari 10 KB, naikkan bertahap sampai `AllocateTensors()`
berhasil, lalu beri kelonggaran sekitar 20 persen.

## 4. Jalur alternatif tanpa menulis kode inferensi

Bila tujuannya mencoba alur TinyML tanpa menulis seluruh kode dari nol,
tersedia layanan yang membangkitkan pustaka Arduino secara otomatis dari data
latih (misalnya Edge Impulse). Alurnya: kumpulkan data, latih lewat antarmuka
web, unduh pustaka Arduino, lalu panggil fungsi klasifikasinya dari sketch.

Jalur ini cocok untuk pengenalan; jalur manual di atas tetap perlu dipahami
agar mahasiswa mengetahui apa yang sebenarnya terjadi.

## 5. Batasan yang perlu disadari

- Pelatihan model **tidak** dilakukan di ESP32, hanya inferensi.
- SRAM ESP32 sekitar 520 KB, sehingga hanya model kecil yang muat.
- Model besar seperti pengenalan gambar umum tidak akan muat.
- Untuk banyak persoalan IoT, aturan ambang dan statistik sederhana pada
  Bab 8 sudah memadai dan jauh lebih mudah ditelusuri ketika keliru.
