# Kunci Jawaban Self-Assessment - Bab 4

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | c | 7 | b |
| 2 | b | 8 | c |
| 3 | c | 9 | b |
| 4 | b | 10 | c |
| 5 | c | 11 | b |
| 6 | b | 12 | b |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Pertukaran jangkauan, laju data, dan daya

Ketiga aspek ini saling tarik-menarik dan tidak dapat dimaksimalkan bersamaan.
Mengirim data dalam jumlah besar menuntut lebar pita dan daya pancar yang besar,
sehingga baterai cepat habis. Sebaliknya, menjangkau jarak jauh dengan daya kecil
hanya mungkin bila data yang dikirim sedikit dan dikirim jarang.

Dua contoh yang berlawanan posisinya:
- **WiFi:** laju data tinggi (mampu mengalirkan video), tetapi jangkauannya hanya
  puluhan meter dan konsumsi dayanya besar. Cocok untuk perangkat berlistrik tetap.
- **LoRaWAN:** jangkauan beberapa kilometer dengan daya sangat rendah sehingga
  baterai bertahan lama, tetapi laju datanya sangat kecil sehingga hanya cukup
  untuk beberapa byte tiap beberapa menit.

Kesimpulannya, pemilihan teknologi bukan mencari yang "terbaik", melainkan yang
paling sesuai dengan profil kebutuhan.

### Esai 2 - Topologi bintang vs jala

**Topologi bintang:** semua node berkomunikasi langsung dengan satu titik pusat.
- Kelebihan: sederhana, mudah dikelola, node tidak perlu meneruskan data orang lain
  sehingga dapat tidur lebih lama.
- Kekurangan: jangkauan dibatasi jarak node terjauh ke pusat; bila pusat mati,
  seluruh jaringan berhenti.
- Contoh: WiFi, LoRaWAN, jaringan seluler.

**Topologi jala (mesh):** node dapat meneruskan data node lain.
- Kelebihan: jangkauan efektif meluas karena data dapat melompat antarnode;
  lebih tahan gangguan karena tersedia jalur alternatif.
- Kekurangan: pengelolaan lebih rumit; node perantara harus lebih sering aktif
  sehingga lebih boros daya.
- Contoh: Zigbee.

### Esai 3 - Rancangan pemantauan kualitas udara dalam gedung

**Pilihan: WiFi.**

Alasan berdasarkan kriteria:
- **Jangkauan:** seluruh titik berada dalam satu gedung, sehingga jangkauan
  puluhan meter per titik akses sudah memadai; tidak perlu teknologi LPWAN.
- **Sumber daya:** gedung berlistrik, sehingga kelemahan utama WiFi berupa
  konsumsi daya besar tidak menjadi masalah.
- **Laju data:** WiFi lebih dari cukup, dan memberi ruang bila kelak ingin
  menambah pembacaan yang lebih sering atau data tambahan.
- **Infrastruktur:** jaringan WiFi kampus umumnya sudah tersedia, sehingga tidak
  perlu memasang gateway khusus seperti pada LoRaWAN atau Zigbee.
- **Biaya:** tidak ada biaya berlangganan per perangkat seperti pada seluler,
  dan ESP32 sudah memiliki WiFi bawaan sehingga tidak perlu modul tambahan.

Alternatif Zigbee dapat dipertimbangkan bila jumlah titik jauh lebih banyak dan
sebagian bertenaga baterai, tetapi memerlukan hub tambahan. Jawaban lain dapat
diterima sepanjang alasannya konsisten dengan kriteria pemilihan.
