# Kunci Jawaban Self-Assessment - Bab 10

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | b | 5 | c |
| 2 | c | 6 | d |
| 3 | d | 7 | c |
| 4 | a | 8 | b |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Perbandingan dua domain

Jawaban bergantung pada domain yang dipilih. Contoh untuk **smart
agriculture** dibanding **smart industry**:

| Aspek | Smart Agriculture | Smart Industry |
|-------|-------------------|----------------|
| Jarak | Kilometer, tersebar di lahan | Puluhan meter, dalam satu pabrik |
| Sumber daya | Tidak ada listrik; baterai | Listrik tersedia |
| Waktu tanggap | Menit hingga jam; kelembaban tanah berubah lambat | Milidetik hingga detik; getaran berbahaya harus segera dihentikan |
| Kepekaan data | Rendah | Sedang; menyangkut keselamatan dan rahasia produksi |

**Pengaruh terhadap pilihan teknologi:**

- **Konektivitas.** Agriculture menuntut jangkauan kilometer dengan daya
  rendah, sehingga LoRaWAN sesuai. Industry cukup memakai jaringan lokal
  berkecepatan tinggi karena jaraknya pendek.
- **Sumber daya.** Agriculture memerlukan mode tidur dalam dan pengiriman
  jarang agar baterai awet. Industry tidak dibatasi daya.
- **Letak pemrosesan.** Industry harus memproses di edge karena keputusan
  tidak boleh menunggu perjalanan data ke cloud. Agriculture boleh
  memproses di cloud karena tidak ada tuntutan seketika.
- **Selang pengiriman.** Agriculture cukup beberapa menit sekali; Industry
  memerlukan pembacaan yang jauh lebih rapat, sehingga penyaringan dan
  agregasi di edge menjadi penting agar volume data terkendali.

Kesimpulannya, teknologi dasarnya sama, tetapi bobot pertimbangannya berbeda
sehingga menghasilkan rancangan yang sangat berlainan.

### Esai 2 - Mengapa berangkat dari masalah

Merancang dari masalah memastikan sistem yang dibangun benar-benar
menyelesaikan sesuatu. Urutan yang benar adalah: rumuskan masalah, tentukan
informasi yang dibutuhkan, kenali batasan, lalu pilih teknologi yang
memenuhi batasan itu.

Bila urutannya dibalik, yaitu memilih teknologi lebih dahulu lalu mencari
masalah yang cocok, akibat yang timbul:

1. **Sistem berjalan tetapi tidak berguna.** Alat menyala, data masuk,
   dashboard tampil, tetapi tidak ada keputusan atau tindakan yang berubah
   karenanya.
2. **Teknologi tidak sesuai batasan.** Contoh: memilih WiFi karena sudah
   dikuasai, padahal sensor dipasang di lahan tanpa listrik sejauh dua
   kilometer. Sistem gagal bukan karena salah program, melainkan karena
   pilihan awalnya keliru.
3. **Keberhasilan tidak dapat dibuktikan.** Tanpa masalah yang jelas, tidak
   ada tolok ukur, sehingga penilaian jatuh pada "alatnya menyala".
4. **Ruang lingkup melebar.** Karena tidak ada batas yang ditetapkan
   masalah, fitur terus ditambahkan sampai waktu habis.

Contoh nyata: proposal yang dimulai dengan "kami ingin memakai sensor gas dan
ESP32" menghasilkan sistem yang mengukur udara tetapi tidak pernah menjawab
berapa titik yang diperlukan, tindakan apa yang diambil, dan bagaimana
membuktikan ruangan menjadi lebih nyaman.

## C. Rubrik Penilaian Proposal

Total 100 poin.

| Aspek | Bobot | Sangat baik | Cukup | Kurang |
|-------|-------|-------------|-------|--------|
| Rumusan masalah | 15 | Masalah nyata, tanpa menyebut teknologi, pihak terdampak jelas | Masalah jelas tetapi masih menyinggung teknologi | Berangkat dari teknologi |
| Ruang lingkup | 10 | Batas jelas, ada daftar yang tidak dikerjakan, masuk akal | Batas ada tetapi longgar | Tidak ada batas |
| Analisis kebutuhan | 15 | Tiap besaran punya tindakan; selang kirim beralasan | Sebagian beralasan | Sekadar daftar sensor |
| Batasan rancangan | 15 | Keenam pertanyaan terjawab konkret | Sebagian terjawab | Tidak dibahas |
| Rancangan solusi | 20 | Arsitektur lengkap; tiap pilihan beralasan merujuk batasan | Arsitektur ada, alasan sebagian | Daftar komponen tanpa alasan |
| Ukuran keberhasilan | 15 | Terukur, terikat waktu, cara pembuktian jelas | Terukur tetapi cara pembuktian kabur | Tidak terukur |
| Kelayakan dan risiko | 10 | Rencana mingguan masuk akal, risiko dikenali | Rencana ada, risiko belum | Tidak ada rencana |

**Catatan bagi pengampu.** Aspek yang paling sering lemah adalah *ukuran
keberhasilan*. Bila proposal hanya menulis "sistem berjalan dengan baik",
kembalikan untuk diperbaiki sebelum pekerjaan dimulai, sebab tanpa tolok ukur
penilaian akhir menjadi tidak berdasar.
