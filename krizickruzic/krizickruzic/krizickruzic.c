#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define Broj_Plocica 3
void Pocetno_stanje();
char Odabir_znaka(char igrac);
int main()
{
	int ploca[Broj_Plocica][Broj_Plocica];
	int brojevi[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 0;
	int igra;
	char igrac1='p', igrac2;
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
	}void Pocetno_stanje();
	/*while (kraj!=true)
	{
		for (int i = 0;i < 9;i++)

		{
		printf("upisi u koje mjesto ces staviti oznaku:\n");
		scanf("%d",&igra);
		
		
		
		
		}
	}*/
	Pocetno_stanje();
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
	


	return 0;
}


void Pocetno_stanje()
{
	printf("pocetno stanje ploce:\n");
	for (int i = 0; i < Broj_Plocica; i++)
	{
		for (int j = 0; j < Broj_Plocica; j++)
		{
			printf("I ");
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