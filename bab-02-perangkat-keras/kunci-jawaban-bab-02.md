# Kunci Jawaban Self-Assessment - Bab 2

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | c | 7 | b |
| 2 | c | 8 | a |
| 3 | b | 9 | d |
| 4 | b | 10 | a |
| 5 | a | 11 | c |
| 6 | c | 12 | b |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%), serta
kejelasan penyajian (20%).

### Esai 1 - MCU, MPU, SoC, dan mengapa ESP32 disebut SoC
- **MCU (mikrokontroler):** menggabungkan prosesor, memori, dan periferal dalam satu chip;
  hemat daya, untuk tugas kendali, tanpa sistem operasi.
- **MPU (mikroprosesor):** hanya unit pemrosesan yang kuat; memerlukan memori dan
  penyimpanan eksternal serta umumnya menjalankan sistem operasi penuh (Linux).
- **SoC (System on Chip):** integrasi lebih luas, termasuk modul nirkabel, dalam satu chip.

ESP32 tepat disebut SoC karena memuat inti mikrokontroler sekaligus radio WiFi dan
Bluetooth dalam satu chip. Integrasi konektivitas inilah yang membuatnya siap dipakai
sebagai node IoT tanpa modul tambahan.

### Esai 2 - I2C vs SPI
- **I2C:** dua kabel bersama (SDA, SCL); banyak perangkat berbagi satu bus dengan alamat
  masing-masing; kecepatan menengah; hemat pin. Cocok untuk menghubungkan beberapa sensor
  berkecepatan rendah, mis. sensor lingkungan dan layar OLED pada bus yang sama.
- **SPI:** jalur terpisah (MOSI, MISO, SCK, CS); kecepatan tinggi; tiap perangkat butuh
  jalur CS sendiri; memakai lebih banyak pin. Cocok untuk perangkat yang menuntut kecepatan
  tinggi, mis. kartu SD atau layar TFT.

### Esai 3 - Pemilihan perangkat keras node cuaca bertenaga baterai
- **Mikrokontroler:** ESP32 karena WiFi bawaan dan mode deep sleep untuk menghemat baterai.
- **Sensor:** DHT22 untuk suhu & kelembaban (digital, mudah dibaca) dan LDR untuk cahaya
  (analog, murah). Pilih sensor sesuai rentang ukur dan ketelitian yang dibutuhkan.
- **Catu daya:** baterai dengan regulator yang efisien; manfaatkan deep sleep sehingga
  perangkat hanya aktif saat membaca dan mengirim data.
- **Konektivitas:** WiFi bila ada jangkauan; untuk lahan sangat luas tanpa WiFi,
  pertimbangkan LoRa (dibahas pada bab konektivitas).

Kunci penilaian: kesesuaian pilihan dengan kebutuhan hemat daya, jangkauan, dan ketelitian,
serta alasan yang logis.
