-- Buku Ajar IoT berbasis ESP32 - Repositori Suplemen
-- Bab 7: kueri contoh untuk data sensor

-- ============================================================
-- 1. Menyimpan pembacaan baru
-- ============================================================
INSERT INTO pembacaan (perangkat_id, waktu, suhu, kelembaban)
VALUES (1, datetime('now'), 28.4, 61.0);

-- ============================================================
-- 2. Data mentah pada rentang waktu (kueri paling sering dipakai)
-- ============================================================
SELECT waktu, suhu, kelembaban
FROM pembacaan
WHERE perangkat_id = 1
  AND waktu >= datetime('now', '-1 hour')
ORDER BY waktu;

-- ============================================================
-- 3. Ringkasan per jam untuk satu hari terakhir
-- ============================================================
SELECT
  strftime('%Y-%m-%d %H:00', waktu) AS jam,
  ROUND(AVG(suhu), 2) AS suhu_rata,
  ROUND(MIN(suhu), 2) AS suhu_min,
  ROUND(MAX(suhu), 2) AS suhu_maks,
  COUNT(*)            AS jumlah_data
FROM pembacaan
WHERE perangkat_id = 1
  AND waktu >= datetime('now', '-1 day')
GROUP BY jam
ORDER BY jam;

-- ============================================================
-- 4. Menggabungkan dengan tabel acuan (kekuatan basis data relasional)
-- ============================================================
SELECT p.gedung, p.ruang, ROUND(AVG(b.suhu), 2) AS suhu_rata
FROM pembacaan b
JOIN perangkat p ON p.id = b.perangkat_id
WHERE b.waktu >= datetime('now', '-1 day')
GROUP BY p.gedung, p.ruang
ORDER BY suhu_rata DESC;

-- ============================================================
-- 5. Membuktikan pengaruh indeks
-- ============================================================
-- Jalankan sebelum dan sesudah membuat indeks, lalu bandingkan rencananya.
EXPLAIN QUERY PLAN
SELECT * FROM pembacaan
WHERE perangkat_id = 1 AND waktu >= datetime('now', '-1 day');

-- Tanpa indeks : terlihat "SCAN pembacaan"   (memeriksa seluruh baris)
-- Dengan indeks: terlihat "SEARCH pembacaan" (langsung ke bagian yang dicari)
--
-- Hasil pengukuran pada 200.000 baris (SQLite):
--   tanpa indeks  : ~20 ms
--   dengan indeks : ~0,4 ms   -> sekitar 50 kali lebih cepat
-- Selisihnya makin besar seiring bertambahnya jumlah baris.
--
-- CATATAN saat menguji: buka koneksi BARU setelah membuat indeks, sebab
-- rencana kueri yang sudah tersimpan di memori tidak dihitung ulang.

-- ============================================================
-- 6. AGREGASI: memindahkan data lama menjadi ringkasan per jam
-- ============================================================
INSERT OR REPLACE INTO ringkasan_jam
  (perangkat_id, jam, suhu_rata, suhu_min, suhu_maks, jumlah_data)
SELECT
  perangkat_id,
  strftime('%Y-%m-%d %H:00', waktu),
  AVG(suhu), MIN(suhu), MAX(suhu), COUNT(*)
FROM pembacaan
WHERE waktu < datetime('now', '-7 day')
GROUP BY perangkat_id, strftime('%Y-%m-%d %H:00', waktu);

-- ============================================================
-- 7. RETENSI: menghapus data mentah yang sudah diringkas
-- ============================================================
-- PERINGATAN: penghapusan bersifat TETAP. Pastikan langkah 6 sudah
-- dijalankan dan hasilnya diperiksa sebelum menjalankan perintah ini.
DELETE FROM pembacaan
WHERE waktu < datetime('now', '-7 day');

-- ============================================================
-- 8. Memperkirakan pertumbuhan penyimpanan
-- ============================================================
SELECT
  COUNT(*) AS jumlah_baris,
  MIN(waktu) AS terlama,
  MAX(waktu) AS terbaru
FROM pembacaan;
