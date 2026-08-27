# Kunci Jawaban Self-Assessment - Bab 1

> Berkas ini disediakan pada repositori (bukan dicetak lengkap di buku) agar mahasiswa
> berlatih mandiri terlebih dahulu.

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | a | 7 | c |
| 2 | c | 8 | d |
| 3 | a | 9 | b |
| 4 | d | 10 | c |
| 5 | a | 11 | b |
| 6 | b | 12 | b |

## B. Jawaban Esai (Model)

Jawaban berikut adalah acuan. Jawaban mahasiswa dinilai atas ketepatan konsep (50%),
kelengkapan uraian dan contoh (30%), serta kejelasan penyajian (20%).

### Esai 1 - Perbedaan arsitektur tiga lapis dan lima lapis

Arsitektur tiga lapis adalah model dasar yang terdiri atas lapisan persepsi, jaringan,
dan aplikasi. Arsitektur lima lapis memperinci model tersebut menjadi lapisan persepsi,
transport, pemrosesan, aplikasi, dan bisnis. Perbedaan utamanya, arsitektur lima lapis
memisahkan fungsi pengangkutan data (transport) dari fungsi pengolahan data (pemrosesan),
serta menambahkan lapisan bisnis.

Fungsi lapisan tambahan pada arsitektur lima lapis:
- **Transport:** mengirimkan data dari perangkat melalui jaringan (WiFi, seluler, dan lain-lain).
- **Pemrosesan:** menyimpan, menganalisis, dan mengolah data, baik di edge maupun cloud.
- **Bisnis:** mengelola keseluruhan sistem, model bisnis, laporan, dan keputusan strategis.

Arsitektur lima lapis lebih sesuai untuk sistem berskala besar dan kompleks, sedangkan
tiga lapis memadai untuk sistem sederhana.

### Esai 2 - Peran edge, fog, dan cloud serta contoh keunggulan edge

- **Edge computing:** pemrosesan sedekat mungkin dengan sumber data (mis. pada mikrokontroler).
  Latensi sangat rendah, tetapi sumber dayanya terbatas.
- **Fog computing:** pemrosesan pada lapisan antara, mis. gateway lokal yang melayani beberapa
  perangkat sebelum data diteruskan ke cloud.
- **Cloud computing:** pemrosesan dan penyimpanan pada server awan dengan sumber daya besar,
  cocok untuk analitik berat dan penyimpanan jangka panjang.

Contoh kondisi edge lebih baik daripada cloud: sistem yang harus bereaksi cepat dan tetap
berfungsi meski koneksi internet terputus, misalnya mematikan mesin secara otomatis ketika
sensor mendeteksi kondisi berbahaya, atau menyalakan pompa irigasi saat kelembaban melewati
ambang. Memproses keputusan di edge menghindari keterlambatan (latensi) akibat mengirim data
ke cloud dan menunggu balasan, sekaligus mengurangi penggunaan bandwidth.

### Esai 3 - Pemetaan sistem IoT dan aliran datanya

Jawaban bergantung pada sistem yang dipilih. Contoh untuk rumah pintar:
- **Ekosistem:** perangkat (sensor gerak & suhu, relai, ESP32), konektivitas (WiFi),
  pemrosesan (edge di ESP32 + cloud), aplikasi (aplikasi ponsel), pengguna (penghuni).
- **Aliran data:** sensor mendeteksi kehadiran dan suhu; ESP32 membaca dan menerapkan aturan;
  perintah dikirim ke relai untuk menyalakan lampu/AC (aksi di edge); data dikirim via WiFi ke
  cloud untuk disimpan; penghuni memantau dan mengendalikan melalui aplikasi ponsel.

Jawaban dinilai berdasarkan ketepatan pemetaan komponen dan kelengkapan uraian aliran data
dari sensor hingga menghasilkan aksi. (Lihat `latihan/contoh-pengerjaan.md`.)
