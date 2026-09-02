# Kunci Jawaban Self-Assessment - Bab 5

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | b | 7 | a |
| 2 | c | 8 | b |
| 3 | a | 9 | b |
| 4 | b | 10 | b |
| 5 | c | 11 | a |
| 6 | c | 12 | b |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Permintaan-tanggapan vs terbit-langgan

**Permintaan-tanggapan:** klien mengirim permintaan, server membalas. Data
hanya mengalir ketika diminta. Klien harus tahu alamat server, dan keduanya
harus aktif pada saat yang sama. Contoh: HTTP.

**Terbit-langgan:** pengirim menerbitkan pesan ke perantara (broker), pihak
yang berminat berlangganan pada broker. Broker meneruskan pesan kepada semua
pelanggan. Pengirim dan penerima tidak saling mengenal. Contoh: MQTT.

Terbit-langgan lebih sesuai untuk IoT berskala besar karena:
1. **Hemat sumber daya perangkat.** Perangkat cukup mengirim saat ada data,
   tanpa melayani permintaan berulang dari banyak klien.
2. **Satu data, banyak pemakai.** Dashboard, pencatat data, dan sistem
   peringatan dapat berlangganan topic yang sama tanpa menambah beban perangkat.
3. **Mudah diperluas.** Menambah perangkat atau pemakai baru tidak menuntut
   perubahan pada pihak lain.
4. **Tahan koneksi terputus.** Pengirim dan penerima tidak harus aktif
   bersamaan.

### Esai 2 - Tingkat QoS

- **QoS 0 (at most once):** kirim lalu lupakan, tanpa balasan. Paling ringan
  dan cepat, tetapi pesan dapat hilang.
- **QoS 1 (at least once):** pesan dikirim ulang sampai ada balasan PUBACK.
  Pesan dijamin sampai, tetapi penerima dapat menerimanya lebih dari sekali.
- **QoS 2 (exactly once):** jabat tangan empat tahap (PUBLISH, PUBREC, PUBREL,
  PUBCOMP). Menjamin pesan diterima tepat satu kali, tetapi paling berat dan
  paling lambat.

**Untuk data suhu berkala: QoS 0.** Data dikirim berulang setiap beberapa
detik, sehingga kehilangan satu pesan segera tertutup oleh pengiriman
berikutnya. Memakai QoS lebih tinggi hanya menambah beban tanpa manfaat berarti.

**Untuk pesan peringatan: QoS 1.** Peringatan suhu berlebih tidak boleh hilang
karena tidak akan diulang secara berkala. Pesan ganda masih dapat ditoleransi
(petugas menerima notifikasi dua kali), sehingga QoS 2 yang lebih berat tidak
diperlukan.

### Esai 3 - Rancangan struktur topic

Contoh struktur, disusun dari umum ke khusus:

```
kampus/gedungA/ruang101/suhu
kampus/gedungA/ruang101/kelembaban
kampus/gedungB/ruang205/suhu
```

Tingkatannya: `kampus` (lokasi umum) / `gedung` / `ruang` / `besaran`.

Alasan: penambahan gedung atau ruang baru cukup mengikuti pola yang sama tanpa
mengubah rancangan. Menempatkan besaran di tingkat paling akhir memudahkan
pemilihan data tertentu.

**Berlangganan seluruh data satu gedung:**
```
kampus/gedungA/#
```
Tanda `#` mencakup semua tingkat di bawahnya, sehingga satu langganan menangkap
seluruh ruang dan seluruh besaran pada gedung A.

Bila hanya ingin suhu dari semua ruang di gedung A:
```
kampus/gedungA/+/suhu
```
Tanda `+` mewakili tepat satu tingkat, yaitu nama ruang.

Jawaban lain dapat diterima sepanjang tingkatannya konsisten, disusun dari umum
ke khusus, dan penggunaan wildcard-nya tepat.
