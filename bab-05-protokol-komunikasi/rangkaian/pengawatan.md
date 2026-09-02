# Pengawatan: Praktik MQTT (Bab 5)

| Komponen | Pin komponen | Pin ESP32 |
|----------|--------------|-----------|
| DHT22 | VCC | 3V3 |
| DHT22 | DATA | GPIO4 |
| DHT22 | GND | GND |

Untuk `mqtt_subscribe.ino` cukup memakai LED bawaan pada GPIO2, tanpa
komponen tambahan.

Catatan:
- Rangkaian sama seperti Bab 2 dan Bab 4. Yang berubah pada bab ini adalah
  cara data dikirim, yaitu melalui broker MQTT.
- Pada Wokwi, gunakan SSID "Wokwi-GUEST" dengan kata sandi kosong.
