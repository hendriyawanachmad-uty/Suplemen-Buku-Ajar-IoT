// Buku Ajar IoT berbasis ESP32 - Repositori Suplemen
// Bab 7: contoh dokumen dan kueri MongoDB

// ============================================================
// 1. Bentuk dokumen
// ============================================================
// Perhatikan objek bersarang (lokasi, bacaan) yang tidak dapat dilakukan
// langsung pada tabel relasional.
db.pembacaan.insertOne({
  perangkat: "esp32-01",
  lokasi: { gedung: "A", ruang: "101" },
  waktu: new Date("2026-05-20T10:00:00Z"),
  bacaan: { suhu: 28.4, kelembaban: 61 }
});

// Keluwesan: perangkat lain boleh mengirim medan yang berbeda
db.pembacaan.insertOne({
  perangkat: "esp32-09",
  lokasi: { gedung: "B", ruang: "205" },
  waktu: new Date("2026-05-20T10:00:00Z"),
  bacaan: { gas_ppm: 412, kebisingan_db: 55 }   // medan berbeda
});

// ============================================================
// 2. Indeks (tetap diperlukan, sama seperti basis data lain)
// ============================================================
db.pembacaan.createIndex({ perangkat: 1, waktu: -1 });

// ============================================================
// 3. Kueri rentang waktu
// ============================================================
db.pembacaan.find({
  perangkat: "esp32-01",
  waktu: { $gte: new Date(Date.now() - 24*60*60*1000) }
}).sort({ waktu: 1 });

// ============================================================
// 4. Ringkasan per jam (aggregation pipeline)
// ============================================================
db.pembacaan.aggregate([
  { $match: {
      "lokasi.gedung": "A",
      waktu: { $gte: new Date(Date.now() - 24*60*60*1000) }
  }},
  { $group: {
      _id: {
        ruang: "$lokasi.ruang",
        jam: { $dateTrunc: { date: "$waktu", unit: "hour" } }
      },
      suhu_rata: { $avg: "$bacaan.suhu" },
      suhu_maks: { $max: "$bacaan.suhu" },
      jumlah:    { $sum: 1 }
  }},
  { $sort: { "_id.jam": 1 } }
]);

// ============================================================
// CATATAN PENTING
// ============================================================
// Keluwesan skema menyimpan risiko. Karena tidak ada aturan yang memaksa
// keseragaman, mudah terjadi ketidakkonsistenan seperti:
//     { bacaan: { suhu: 28.4 } }
//     { bacaan: { temperature: 28.4 } }   <- nama medan berbeda
//     { suhu: 28.4 }                      <- tanpa objek bersarang
// Ketiganya sah bagi MongoDB, tetapi kueri agregasi menjadi kacau.
// Sepakati penamaan sejak awal dan tegakkan sendiri melalui kode.
