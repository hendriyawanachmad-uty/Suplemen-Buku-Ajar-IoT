# Panduan Memperoleh dan Menyematkan Sertifikat

Agar ESP32 dapat memeriksa keaslian broker, sertifikat otoritas penerbit
(root CA) milik broker harus disematkan ke dalam program.

## 1. Memperoleh sertifikat

### Cara A: melalui peramban
1. Buka alamat broker pada peramban (bila menyediakan antarmuka web).
2. Klik ikon gembok pada bilah alamat.
3. Pilih rincian sertifikat, lalu telusuri sampai sertifikat paling atas
   (root CA).
4. Ekspor dalam format PEM (berkas berisi teks `-----BEGIN CERTIFICATE-----`).

### Cara B: melalui baris perintah
```
openssl s_client -showcerts -connect broker.emqx.io:8883 </dev/null
```
Salin blok sertifikat **paling akhir** pada keluaran, yaitu root CA-nya.

### Cara C: dari dokumentasi broker
Banyak penyedia mencantumkan tautan unduhan sertifikatnya. Cara ini paling
dianjurkan karena paling kecil kemungkinan salah salin.

## 2. Menyematkan ke program

Tempelkan isi sertifikat di antara tanda kutip mentah:

```cpp
const char* CA_CERT = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDrzCCApegAwIBAgIQ...
...
-----END CERTIFICATE-----
)EOF";
```

Perhatikan:
- Sertakan **seluruh** baris, termasuk baris BEGIN dan END.
- Jangan menambah atau menghapus spasi maupun baris kosong.
- Satu kesalahan karakter membuat koneksi gagal tanpa pesan yang jelas.

## 3. Waktu perangkat harus benar

Masa berlaku sertifikat diperiksa terhadap waktu saat ini. ESP32 tidak
memiliki jam yang bertahan setelah dimatikan, sehingga waktunya harus
diselaraskan lebih dahulu melalui NTP:

```cpp
configTime(0, 0, "pool.ntp.org", "time.nist.gov");
while (time(nullptr) < 100000) delay(300);
```

**Ini penyebab kegagalan yang paling sering dan paling membingungkan.**
Sertifikat sudah benar, jaringan sudah tersambung, tetapi koneksi TLS tetap
ditolak karena perangkat mengira sekarang tahun 1970.

## 4. Menelusuri kegagalan

| Gejala | Kemungkinan penyebab |
|--------|----------------------|
| Gagal terus sejak awal | Sertifikat salah salin atau bukan root CA-nya |
| Gagal setelah sebelumnya berhasil | Sertifikat broker kedaluwarsa atau diganti |
| Gagal hanya setelah perangkat dimatikan | Waktu belum diselaraskan melalui NTP |
| Gagal pada porta 8883 saja | Broker tidak mendukung TLS pada porta itu |

## 5. Tentang setInsecure()

Banyak contoh di internet memakai:

```cpp
aman.setInsecure();   // JANGAN untuk sistem sungguhan
```

Baris ini melewati pemeriksaan sertifikat. Pesan tetap terenkripsi, tetapi
perangkat **tidak lagi dapat membedakan** broker yang sah dari penyusup yang
menyamar. Untuk latihan di kelas hal ini masih dapat diterima agar tidak
tersendat, tetapi harus disadari sebagai penurunan tingkat keamanan, bukan
sebagai cara yang benar.
