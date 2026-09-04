-- Buku Ajar IoT berbasis ESP32 - Repositori Suplemen
-- Bab 7: skema penyimpanan data sensor
-- Dapat dijalankan pada SQLite maupun (dengan sedikit penyesuaian) MySQL.

-- Tabel acuan: berisi data yang jarang berubah dan saling berelasi.
CREATE TABLE IF NOT EXISTS perangkat (
  id       INTEGER PRIMARY KEY,
  nama     TEXT NOT NULL UNIQUE,   -- mis. esp32-01
  gedung   TEXT,
  ruang    TEXT,
  dipasang DATE
);

-- Tabel telemetri: terus bertambah, hampir tidak pernah diubah.
CREATE TABLE IF NOT EXISTS pembacaan (
  id           INTEGER PRIMARY KEY,
  perangkat_id INTEGER NOT NULL,
  waktu        DATETIME NOT NULL,
  suhu         REAL,
  kelembaban   REAL,
  FOREIGN KEY (perangkat_id) REFERENCES perangkat(id)
);

-- INDEKS: bagian yang paling menentukan kecepatan kueri.
-- Hampir semua kueri data IoT menyaring berdasarkan perangkat dan waktu,
-- sehingga indeks gabungan kedua kolom itu paling berguna.
CREATE INDEX IF NOT EXISTS idx_pembacaan_perangkat_waktu
  ON pembacaan (perangkat_id, waktu);

-- Tabel ringkasan: hasil agregasi data lama (lihat kueri-contoh.sql).
CREATE TABLE IF NOT EXISTS ringkasan_jam (
  perangkat_id   INTEGER NOT NULL,
  jam            DATETIME NOT NULL,
  suhu_rata      REAL,
  suhu_min       REAL,
  suhu_maks      REAL,
  jumlah_data    INTEGER,
  PRIMARY KEY (perangkat_id, jam)
);

-- Data contoh
INSERT OR IGNORE INTO perangkat (id, nama, gedung, ruang, dipasang)
VALUES (1, 'esp32-01', 'A', '101', '2026-01-15'),
       (2, 'esp32-02', 'A', '102', '2026-01-15'),
       (3, 'esp32-03', 'B', '205', '2026-02-01');
