/*	
	KELAS 02
	Oktavianus Handika / 13515035
	Holy Lovenia / 13515113
*/


/* File : stackt.c */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "stackt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */

void CreateEmpty (Stack *S)
{
	Top(*S) = Nil;
}
/* I.S. sembarang{} */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */

boolean IsEmpty (Stack S)
{
	return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull (Stack S)
{
	return (Top(S) == MaxEl);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */


/* ************ Menambahkan sebuah elemen ke Stack ************ */

void Push (Stack * S, infotype X)
{
	Top(*S)++;
	InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */


/* ************ Menghapus sebuah elemen Stack ************ */

void Pop (Stack * S, infotype* X)
{
	*X = InfoTop(*S);
	Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */