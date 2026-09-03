/*
 * Buku Ajar Internet of Things (IoT) berbasis ESP32 - Repositori Suplemen
 * Bab 8 - Komunikasi MQTT terenkripsi dengan TLS.
 *
 * Menunjukkan KEDUA fungsi TLS:
 *   1. menyandikan isi pesan  -> penyadap hanya melihat huruf acak
 *   2. memeriksa sertifikat   -> perangkat yakin bicara dengan broker yang benar
 *
 * PENTING: materi ini bersifat DEFENSIF. Terapkan hanya pada sistem dan
 * akun milik Anda sendiri.
 *
 * Lisensi kode: MIT
 * Library: PubSubClient, DHT sensor library, Adafruit Unified Sensor.
 */
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "secrets.h"

#define PIN_DHT 4
#define DHTTYPE DHT22

const unsigned long SELANG_KIRIM = 10000;

/* Sertifikat otoritas penerbit (root CA) milik broker.
 * Lihat latihan/panduan-sertifikat.md untuk cara memperolehnya.
 * Sertifikat memiliki masa berlaku; bila koneksi tiba-tiba gagal setelah
 * sekian lama, periksa apakah sertifikat ini sudah kedaluwarsa. */
const char* CA_CERT = R"EOF(
-----BEGIN CERTIFICATE-----
GANTI_DENGAN_SERTIFIKAT_BROKER_ANDA
-----END CERTIFICATE-----
)EOF";

DHT dht(PIN_DHT, DHTTYPE);
WiFiClientSecure aman;              // klien ber-TLS, bukan WiFiClient biasa
PubSubClient mqtt(aman);

unsigned long terakhirKirim = 0;

void hubungkanWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Menyambung WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi terhubung.");
}

void sambungMQTT() {
  while (!mqtt.connected()) {
    String id = "esp32-tls-" + String(random(9999));
    Serial.print("Menyambung broker melalui TLS...");

    if (mqtt.connect(id.c_str(), MQTT_USER, MQTT_PASS)) {
      Serial.println(" berhasil.");
    } else {
      Serial.print(" gagal, kode = ");
      Serial.println(mqtt.state());
      Serial.println("Periksa sertifikat, porta, dan waktu perangkat.");
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  hubungkanWiFi();

  // Waktu perangkat harus benar, sebab masa berlaku sertifikat diperiksa
  // terhadap waktu saat ini. Waktu yang salah membuat koneksi TLS ditolak.
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  Serial.print("Menyelaraskan waktu");
  while (time(nullptr) < 100000) {
    delay(300);
    Serial.print(".");
  }
  Serial.println(" selesai.");

  // Inilah baris yang mengaktifkan pemeriksaan keaslian broker.
  // Menggantinya dengan aman.setInsecure() memang membuat koneksi cepat
  // berhasil, tetapi menghapus fungsi kedua TLS. Jangan dipakai pada
  // sistem sungguhan.
  aman.setCACert(CA_CERT);

  mqtt.setServer(MQTT_BROKER, MQTT_PORT);   // porta 8883
}

void loop() {
  if (!mqtt.connected()) sambungMQTT();
  mqtt.loop();

  if (millis() - terakhirKirim < SELANG_KIRIM) return;
  terakhirKirim = millis();

  float suhu = dht.readTemperature();
  if (isnan(suhu)) return;

  char muatan[16];
  dtostrf(suhu, 4, 1, muatan);
  mqtt.publish(TOPIC_SUHU, muatan);

  Serial.print("Terkirim terenkripsi: ");
  Serial.println(muatan);
}
