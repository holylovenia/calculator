/*	
	KELAS 02
	Oktavianus Handika / 13515035
	Holy Lovenia / 13515113
*/



/* LIBRARY */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackt.h"
#include "mesintoken.h"
#include "boolean.h"



/* FUNGSI DAN PROSEDUR */

boolean isNumber (char c);
/*Fungsi mengembalikan true apabila character merupakan angka 0 sampai dengan 9*/

boolean isPlus (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda tambah*/

boolean isSubtract (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda kurang*/

boolean isMultiple (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda kali*/

boolean isDivide (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda bagi*/

boolean isLeftParent (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda kurung buka*/

boolean isRightParent (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda kurung tutup*/

boolean isDecimal (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda koma desimal*/

boolean isEnd (char c);
/*Fungsi mengembalikan true apabila character merupakan tanda sama dengan*/

boolean validate (char* input);
/*Fungsi mengembalikan true apabila sintaks input string valid sesuai aturan ekspresi aritmatika*/

void calculate(Stack SOperator, Stack SAngka, Token hasil, Token T);
/* Prosedur untuk mengkalkulasi ekspresi matematika yang valid */



/* MAIN PROGRAM */

int main ()
{
	// KAMUS
	boolean syntax;
	char input[NMax];
	FILE *fp;
	Stack SOperator1, SAngka1;
	Token hasil1;
	Token T1;
	
		// ALGORITMA
		printf("Masukkan ekspresi aritmatika (bubuhkan tanda '=' di akhir ekspresi): \n");
		scanf("%[^\n]s",input);
		syntax = validate(input); 
		if (input[strlen(input) - 1] != '=')
		{
			printf("Tidak ada tanda sama dengan pada akhir ekspresi\n");
		}else
		{
			if (syntax)
			{
				
				fp = fopen("../bin/input.txt", "w");
				fprintf(fp, "%s", input);
				fclose(fp);
				calculate(SOperator1,SAngka1,hasil1,T1);

			} else
			{
				printf("SYNTAX ERROR\n");
			}
		}
		return 0;
}



/* FUNGSI DAN PROSEDUR */

boolean isNumber (char c)
/*Fungsi mengembalikan true apabila character merupakan angka 0 sampai dengan 9*/
{
	return ((c >= '0') && (c <= '9'));
}

boolean isPlus (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda tambah*/
{
	return (c == '+');
}

boolean isSubtract (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda kurang*/
{
	return (c == '-');
}

boolean isMultiple (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda kali*/
{
	return (c == '*');
}

boolean isDivide (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda bagi*/
{
	return (c == '/');
}

boolean isLeftParent (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda kurung buka*/
{
	return (c == '(');
}

boolean isRightParent (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda kurung tutup*/
{
	return (c == ')');
}

boolean isDecimal (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda koma desimal*/
{
	return (c == '.');
}

boolean isEnd (char c)
/*Fungsi mengembalikan true apabila character merupakan tanda sama dengan*/
{
	return (c == '=');
}

boolean validate (char* input)
/*Fungsi mengembalikan true apabila sintaks input string valid sesuai aturan ekspresi aritmatika*/
{
	//KAMUS
	boolean X = true;
	boolean dec = false;
	boolean end = false;
	boolean symbol2 = false;
	int left = 0;
	int right = 0;
	int i = 0;
	//ALGORITMA
	if (isLeftParent(input[i]) || isNumber(input[i]) || isPlus(input[i]) || isSubtract(input[i]))
	{
		if (isLeftParent(input[i]))
		{
			left++;
		} else if ((isPlus(input[i]) || isSubtract(input[i])) && (isPlus(input[i+1]) || isSubtract(input[i+1]) || isMultiple(input[i+1]) || isDivide(input[i+1])))
		{
			X = false;
		}
		i++;
		while (X && !end)
		{
			if (isLeftParent(input[i]) && (isNumber(input[i+1]) || isLeftParent(input[i+1]) || isSubtract(input[i+1])))
			{left++; symbol2 = false;} else if (isRightParent(input[i]) && (isPlus(input[i+1]) || isSubtract(input[i+1]) || isMultiple(input[i+1]) || isDivide(input[i+1]) || isRightParent(input[i+1])))
			{right++; symbol2 = false;} else if (isDecimal(input[i]) && isNumber(input[i+1]))
			{symbol2 = false;} else if (isNumber(input[i]) && (isPlus(input[i+1]) || isSubtract(input[i+1]) || isMultiple(input[i+1]) || isDivide(input[i+1]) || isRightParent(input[i+1]) || isNumber(input[i+1])))
			{dec = false; symbol2 = false;} else if (isNumber(input[i]) && isDecimal(input[i+1]) && (!dec))
			{dec = true; symbol2 = false;} else if (!symbol2 && isPlus(input[i]) && (isNumber(input[i+1]) || isLeftParent(input[i+1]) || isSubtract(input[i+1]) || isPlus(input[i+1])))
			{} else if (!symbol2 && isSubtract(input[i]) && (isNumber(input[i+1]) || isLeftParent(input[i+1]) || isPlus(input[i+1]) || isSubtract(input[i+1])))
			{} else if (!symbol2 && isMultiple(input[i]) && (isNumber(input[i+1]) || isLeftParent(input[i+1]) || isPlus(input[i+1]) || isSubtract(input[i+1])))
			{} else if (!symbol2 && isDivide(input[i]) && (isNumber(input[i+1]) || isLeftParent(input[i+1]) || isPlus(input[i+1]) || isSubtract(input[i+1])))
			{} else if ((isLeftParent(input[i]) || isRightParent(input[i]) || isNumber(input[i])) && isEnd(input[i+1]))
			{	if (isLeftParent(input[i]))
				{
					left++;
				} else if (isRightParent(input[i]))
				{
					right++;
				}
				if (left == right)
				{ 
					end = true;
				}
				else
				{
					X = false;
				}
			} else
			{X = false;}
			if ((isPlus(input[i-1]) || isSubtract(input[i-1]) || isMultiple(input[i-1]) || isDivide(input[i-1])) && (isPlus(input[i]) || isSubtract(input[i])))
			{symbol2 = true;}
			i++;
		}
	} else
	{
		X = false;
	}
	return X;
}

void calculate(Stack SOperator, Stack SAngka, Token hasil, Token T)
/* Prosedur untuk mengkalkulasi ekspresi matematika yang valid */
	{
		boolean math = true;
		// ALGORITMA
		
		CreateEmpty(&SOperator);
		CreateEmpty(&SAngka);
		
		STARTTOKEN();
		while (!EndToken)
		{
			if (CToken.tkn == 'b')
			{
				printf("%f", CToken.val);
				Push(&SAngka, CToken);
			}
			else
			{
				printf("%c", CToken.tkn);
				if (!IsEmpty(SOperator))
				{
					if (IsHigherPrecedence(CToken, InfoTop(SOperator)))
					{
						Push(&SOperator, CToken);
					}
					else // yang mau dimasukkin lower precedence
					{
						if (CToken.tkn == ')')
						{
							while (InfoTop(SOperator).tkn != '(')
							{
								Perhitungan(&SOperator, &SAngka, &math);
							}
							Pop(&SOperator, &T);
						}
						else
						{
							if (CToken.tkn != '(')
							{
								Perhitungan(&SOperator, &SAngka, &math);
							}
							Push(&SOperator, CToken);
						}
					}
				}
				else // IsEmpty(SOperator)
				{
					Push(&SOperator, CToken);
				}
			}
			ADVTOKEN();
		}
		
		// EndToken, kosongin stack
		while (!IsEmpty(SOperator))
		{
			Perhitungan(&SOperator, &SAngka, &math);
		}
		
		// Stack Operator kosong
		Pop(&SAngka, &hasil);
		if (!math)
		{
			printf("\n\nMATH ERROR\n");
		} else
		{
			printf("\n\nHasil: %f\n", hasil.val);
		}
}

