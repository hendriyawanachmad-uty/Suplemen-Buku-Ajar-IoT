# Broker MQTT Publik untuk Latihan

Beberapa broker publik dapat dipakai gratis untuk belajar. Alamat dan
ketersediaannya dapat berubah sewaktu-waktu, jadi periksa kembali bila gagal
tersambung.

| Broker | Alamat | Porta (tanpa TLS) |
|--------|--------|-------------------|
| EMQX | broker.emqx.io | 1883 |
| HiveMQ | broker.hivemq.com | 1883 |
| Mosquitto | test.mosquitto.org | 1883 |

## PERINGATAN KEAMANAN

Broker publik **terbuka untuk siapa saja**. Konsekuensinya:

1. Semua orang dapat berlangganan topic Anda dan membaca data yang Anda kirim.
2. Semua orang dapat menerbitkan pesan ke topic Anda, termasuk perintah palsu.
3. Data tidak dijamin tersimpan dan layanan dapat berhenti kapan saja.

Karena itu:
- Gunakan **hanya untuk latihan**, tidak pernah untuk data nyata atau kendali
  perangkat sungguhan.
- Jangan mengirim data pribadi, kredensial, atau lokasi yang sebenarnya.
- Pakai **awalan topic yang unik**, misalnya `kelasA-nim123/...`, agar tidak
  bentrok dengan pengguna lain di seluruh dunia yang memakai broker sama.

Untuk sistem sungguhan, pakailah broker sendiri atau layanan berbayar dengan
autentikasi dan TLS. Aspek keamanan ini dibahas pada bab keamanan.
