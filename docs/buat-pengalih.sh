#!/usr/bin/env bash
# Membangkitkan ulang seluruh halaman pengalih dari peta.txt
# Jalankan dari dalam folder docs/ :  bash buat-pengalih.sh
set -e
USER="hendriyawanachmad-uty"
REPO="Suplemen-Buku-Ajar-IoT"
BRANCH="main"

while IFS='|' read -r kode folder judul; do
  [[ "$kode" =~ ^#.*$ || -z "$kode" ]] && continue
  tujuan="https://github.com/$USER/$REPO/tree/$BRANCH/$folder"
  mkdir -p "$kode"
  cat > "$kode/index.html" <<HTML
<!DOCTYPE html>
<html lang="id">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta http-equiv="refresh" content="0; url=$tujuan">
<link rel="canonical" href="$tujuan">
<title>$judul</title>
<style>
 body{font-family:system-ui,-apple-system,Segoe UI,Roboto,sans-serif;
      max-width:34rem;margin:4rem auto;padding:0 1.25rem;line-height:1.6;color:#1a1a1a}
 h1{font-size:1.25rem;margin-bottom:.5rem}
 a.tombol{display:inline-block;margin-top:1rem;padding:.7rem 1.2rem;
      background:#1F3864;color:#fff;text-decoration:none;border-radius:8px}
 p.kecil{color:#666;font-size:.9rem;margin-top:2rem}
</style>
</head>
<body>
  <h1>$judul</h1>
  <p>Mengalihkan ke materi daring&hellip;</p>
  <a class="tombol" href="$tujuan">Buka sekarang</a>
  <p class="kecil">Buku Ajar Internet of Things (IoT) &mdash; repositori suplemen.<br>
  Bila halaman tidak berpindah sendiri, tekan tombol di atas.</p>
</body>
</html>
HTML
  echo "  dibuat: $kode/  ->  $folder"
done < peta.txt
echo "Selesai. Jangan lupa commit dan push."
