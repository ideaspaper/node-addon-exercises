# Node Addon

Repo ini adalah repo pembelajaran personal tentang Node Addon.

Mengutip dari dokumentasi Node.js, definisi dari Node Addon adalah seperti di bawah.

> Addons are dynamically-linked shared objects written in C++. The `require()` function can load addons as ordinary Node.js modules. Addons provide an interface between JavaScript and C/C++ libraries.

Apa keuntungan dari penggunaan Node Addon? Sama seperti ketika kita menggunakan C/C++. Waktu eksekusi compiled language (C/C++) akan lebih cepat dibandingkan dengan interpreted language (JavaScript), sehingga, jika Node Addon diaplikasikan dengan benar dapat memberikan peningkatan performa. Selain itu nature dari C/C++ adalah closed source. Maka dari itu, kita dapat menyembunyikan algoritma/kode program kita yang bersifat confidential dari customer.

## Peningkatan Performa

Seperti yang telah disebutkan sebelumnya, maka pada contoh `02-performance-comparison` dibuat sebuah fungsi recursive sederhana untuk bilangan Fibonacci. Dari hasil percobaan sederhana, didapatkan hasil seperti di bawah.

```
Regular Fibonacci execution time (hr): 20s 98.934679ms
Addon Fibonacci execution time (hr): 8s 480.944312ms
```

Waktu tersebut tentu berbeda apabila percobaan dilakukan pada komputer lain dengan spesifikasi yang berbeda. Namun dapat dilihat bahwa eksekusi function regular Fibonacci pada JavaScript membutuhkan waktu 2 kali lebih lama dari implementasi Node Addon (C++).

## How to Use

Masuk ke salah satu folder examples yang ada. Eksekusi command `npm i`. Apabila terdapat perubahan pada file `cc`, jalankan `npm i` kembali untuk proses compile executable binary.