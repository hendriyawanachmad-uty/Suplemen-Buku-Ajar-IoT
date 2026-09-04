# Kunci Jawaban Self-Assessment - Bab 6

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | c | 7 | c |
| 2 | a | 8 | a |
| 3 | b | 9 | d |
| 4 | d | 10 | b |
| 5 | c | 11 | d |
| 6 | a | 12 | c |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Layanan platform cloud IoT

Layanan pokok yang disediakan:
1. **Konektivitas perangkat** melalui MQTT atau HTTP, termasuk penanganan
   banyak perangkat sekaligus.
2. **Autentikasi** berupa kunci API atau token, sehingga hanya perangkat yang
   sah dapat mengirim data.
3. **Penyimpanan data time-series** beserta agregasinya.
4. **Mesin aturan** yang memicu tindakan otomatis, misalnya notifikasi.
5. **Dashboard** sebagai antarmuka visual bagi pengguna.

Layanan ini umumnya tidak dibangun sendiri untuk proyek kecil karena:
- Usaha membangunnya besar dan tidak sebanding dengan manfaatnya; yang dibangun
  bukan hanya server, melainkan juga keamanan, ketersediaan, cadangan data,
  dan antarmuka.
- Diperlukan pemeliharaan terus-menerus, termasuk pembaruan keamanan.
- Sistem harus tersedia sepanjang waktu, yang menuntut biaya dan pengawasan.
- Fokus proyek pembelajaran sebaiknya pada perangkat dan pemanfaatan data,
  bukan pada infrastruktur.

### Esai 2 - Provisioning dan pengelolaan kredensial

**Provisioning** adalah proses mendaftarkan perangkat pada platform sehingga
dikenali. Platform menerbitkan kredensial unik berupa kunci API atau token,
yang disertakan perangkat pada setiap pengiriman.

Pengelolaan kredensial bersifat kritis karena:
- Kredensial adalah satu-satunya bukti identitas perangkat. Siapa pun yang
  memilikinya dapat mengirim data **atas nama** perangkat tersebut.
- Data palsu membuat grafik menjadi kacau dan keputusan otomatis salah,
  misalnya notifikasi palsu atau aktuator menyala tanpa alasan.
- Pada sebagian platform, kredensial juga memungkinkan pengiriman perintah
  (downlink), sehingga kebocoran berarti kendali perangkat dapat diambil alih.

Langkah yang benar bila token terlanjur tersebar:
1. **Batalkan (revoke) token tersebut segera** pada platform.
2. **Terbitkan token baru** dan perbarui `secrets.h` pada perangkat.
3. Periksa riwayat data untuk melihat apakah ada kiriman mencurigakan.

Menghapus berkas atau riwayat unggahan **tidak cukup**, sebab token yang sudah
tersebar dapat terlanjur disalin pihak lain.

### Esai 3 - Rancangan dashboard tiga gudang

Contoh rancangan:

| Widget | Data | Alasan |
|--------|------|--------|
| Grafik garis (3 seri) | Suhu ketiga gudang | Menampilkan tren dan memudahkan perbandingan antar gudang |
| Gauge (3 buah) | Suhu terkini tiap gudang | Menjawab kondisi saat ini terhadap rentang aman |
| Indikator status | Perangkat daring/luring | Membedakan "suhu aman" dengan "data tidak masuk" |
| Indikator pendingin | Status aktuator | Mengetahui apakah pendingin sedang bekerja |

Alasan pemilihan mengikuti pertanyaan yang dijawab: tren memakai grafik,
kondisi sesaat memakai gauge, dan status memakai indikator.

**Aturan notifikasi:**
- Kondisi: suhu salah satu gudang melebihi batas atas (misalnya 8 derajat).
- Syarat waktu bertahan: bertahan selama 10 menit berturut-turut.
- Tindakan: mengirim pesan kepada petugas jaga.
- Aturan tambahan: bila perangkat tidak mengirim data selama 15 menit, kirim
  peringatan terpisah, sebab data yang berhenti juga merupakan masalah.

Syarat waktu bertahan diperlukan agar satu pembacaan menyimpang, misalnya saat
pintu gudang dibuka sebentar, tidak langsung memicu peringatan.
