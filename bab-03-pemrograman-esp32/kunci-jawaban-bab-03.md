# Kunci Jawaban Self-Assessment - Bab 3

## A. Pilihan Ganda

| No | Kunci | No | Kunci |
|----|-------|----|-------|
| 1 | b | 7 | b |
| 2 | c | 8 | b |
| 3 | c | 9 | b |
| 4 | b | 10 | b |
| 5 | c | 11 | b |
| 6 | c | 12 | a |

## B. Jawaban Esai (Model)

Dinilai atas ketepatan konsep (50%), kelengkapan uraian dan contoh (30%),
serta kejelasan penyajian (20%).

### Esai 1 - Peran setup() dan loop()

`setup()` dijalankan **satu kali** ketika perangkat menyala atau direset, dan
berisi persiapan yang cukup dilakukan sekali: membuka komunikasi serial,
menetapkan mode pin, serta menginisialisasi sensor. `loop()` dijalankan
**berulang tanpa henti** selama perangkat menyala, dan berisi pekerjaan
rutin: membaca sensor, mengambil keputusan, serta mengendalikan aktuator.

Contoh perintah yang keliru bila ditempatkan di dalam `loop()`:
`Serial.begin(115200)`, `pinMode(...)`, atau `dht.begin()`. Perintah tersebut
akan dijalankan ribuan kali per detik tanpa manfaat, memboroskan waktu
pemrosesan dan berpotensi menimbulkan perilaku tak terduga.

### Esai 2 - Histeresis

Histeresis adalah teknik kendali yang menggunakan **dua nilai ambang berbeda**:
satu untuk menyalakan aktuator (ambang atas) dan satu untuk mematikannya
(ambang bawah). Di antara keduanya terdapat pita histeresis, yaitu daerah
ketika status aktuator sengaja dipertahankan apa adanya.

Histeresis diperlukan karena pembacaan sensor selalu bergoyang sedikit akibat
derau. Dengan satu ambang tunggal, nilai yang naik-turun di sekitar ambang
membuat aktuator menyala dan mati berulang kali dalam waktu singkat. Pada
relai mekanis hal ini menimbulkan bunyi mengganggu, memperpendek umur
komponen, dan pada motor dapat menyebabkan lonjakan arus berulang.

- **Pita terlalu sempit:** perlindungan terhadap derau menjadi kecil, sehingga
  aktuator masih mungkin berkedip. Manfaat histeresis nyaris hilang.
- **Pita terlalu lebar:** sistem menjadi lamban menanggapi perubahan nyata.
  Contoh: kipas baru mati setelah ruangan menjadi jauh lebih dingin daripada
  yang dikehendaki, sehingga terasa tidak nyaman dan boros energi.

Nilai yang tepat ditentukan dengan mempertimbangkan besar derau sensor dan
toleransi kenyamanan; umumnya ditetapkan melalui pengamatan langsung.

### Esai 3 - Kelemahan delay() dan solusi millis()

`delay()` menghentikan **seluruh** eksekusi program selama waktu yang
ditentukan. Selama jeda tersebut program tidak dapat melakukan apa pun:
tombol tidak terbaca, permintaan jaringan tidak dilayani, dan aktuator tidak
dapat dihentikan mendadak. Pada sistem yang harus melayani banyak tugas,
sistem terasa lamban dan bahkan dapat kehilangan peristiwa penting.

`millis()` mengembalikan jumlah milidetik sejak perangkat menyala. Alih-alih
menghentikan program, kita **mencatat waktu** terakhir sebuah tugas dijalankan,
lalu pada setiap putaran `loop()` memeriksa apakah selang waktunya sudah
terpenuhi:

```
if (millis() - terakhirBaca >= SELANG) {
  terakhirBaca = millis();
  bacaSensor();
}
```

Dengan cara ini `loop()` tetap berputar cepat, sehingga tugas lain seperti
pembacaan tombol tetap dilayani di antara pembacaan sensor. Bentuk pengurangan
`millis() - terakhirBaca` juga tetap benar meskipun nilai `millis()` kembali ke
nol setelah kira-kira 49 hari, sepanjang variabelnya bertipe `unsigned long`.
