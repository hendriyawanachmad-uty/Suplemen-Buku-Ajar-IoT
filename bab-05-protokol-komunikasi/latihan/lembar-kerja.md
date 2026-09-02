# Lembar Kerja Praktik Bab 5 - MQTT

**Nama / NIM:** [ ... ]  **Tanggal:** [ ... ]

## 1. Tujuan
Mengirim data sensor dari ESP32 ke broker MQTT dan memverifikasinya melalui
aplikasi klien MQTT.

## 2. Rancangan topic
| Butir | Isi |
|-------|-----|
| Broker yang dipakai | |
| Awalan unik Anda | |
| Topic suhu | |
| Topic kelembaban | |
| Topic perintah | |

[ Jelaskan alasan penyusunan tingkatan topic Anda. ]

## 3. Hasil pengiriman
[ Lampirkan tangkapan layar aplikasi klien MQTT yang menampilkan data masuk. ]

| Waktu | Suhu (C) | Kelembaban (%) |
|-------|----------|----------------|
|       |          |                |
|       |          |                |

## 4. Percobaan tanda pengganti
| Pola langganan | Topic yang tertangkap | Sesuai dugaan? |
|----------------|----------------------|----------------|
| topic penuh (tanpa wildcard) | | |
| menggunakan `+` | | |
| menggunakan `#` | | |

## 5. Percobaan QoS
Ubah tingkat QoS pada pemanggilan `publish`, lalu amati.

| QoS | Terlihat berbeda? | Catatan |
|-----|-------------------|---------|
| 0 | | |
| 1 | | |

[ Mengapa perbedaannya sulit terlihat pada jaringan yang stabil? ]

## 6. Percobaan menerima perintah
Unggah `mqtt_subscribe.ino`, lalu kirim pesan NYALA dan MATI dari aplikasi klien.

Hasil: [ ... ]

## 7. Percobaan kegagalan (penting)
Hapus sementara baris `mqtt.loop()` dari program, lalu jalankan beberapa menit.

[ Apa yang terjadi? Mengapa gejalanya membingungkan? ]

## 8. Kesimpulan
[ ... ]
