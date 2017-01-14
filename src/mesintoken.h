/*	
	KELAS 02
	Oktavianus Handika / 13515035
	Holy Lovenia / 13515113
*/


/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

#ifndef __MESINTOKEN_H__
#define __MESINTOKEN_H__

#include "boolean.h"
#include "mesinkar.h"
#include "token.h"
#include "stackt.h"

#define NMax 500
#define BLANK ' '


/* State Mesin Kata */
extern boolean EndToken;
extern Token CToken;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN();
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken();
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsNumber (char C);
		  
boolean IsCertainOperator (char C);
		  
boolean IsOperator (char C);
		  
boolean IsHigherPrecedence (Token T1, Token T2);

Token EksekusiOperator (Token T, Token op1, Token op2);

void Perhitungan (Stack * SOperator, Stack * SAngka, boolean * math);
		  
#endif