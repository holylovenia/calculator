KALKULATOR
Tugas 2 TBFO

Oktavianus Handika / 13515035
Holy Lovenia / 13515113
------------------------------------------------------



Deskripsi Program
------------------------------------------------------
Program ini adalah bentuk dari implementasi CFG dan PDA
yang digunakan untuk menentukan validitas dan hasil
kalkulasi suatu ekspresi matematika. Bila ekspresi mate-
matika tersebut tidak valid, maka program akan mengeluarkan
"SYNTAX ERROR". Sedangkan apabila ekspresi matematika ter-
sebut valid, program akan menghitung dan menampilkan hasil
dari ekspresi matematika tersebut.


Cara Kerja
------------------------------------------------------
Program utama (ekspresi.c) menggunakan modul boolean.h untuk memungkinkan penggunaan nilai true (benar) dan false (salah), library stdio.h juga digunakan untuk membaca input dari
pengguna dan menampilkannya ke monitor. Program utama menerima
masukan ekspresi matematika dari pengguna yang diakhiri dengan
MARK ("="). Lalu, program akan melakukan validasi dengan CYK
Algorithm. Apabila ekspresi valid, maka program akan menuliskan
ekspresi tersebut ke sebuah file eksternal (input.txt) sebagai
informasi tentang kalkulasi terakhir yang user lakukan. Program
akan membaca kembali ekspresi tersebut menggunakan ADT Mesin
Karakter (mesinkar.c) dan ADT Mesin Token (mesintoken.c).
Terakhir, program akan melakukan kalkulasi dengan 2 stack of
token yang dikonstruksi menggunakan ADT Stack (stackt.c), lalu
menampilkan hasilnya. Apabila ekspresi tidak valid, maka
program akan mengeluarkan pesan error.


Dokumen
------------------------------------------------------
Dokumen dapat diperoleh dalam folder doc.


Cara Compile (Terminal)
------------------------------------------------------
gcc ekspresi.c mesinkar.c mesintoken.c stackt.c -o ekspresi


Aplikasi
------------------------------------------------------
Program dapat dijalankan dengan membuka ekspresi.exe pada folder bin.