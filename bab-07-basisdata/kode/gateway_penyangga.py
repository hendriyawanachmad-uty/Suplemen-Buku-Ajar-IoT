#!/usr/bin/env python3
"""
Buku Ajar IoT berbasis ESP32 - Repositori Suplemen
Bab 7: basis data lokal pada gateway sebagai penyangga.

Menyimpan telemetri ke SQLite lebih dahulu, lalu mengirimkannya ke cloud.
Bila pengiriman gagal, data TETAP tersimpan dan dicoba lagi kemudian,
sehingga riwayat tidak berlubang saat jaringan terputus.

Lisensi: MIT
Kebutuhan: hanya pustaka bawaan Python (sqlite3). Tidak perlu pemasangan.
"""

import sqlite3
import time
from datetime import datetime, timezone

DB = "penyangga.db"
BATAS_BARIS = 100_000      # kapasitas penyangga; sesuaikan dengan gateway
UKURAN_KIRIM = 50          # banyak baris per sekali kirim


def siapkan():
    """Membuat tabel antrean bila belum ada."""
    with sqlite3.connect(DB) as db:
        db.execute("""
            CREATE TABLE IF NOT EXISTS antrean (
                id        INTEGER PRIMARY KEY,
                waktu     TEXT NOT NULL,
                perangkat TEXT NOT NULL,
                suhu      REAL,
                kelembaban REAL,
                terkirim  INTEGER DEFAULT 0
            )
        """)
        # Indeks pada kolom penanda agar pencarian antrean cepat
        db.execute("""
            CREATE INDEX IF NOT EXISTS idx_belum_terkirim
            ON antrean (terkirim, id)
        """)


def simpan(perangkat, suhu, kelembaban):
    """Menyimpan pembacaan ke penyangga lokal. Selalu berhasil selama
    penyimpanan masih tersedia, meski jaringan sedang mati."""
    waktu = datetime.now(timezone.utc).isoformat()
    with sqlite3.connect(DB) as db:
        db.execute(
            "INSERT INTO antrean (waktu, perangkat, suhu, kelembaban) "
            "VALUES (?, ?, ?, ?)",
            (waktu, perangkat, suhu, kelembaban),
        )
        jaga_kapasitas(db)


def jaga_kapasitas(db):
    """Bila penyangga penuh, buang data TERLAMA yang sudah terkirim lebih
    dahulu. Bila masih penuh juga, barulah buang yang terlama secara umum.

    Keputusan ini harus diambil secara sadar sejak awal: kehilangan data
    terlama umumnya lebih dapat diterima daripada berhenti mencatat sama
    sekali karena penyimpanan penuh."""
    (jumlah,) = db.execute("SELECT COUNT(*) FROM antrean").fetchone()
    if jumlah <= BATAS_BARIS:
        return

    kelebihan = jumlah - BATAS_BARIS
    db.execute(
        "DELETE FROM antrean WHERE id IN ("
        "  SELECT id FROM antrean WHERE terkirim = 1 "
        "  ORDER BY id LIMIT ?)",
        (kelebihan,),
    )
    (jumlah,) = db.execute("SELECT COUNT(*) FROM antrean").fetchone()
    if jumlah > BATAS_BARIS:
        db.execute(
            "DELETE FROM antrean WHERE id IN ("
            "  SELECT id FROM antrean ORDER BY id LIMIT ?)",
            (jumlah - BATAS_BARIS,),
        )
        print("PERINGATAN: penyangga penuh, data terlama dibuang.")


def kirim_ke_cloud(baris):
    """Ganti isi fungsi ini dengan pengiriman sungguhan (HTTP/MQTT).
    Kembalikan True bila berhasil, False bila gagal."""
    print(f"  mengirim {len(baris)} baris ke cloud...")
    return True     # untuk latihan, anggap selalu berhasil


def kirim_antrean():
    """Mengirim data yang belum terkirim, lalu menandainya."""
    with sqlite3.connect(DB) as db:
        baris = db.execute(
            "SELECT id, waktu, perangkat, suhu, kelembaban "
            "FROM antrean WHERE terkirim = 0 ORDER BY id LIMIT ?",
            (UKURAN_KIRIM,),
        ).fetchall()

        if not baris:
            return 0

        if kirim_ke_cloud(baris):
            # Ditandai terkirim, BUKAN langsung dihapus, agar data masih
            # dapat ditelusuri sebentar bila terjadi persoalan di cloud.
            db.executemany(
                "UPDATE antrean SET terkirim = 1 WHERE id = ?",
                [(b[0],) for b in baris],
            )
            return len(baris)

        print("  pengiriman gagal, data tetap tersimpan untuk dicoba lagi.")
        return 0


def laporan():
    with sqlite3.connect(DB) as db:
        (total,)  = db.execute("SELECT COUNT(*) FROM antrean").fetchone()
        (tunggu,) = db.execute(
            "SELECT COUNT(*) FROM antrean WHERE terkirim = 0").fetchone()
    print(f"  total {total} baris, {tunggu} menunggu dikirim")


if __name__ == "__main__":
    siapkan()
    print("Penyangga gateway berjalan. Tekan Ctrl+C untuk berhenti.")
    try:
        while True:
            # Pada sistem nyata, nilai berikut berasal dari perangkat.
            simpan("esp32-01", 28.4, 61.0)
            kirim_antrean()
            laporan()
            time.sleep(10)
    except KeyboardInterrupt:
        print("\nBerhenti. Data yang belum terkirim tetap tersimpan.")
