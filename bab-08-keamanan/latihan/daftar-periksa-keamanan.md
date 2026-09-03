# Daftar Periksa Keamanan Sistem IoT

Gunakan daftar ini untuk menilai sistem yang Anda bangun. Setiap butir
mengacu pada pembahasan Bab 8.

## Perangkat
- [ ] Kata sandi bawaan pabrik sudah diganti
- [ ] Tiap perangkat memiliki kredensial sendiri, tidak seragam
- [ ] Kredensial tidak ditulis langsung pada berkas kode yang dibagikan
- [ ] Berkas `secrets.h` tercantum pada `.gitignore`
- [ ] Porta debug dan layanan yang tidak dipakai sudah ditutup
- [ ] Perangkat tetap berfungsi aman bila jaringan terputus

## Jaringan
- [ ] Komunikasi memakai TLS (porta 8883 untuk MQTT)
- [ ] Pemeriksaan sertifikat aktif, bukan `setInsecure()`
- [ ] Waktu perangkat diselaraskan melalui NTP
- [ ] Jaringan WiFi memakai kata sandi yang kuat

## Cloud / Broker
- [ ] Broker meminta autentikasi, tidak terbuka untuk umum
- [ ] Tiap perangkat hanya berwenang pada topic miliknya sendiri
- [ ] Kredensial dapat dibatalkan satu per satu
- [ ] Ada rencana tindakan bila kredensial bocor

## Firmware
- [ ] Tersedia jalur pembaruan (OTA)
- [ ] Firmware diperiksa tanda tangannya sebelum dipasang
- [ ] Tersedia dua partisi agar dapat kembali bila pembaruan gagal

## Privasi
- [ ] Hanya mengumpulkan data yang benar-benar dibutuhkan
- [ ] Data tidak disimpan lebih lama daripada keperluannya
- [ ] Identitas disamarkan bila data dianalisis secara agregat
- [ ] Pengguna diberi tahu data apa yang dikumpulkan dan untuk apa

## Catatan
Tidak semua butir dapat dipenuhi pada proyek perkuliahan, terutama yang
berkaitan dengan OTA bertanda tangan. Yang penting adalah **menyadari** butir
mana yang belum terpenuhi dan mengetahui akibatnya, bukan berpura-pura
sistemnya sudah aman.
