# Lembar Uji Proyek Akhir

**Kelompok:** [ ... ]  **Judul proyek:** [ ... ]  **Tanggal uji:** [ ... ]

---

## Lapis 1 - Pengujian bagian
Apakah tiap bagian bekerja sendiri-sendiri?

| Bagian | Cara menguji | Hasil | Bukti |
|--------|--------------|-------|-------|
| Sensor | | lulus / gagal | |
| Aktuator | | lulus / gagal | |
| Koneksi jaringan | | lulus / gagal | |
| Pengiriman data | | lulus / gagal | |

---

## Lapis 2 - Pengujian gabungan
Apakah data mengalir utuh dari sensor sampai dashboard?

Telusuri **satu nilai** dari awal sampai akhir.

| Titik | Nilai yang terlihat | Cap waktu |
|-------|--------------------|-----------|
| Serial Monitor | | |
| Aplikasi klien MQTT | | |
| Basis data | | |
| Dashboard | | |

[ Apakah nilainya sama di semua titik? Bila berbeda, di mana berubahnya? ]

---

## Lapis 3 - Pengujian fungsi
Apakah sistem melakukan yang dijanjikan proposal?

| No | Ukuran keberhasilan (dari proposal) | Hasil pengujian | Tercapai? |
|----|--------------------------------------|-----------------|-----------|
| 1 | | | ya / tidak |
| 2 | | | ya / tidak |
| 3 | | | ya / tidak |

---

## Lapis 4 - Pengujian ketahanan
**Bagian yang paling sering dilewatkan.**

| Gangguan | Perilaku saat gangguan | Perilaku setelah pulih | Sesuai harapan? |
|----------|------------------------|------------------------|-----------------|
| WiFi dimatikan 10 menit | | | |
| Broker/cloud tak terjangkau | | | |
| Sensor dicabut lalu dipasang | | | |
| Perangkat dimatikan lalu dinyalakan | | | |
| Dibiarkan menyala semalaman | | | |

### Uji menyala lama (wajib)
| Butir | Hasil |
|-------|-------|
| Lama menyala | ... jam |
| Jumlah data seharusnya | |
| Jumlah data sebenarnya | |
| Selisih (data hilang) | |
| Apakah perangkat memulai ulang sendiri? | |
| Apakah memori menipis? | |

---

## Evaluasi terhadap masalah
Pengujian menjawab apakah sistem bekerja. Evaluasi menjawab apakah
**masalahnya berkurang**.

| Butir | Sebelum sistem dipasang | Sesudah | Perubahan |
|-------|-------------------------|---------|-----------|
| | | | |

[ Bila belum ada data pembanding sebelum sistem dipasang, keberhasilan tidak
  dapat dibuktikan. Catat hal ini sebagai keterbatasan. ]

---

## Temuan yang tidak sesuai harapan
Tuliskan dengan jujur beserta dugaan penyebabnya. Temuan negatif tetap
bernilai sepanjang disertai analisis.

[ ... ]
