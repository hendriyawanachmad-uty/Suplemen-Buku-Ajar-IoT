# Kunci Jawaban Self-Assessment - Bab 9

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | b | 7 | c |
| 2 | d | 8 | b |
| 3 | b | 9 | d |
| 4 | c | 10 | b |
| 5 | a | 11 | c |
| 6 | d | 12 | a |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Permukaan serangan dan dua prinsip

**Permukaan serangan pada empat lapisan:**

1. **Perangkat:** kata sandi bawaan, firmware yang tidak pernah diperbarui,
   porta debug yang terbuka, akses fisik ke papan, kredensial yang ditulis
   langsung di kode.
2. **Jaringan:** data terkirim polos sehingga dapat disadap, penyusup yang
   menyamar di tengah jalur, jaringan WiFi tanpa kata sandi.
3. **Cloud/Broker:** broker tanpa autentikasi, token yang bocor, hak akses
   yang terlalu luas, basis data yang terbuka.
4. **Aplikasi:** masukan yang tidak diperiksa, sesi yang tidak kedaluwarsa,
   data pribadi yang terekspos, kunci API yang tertanam di aplikasi.

**Prinsip rantai terlemah:** keamanan sistem ditentukan oleh bagiannya yang
paling lemah, bukan yang paling kuat. Contoh: memasang TLS dengan enkripsi
terkuat menjadi sia-sia bila perangkatnya masih memakai kata sandi bawaan
pabrik, sebab penyerang cukup masuk lewat kata sandi itu tanpa perlu
menembus enkripsinya.

**Prinsip pertahanan berlapis:** karena tidak ada perlindungan yang sempurna,
sistem dirancang agar tetap terlindungi meski satu lapisan tertembus. Contoh:
meskipun kredensial sebuah perangkat bocor, pembatasan hak akses membuat
perangkat itu hanya dapat menulis pada topic-nya sendiri, sehingga kerusakannya
terbatas.

### Esai 2 - Autentikasi, otorisasi, dan hak akses seperlunya

**Autentikasi** menjawab pertanyaan "siapa Anda", yaitu memastikan perangkat
memang benar perangkat yang diakuinya. Sarananya berupa token, kunci API,
sertifikat, atau pasangan nama pengguna dan kata sandi.

**Otorisasi** menjawab pertanyaan "apa yang boleh Anda lakukan", yaitu
menentukan tindakan yang diizinkan setelah identitas dikenali. Contohnya
membatasi sebuah perangkat agar hanya boleh menerbitkan pada topic miliknya.

Keduanya berbeda dan sama-sama diperlukan. Autentikasi yang lemah membuat
pihak asing dapat menyamar. Otorisasi yang longgar membuat perangkat yang
sah, atau yang berhasil disamarkan, dapat berbuat jauh lebih banyak daripada
seharusnya.

**Prinsip hak akses seperlunya** menyatakan setiap perangkat hanya diberi
kewenangan sebatas kebutuhan tugasnya. Perannya dalam membatasi kerusakan:

- Bila tiap perangkat memiliki kredensial sendiri, kebocoran satu kredensial
  hanya memengaruhi satu perangkat, bukan seluruh sistem.
- Bila sensor hanya berwenang menulis pada topic-nya, penyerang yang menguasai
  kredensial sensor tidak dapat mengirim perintah ke aktuator.
- Kredensial yang terpisah dapat dibatalkan satu per satu tanpa mengganggu
  perangkat lain.

Sebaliknya, satu token yang dipakai bersama oleh seluruh perangkat dengan hak
baca-tulis penuh berarti satu kebocoran membuka seluruh sistem.

### Esai 3 - TLS dan pembaruan OTA

**Dua fungsi TLS:**
1. **Menyandikan isi pesan.** Data yang melintas jaringan berubah menjadi
   rangkaian huruf acak, sehingga penyadap tidak dapat membaca isinya,
   termasuk token yang menyertainya.
2. **Memeriksa keaslian lawan bicara.** Melalui pemeriksaan sertifikat,
   perangkat memastikan sedang berhubungan dengan broker yang benar.

**Akibat melewati pemeriksaan sertifikat** (misalnya memakai `setInsecure()`):
fungsi pertama tetap berjalan, pesan masih terenkripsi. Namun fungsi kedua
hilang sepenuhnya. Perangkat menjadi tidak dapat membedakan broker yang sah
dari penyusup yang menyamar, sehingga penyusup dapat menempatkan diri di
tengah jalur, menerima data perangkat, lalu meneruskannya seolah tidak terjadi
apa-apa. Enkripsinya tetap ada, tetapi terjadi dengan pihak yang salah.

**Syarat pembaruan OTA yang aman:**
1. **Pemeriksaan tanda tangan.** Perangkat hanya memasang firmware yang
   ditandatangani dengan kunci pengembang dan tanda tangannya terbukti sah.
   Tanpa ini, penyerang yang berhasil menyisipkan berkas palsu dapat membuat
   perangkat memasang firmware buatannya, sehingga perangkat sepenuhnya
   dikuasai dan sulit dipulihkan dari jarak jauh.
2. **Penyediaan dua partisi.** Firmware baru ditulis ke partisi cadangan.
   Bila gagal menyala, perangkat kembali ke partisi lama yang masih berfungsi,
   sehingga kegagalan pembaruan tidak membuat perangkat mati total.
3. Pengunduhan sebaiknya juga melalui saluran terenkripsi agar berkas tidak
   dapat diubah di tengah jalan.
