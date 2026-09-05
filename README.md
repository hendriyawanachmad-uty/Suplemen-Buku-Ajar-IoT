# Buku Ajar Internet of Things (IoT) berbasis ESP32 — Repositori Companion

Repositori ini adalah materi daring pendamping (companion) untuk **Buku Ajar Internet of Things (IoT)**
yang disusun selaras dengan Rencana Pembelajaran Semester (RPS) mata kuliah IoT (3 SKS).
Kode program lengkap, berkas rangkaian, panduan instalasi rinci, dataset, bank soal, dan templat ditempatkan di sini.

> Platform praktik utama: **ESP32** + sensor + aktuator + cloud. Praktik dapat dikerjakan pada
> perangkat keras nyata maupun simulator **Wokwi**.

## Cara menggunakan repositori ini

1. Baca babnya di buku cetak, lalu buka folder bab yang sesuai di sini (lihat pemetaan di bawah).
2. Setiap folder bab berisi:
   - `kode/` — kode program lengkap tiap praktik.
   - `rangkaian/` — berkas/gambar rangkaian dan proyek Wokwi.
   - `latihan/` — berkas pendukung latihan dan self-assessment.
3. Ikuti panduan instalasi di [`docs/instalasi.md`](docs/instalasi.md) sebelum praktik pertama.
4. Siapkan komponen sesuai [`docs/daftar-komponen-BOM.md`](docs/daftar-komponen-BOM.md).

## Pemetaan Bab — Minggu — CPMK

| Bab | Judul | Minggu (RPS) | CPMK | Folder |
|----|-------|--------------|------|--------|
| 1 | Konsep dan Arsitektur IoT | 1–2 | CPMK1 | `bab-01-konsep-arsitektur/` |
| 2 | Perangkat Keras IoT: ESP32, Sensor, Aktuator | 3–4 | CPMK2 | `bab-02-perangkat-keras/` |
| 3 | Pemrograman ESP32: Akuisisi & Kendali | 5–6 | CPMK4 | `bab-03-pemrograman-esp32/` |
| 4 | Konektivitas dan Jaringan IoT | 7 | CPMK3 | `bab-04-konektivitas/` |
| 5 | Protokol Komunikasi IoT | 9 | CPMK3 | `bab-05-protokol-komunikasi/` |
| 6 | Integrasi Platform Cloud IoT | 10 | CPMK5 | `bab-06-platform-cloud/` |
| 7 | Basis Data dan Visualisasi Data IoT | 11 | CPMK5 | `bab-07-basisdata/` |
| 8 | Edge/Fog Computing & Analitik Data | 12 | CPMK5 | `bab-08-edge-analitik/` |
| 9 | Keamanan dan Privasi Sistem IoT | 13 | CPMK6 | `bab-09-keamanan/` |
| 10 | Penerapan IoT pada Domain Nyata | 14 | CPMK1, CPMK7 | `bab-10-penerapan-domain/` |
| 11 | Perancangan Proyek IoT End-to-End | 15 | CPMK7 | `bab-11-proyek-end-to-end/` |

_Minggu 8 = UTS, Minggu 16 = UAS (tidak memiliki folder bab)._

## Struktur repositori

```
buku-ajar-iot-esp32/
├── README.md
├── LICENSE                     # MIT untuk kode; materi non-kode CC BY 4.0 (lihat README)
├── CITATION.cff                # cara mengutip
├── CONTRIBUTING.md
├── .gitignore
├── docs/
│   ├── instalasi.md
│   ├── daftar-komponen-BOM.md
│   ├── panduan-wokwi.md
│   └── erata.md
├── templat/
│   ├── proposal-proyek.md
│   ├── laporan-praktik.md
│   ├── laporan-proyek-akhir.md
│   └── platformio.ini.contoh
├── bank-soal/
│   └── README.md
└── bab-01 … bab-11/
    ├── README.md
    ├── kode/
    ├── rangkaian/
    └── latihan/
```

## Lisensi

- **Kode program** (folder `kode/`, berkas `.ino`, `.py`, dsb.): Lisensi **MIT** (lihat [`LICENSE`](LICENSE)).
- **Materi non-kode** (teks, gambar, latihan, templat): **Creative Commons Attribution 4.0 (CC BY 4.0)**.

## Cara mengutip

Lihat [`CITATION.cff`](CITATION.cff), atau gunakan format yang tercantum di halaman buku.

## Kontak

Penulis/pengampu: [NAMA] — [EMAIL/INSTITUSI]. Laporkan kesalahan melalui Issues atau [`docs/erata.md`](docs/erata.md).
