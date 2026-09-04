# Kunci Jawaban Self-Assessment - Bab 8

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | c | 7 | d |
| 2 | a | 8 | c |
| 3 | d | 9 | b |
| 4 | b | 10 | d |
| 5 | d | 11 | a |
| 6 | b | 12 | c |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Edge, fog, dan cloud

| Aspek | Edge | Fog | Cloud |
|-------|------|-----|-------|
| Lokasi | Di perangkat (ESP32) | Gateway lokal | Pusat data |
| Latensi | Milidetik | Puluhan milidetik | Ratusan milidetik atau lebih |
| Daya komputasi | Kecil | Menengah | Sangat besar |
| Privasi | Paling terjaga; data tidak keluar perangkat | Data tetap di jaringan lokal | Data melintasi internet |

Contoh kebutuhan yang paling sesuai:
- **Edge:** mematikan mesin ketika getaran berbahaya. Harus seketika dan tetap
  bekerja meskipun jaringan terputus.
- **Fog:** menggabungkan data dari puluhan sensor dalam satu gedung sebelum
  diteruskan, sehingga lalu lintas ke internet berkurang.
- **Cloud:** menyimpan riwayat setahun dan menyusun laporan tren bulanan, yang
  menuntut penyimpanan besar dan komputasi berat.

Ketiganya saling melengkapi, bukan saling menggantikan.

### Esai 2 - Tiga bentuk pemrosesan di edge

1. **Penyaringan:** membuang pembacaan yang tidak sah, misalnya nilai gagal
   baca (NaN) atau nilai yang mustahil secara fisik.
2. **Agregasi:** meringkas beberapa pembacaan menjadi satu nilai, misalnya
   rata-rata sepuluh cuplikan. Selain mengurangi jumlah data, cara ini juga
   menekan derau.
3. **Penentuan ambang:** mengirim hanya ketika perubahan nilainya cukup
   berarti, sehingga data yang sekadar mengulang nilai sama tidak dikirim.

Manfaatnya terhadap volume data sangat besar. Sensor yang membaca tiap detik
menghasilkan lebih dari 80.000 paket per hari bila semuanya dikirim; dengan
ketiga cara di atas jumlahnya dapat turun menjadi sekitar 900 paket, yaitu
penghematan lebih dari 98 persen. Dampak lanjutannya: baterai lebih awet,
biaya data turun, dan cloud tidak dibanjiri data berulang.

**Risiko penyaringan yang terlalu agresif:** data yang telanjur dibuang tidak
dapat dipulihkan. Detail yang kini tampak tidak penting bisa saja dibutuhkan
saat menelusuri masalah di kemudian hari, misalnya untuk mengetahui apa yang
terjadi tepat sebelum sebuah kerusakan. Praktik yang lazim adalah mengirim
ringkasan secara berkala, sekaligus tetap mengirim data rinci ketika terjadi
kejadian penting.

### Esai 3 - Deteksi anomali berbasis simpangan baku

Cara kerjanya:
1. Ambil sejumlah nilai terakhir sebagai jendela pengamatan.
2. Hitung rata-rata dari jendela tersebut.
3. Hitung simpangan baku, yaitu akar dari rata-rata kuadrat selisih setiap
   nilai terhadap rata-rata.
4. Bandingkan jarak nilai baru terhadap rata-rata dengan k kali simpangan baku
   (k umumnya 2 atau 3).
5. Bila jaraknya melebihi batas tersebut, nilai ditandai sebagai anomali.

Pendekatan ini tidak menyatakan nilai tersebut pasti salah, melainkan bahwa
nilai itu menyimpang dari kebiasaan sehingga layak diperiksa.

**Alasan nilai anomali tidak dimasukkan kembali ke jendela:** bila dimasukkan,
nilai menyimpang itu akan ikut menggeser rata-rata dan memperbesar simpangan
baku. Akibatnya batas normal ikut melebar, dan bila kejanggalan terus berulang,
sistem lambat laun akan menganggap keadaan tidak normal sebagai normal sehingga
berhenti memberi peringatan. Dengan tidak memasukkannya, jendela tetap mewakili
keadaan normal yang sesungguhnya.

Perlu ditambahkan bahwa jendela dihitung dari data terakhir, bukan seluruh
riwayat, agar sistem tetap dapat menyesuaikan diri ketika kondisi normal
memang berubah secara perlahan.
