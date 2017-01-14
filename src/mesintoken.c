/*	
	KELAS 02
	Oktavianus Handika / 13515035
	Holy Lovenia / 13515113
*/


/* File: mesintoken.c */
/* Definisi Mesin Token: Model Akuisisi Versi I */


#include "mesintoken.h"
#include <stdio.h>


/* State Mesin Kata */
boolean EndToken;
Token CToken;


void IgnoreBlank()
{
	while ((CC == BLANK) && (CC != MARK))
	{
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */


void STARTTOKEN()
{
	START();
	
	if (CC == MARK)
	{
		EndToken = true;
	}
	else
	{
		EndToken = false;
		SalinToken();
	}
}
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */


void ADVTOKEN()
{
	if (CC == MARK)
	{
		EndToken = true;
	}
	else
	{
		SalinToken();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */


void SalinToken()
{
	// KAMUS
	int j;
	float N, number, numberdec;
	boolean minus;
	
		// ALGORITMA
		minus = false;
		if ((CC == '+') || ((CC == '-') && ((!IsCertainOperator(BeforeCC)))))
		{
			CToken.tkn = CC;
			CToken.val = 2;
			ADV();
		}
		else if ((CC == '*') || (CC == '/'))
		{
			CToken.tkn = CC;
			CToken.val = 1;
			ADV();
		}
		else if ((CC == '(') || (CC == ')'))
		{
			CToken.tkn = CC;
			CToken.val = 3;
			ADV();
		}
		else // bilangan bulat
		{
			if (CC == '-')
			{
				minus = true;
				ADV();
			}
			CToken.tkn = 'b';
			j = 1;
			number = 0;
			while ((j <= NMax) && (CC != MARK) && (CC != DEC) && (!IsOperator(CC)))
			{
				number = (number * 10) + (CC - '0');
				j++;
				ADV();
			}
			numberdec = 0;
			N = 10;
			if (CC == DEC)
			{
				ADV();
				while ((j <= NMax) && (CC != MARK) && (!IsOperator(CC)))
				{
					numberdec = numberdec + ((CC - '0') / N);
					j++;
					N *= 10;
					ADV();
				}
			}
			CToken.val = number + numberdec;
			if (minus)
			{
				CToken.val = -1 * CToken.val;
			}
		}
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi{} 
          CC = BLANK atau CC = MARK{} 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
		  

boolean IsCertainOperator (char C)
{
	return ((C == '+') || (C == '-') || (C == '*') || (C == '/') || (C == '('));
}

boolean IsOperator (char C)
{
	return ((C == '+') || (C == '-') || (C == '*') || (C == '/') || (C == '(') || (C == ')'));
}

boolean IsNumber (char C)
{
	return ((C == '0') || (C == '1') || (C == '2') || (C == '3') || (C == '4') || (C == '5') || (C == '6') || (C == '7') || (C == '8') || (C == '9'));
}
		  
boolean IsHigherPrecedence (Token T1, Token T2)
{
	// KAMUS
	
	
		// ALGORITMA
		if (T1.val < T2.val)
		{
			return (true);
		}
		else
		{
			return (false);
		}
}
/* T1 lebih tinggi prioritasnya dibanding T2
	I.S: Masukan sudah pasti bukan bilangan
	F.S: Bernilai true bila T1 lebih tinggi atau sama dengan T2 prioritasnya */
	
	
Token EksekusiOperator (Token T, Token op1, Token op2)
{
	// KAMUS
	Token Ans;
	
		// ALGORITMA
		Ans.tkn = 'b';
		if (T.tkn == '+')
		{
			Ans.val = op1.val + op2.val;
		}
		else if (T.tkn == '-')
		{
			Ans.val = op1.val - op2.val;
		}
		else if (T.tkn == '*')
		{
			Ans.val = op1.val * op2.val;
		}
		else if (T.tkn == '/')
		{
			Ans.val = op1.val / op2.val;
		}
		else
		{	
		}
		
		return (Ans);
}


void Perhitungan (Stack * SOperator, Stack * SAngka, boolean * math)
{
	// KAMUS
	Token T, op1, op2, hasil;
	
		// ALGORITMA
		Pop(SOperator, &T);
		Pop(SAngka, &op2);
		Pop(SAngka, &op1);
		if ((T.tkn == '/') && (op2.val == 0) && *math)
		{
			*math = false;
		}
		hasil = EksekusiOperator(T, op1, op2);
		Push(SAngka, hasil);
}