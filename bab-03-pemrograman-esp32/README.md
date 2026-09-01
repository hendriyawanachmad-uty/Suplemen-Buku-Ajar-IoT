# Bab 3 - Pemrograman ESP32: Akuisisi Data dan Kendali Aktuator

- **Bab pada buku:** 3
- **Minggu (RPS):** 5-6
- **CPMK:** CPMK4

## Praktik pada bab ini
Membangun sistem kipas otomatis: membaca suhu secara berkala dengan penjadwalan
`millis()`, menyalakan relai memakai kendali dua ambang (histeresis), menambahkan
LED indikator ber-PWM, dan tombol mode manual dengan debouncing.
Kode juga menunjukkan pola *finite state machine* untuk pengelolaan mode.

## Isi folder
- `kode/kipas_otomatis.ino` - kode lengkap praktik (implementasi Algoritma 3.1).
- `kode/pwm_core3.ino` - contoh PWM untuk Arduino-ESP32 inti versi 3.x.
- `kode/pwm_core2.ino` - contoh PWM untuk Arduino-ESP32 inti versi 2.x.
- `rangkaian/pengawatan.md` - tabel pengawatan.
- `rangkaian/diagram.json` - berkas rangkaian untuk Wokwi.
- `latihan/lembar-kerja.md` - lembar kerja praktik.
- `kunci-jawaban-bab-03.md` - kunci pilihan ganda & jawaban lengkap esai.

## PENTING: perbedaan API PWM antar versi inti
Nama fungsi PWM berbeda antara Arduino-ESP32 inti versi 2.x dan 3.x. Periksa versi
inti Anda di Arduino IDE melalui Boards Manager ("esp32 by Espressif Systems").

| Inti | Menyiapkan PWM | Menulis duty cycle |
|------|----------------|--------------------|
| 3.x  | `ledcAttach(pin, freq, resolusi)` | `ledcWrite(pin, duty)` |
| 2.x  | `ledcSetup(kanal, freq, resolusi)` lalu `ledcAttachPin(pin, kanal)` | `ledcWrite(kanal, duty)` |

Buku menggunakan gaya inti 3.x. Jika kode tidak dapat dikompilasi, gunakan
`kode/pwm_core2.ino` sebagai acuan.

## Cara menjalankan
1. Pasang toolchain dan library DHT (lihat `../docs/instalasi.md`).
2. Rangkai sesuai `rangkaian/pengawatan.md`.
3. Unggah `kode/kipas_otomatis.ino`, buka Serial Monitor pada 115200.
4. Hangatkan sensor (mis. dengan telapak tangan) dan amati perilaku relai.

## Hubungan dengan Algoritma 3.1
| Langkah Algoritma 3.1 | Bagian pada kode |
|-----------------------|------------------|
| 1-2 (MATI, nilai > ambangAtas -> NYALA) | `if (!kipasNyala && suhu > AMBANG_ATAS)` |
| 3-4 (NYALA, nilai < ambangBawah -> MATI) | `else if (kipasNyala && suhu < AMBANG_BAWAH)` |
| 6 (di dalam pita histeresis: status tetap) | tidak ada cabang lain, status dibiarkan |
| 7 (terapkan status) | `digitalWrite(PIN_RELAI, ...)` |
