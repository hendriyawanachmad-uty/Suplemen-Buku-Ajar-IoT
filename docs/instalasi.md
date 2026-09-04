# Panduan Instalasi Lingkungan Pengembangan

Panduan ini disiapkan sekali dan dirujuk oleh seluruh bab praktik.

## 1. Pilihan lingkungan

| Opsi | Cocok untuk | Kebutuhan |
|------|-------------|-----------|
| Arduino IDE | Pemula, praktik cepat | Aplikasi Arduino IDE 2.x |
| PlatformIO (VS Code) | Proyek besar, manajemen library | VS Code + ekstensi PlatformIO |
| Wokwi (simulator) | Tanpa hardware | Peramban web / ekstensi Wokwi di VS Code |

## 2. Menyiapkan Arduino IDE untuk ESP32

1. Pasang Arduino IDE 2.x.
2. File > Preferences > Additional Board Manager URLs, tambahkan URL board ESP32 (arduino-esp32).
3. Tools > Board > Boards Manager, cari "esp32", pasang paketnya.
4. Pilih board (mis. "ESP32 Dev Module") dan port yang sesuai.
5. Pasang driver USB-to-UART bila port tidak terdeteksi (CP210x / CH340 sesuai board).

## 3. Library yang sering dipakai

> Daftar akan dilengkapi per bab. Contoh umum: sensor DHT, klien MQTT, dan pustaka platform cloud.

- [ ] TODO: cantumkan nama dan versi library terkunci per bab.

## 4. Mengelola kredensial dengan aman

Jangan pernah menulis SSID, password, atau token langsung di berkas yang di-commit.
Gunakan berkas `secrets.h` (sudah masuk `.gitignore`) dan sediakan `secrets.h.contoh`:

```cpp
// secrets.h.contoh  (salin menjadi secrets.h lalu isi)
#define WIFI_SSID     "GANTI_SSID"
#define WIFI_PASSWORD "GANTI_PASSWORD"
#define CLOUD_TOKEN   "GANTI_TOKEN"
```

## 5. Uji instalasi

Unggah program "Blink" pada `bab-02-perangkat-keras/kode/` untuk memastikan toolchain berfungsi.
