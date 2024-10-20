#define _CRT_SECURE_NO_WARNINGS
#define clrscr() printf("\e[1;1H\e[2J")
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#define Broj_Plocica 3
void Pocetno_stanje(int ploca[Broj_Plocica][Broj_Plocica]);
char Odabir_znaka(char igrac);
void Postava_Ploce(int ciji_potez,int potezi, int x[Broj_Plocica][Broj_Plocica]);
void Tijekom_Igre(int ploca[Broj_Plocica][Broj_Plocica]);
int evaluate(char b[3][3]);
	
int main()
{
	int ploca[Broj_Plocica][Broj_Plocica];

	int k = 0, potezi = 0,b=0;
	char igrac1='p', igrac2,Pobjeda='o';
	bool kraj = false;
	igrac1 = Odabir_znaka(igrac1);
		switch (igrac1)
		{
		case 'X':
			igrac2 = 'O';
			break;
		case 'O':
			igrac2 = 'X';
			break;
		}
	Pocetno_stanje(ploca);
	for (int i = 1; i < 10; i++)
	{
		
       Postava_Ploce(i, potezi, ploca);
	   Tijekom_Igre(ploca);
	   if (i > 4)
	   {
		   b = evaluate(ploca);
		   printf("%d", b);
		   switch (b)
		   {

		   case 10:
			   printf("prvi igrac je pobjednik\n");
			   kraj = true;
			   break;
		   case -10:
			   printf("drugi igrac je pobjednik\n");
			   kraj = true;
			   break;
		   default:

			   Tijekom_Igre(ploca);
			   break;

		   }
	   }
	}
	

	
	


	return 0;
}
void Tijekom_Igre(int ploca[][Broj_Plocica])
{

	for (int i = 0; i < Broj_Plocica; i++)
	{
		for (int j = 0; j < Broj_Plocica; j++)
		{
			printf("%d ", ploca[i][j]);
		}
		printf("\n");
	}
}

int evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory. 
	for (int row = 0; row < 3; row++) {
		if (b[row][0] == b[row][1]
			&& b[row][1] == b[row][2]) {
			if (b[row][0] == 10)
				return +10;
			else if (b[row][0] == 20)
				return -10;
		}
	}

	// Checking for Columns for X or O victory. 
	for (int col = 0; col < 3; col++) {
		if (b[0][col] == b[1][col]
			&& b[1][col] == b[2][col]) {
			if (b[0][col] == 10)
				return +10;

			else if (b[0][col] == 20)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory. 
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
		if (b[0][0] == 10)
			return +10;
		else if (b[0][0] == 20)
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
		if (b[0][2] == 10)
			return +10;
		else if (b[0][2] == 20)
			return -10;
	}

	// Else if none of them have won then return 0 
	return 0;
}





void Postava_Ploce(int ciji_potez,int potezi, int ploca[][Broj_Plocica])
{
	int pozicije = 1;
	if (ciji_potez % 2 == 0 || ciji_potez == 1)
	{
		printf("1. igrac neka postavi oznaku na zeljeno mjesto\n");
		if (pozicije > 0 && pozicije < 9)
		{
			scanf("%d", &pozicije);
			for (int i = 0; i < Broj_Plocica; i++)
			{
				for (int j = 0; j < Broj_Plocica; j++)
				{
					if (pozicije == ploca[i][j])
					{
						ploca[i][j] = 10;
					}
				}

			}
		}
		else
		{
			printf("nedozvoljen broj upisan\n");
			ciji_potez--;
		 
		}
	}
	else
	{
		printf("2. igrac neka postavi oznaku na zeljeno mjesto\n");
		if (pozicije > 0 && pozicije < 9)
		{
			scanf("%d", &pozicije);
			for (int i = 0; i < Broj_Plocica; i++)
			{
				for (int j = 0; j < Broj_Plocica; j++)
				{
					if (pozicije == ploca[i][j])
					{
						ploca[i][j] = 20;
					}
				}

			}
		}
		else
		{
			printf("nedozvoljen broj upisan\n");
			ciji_potez--;

		}
	}
	
}
void Pocetno_stanje(int ploca[Broj_Plocica][Broj_Plocica])
{
	int brojevi[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 0;
	printf("pocetno stanje ploce:\n");
	for (int i = 0; i < Broj_Plocica; i++)
	{
		for (int j = 0; j < Broj_Plocica; j++)
		{
			printf("I ");
		}
		printf("\n");
	}
	for (int i = 0; i < Broj_Plocica; i++)
	{
		for (int j = 0; j < Broj_Plocica; j++)
		{
			ploca[i][j] = brojevi[k];
			++k;
		}
	}
	printf("polozaj brojeva na ploci:\n");
	for (int i = 0; i < Broj_Plocica; i++)
	{
		for (int j = 0; j < Broj_Plocica; j++)
		{
			
				printf("%d ", ploca[i][j]);
			
			
		}
		printf("\n");
	}

}



char Odabir_znaka(char igrac)
{
	do
	{
		printf("upisi simbol 1. igraca:\n");
		scanf("	%c", &igrac);
		if (igrac != 'X' && igrac != 'O')
			printf("niste unijeli tocan znak: pokusaj ponovo\n");
	} while (igrac != 'X' && igrac != 'O');
	return igrac;
}