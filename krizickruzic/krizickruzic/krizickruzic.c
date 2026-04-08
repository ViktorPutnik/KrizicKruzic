#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define N 3

void inicijalizacija(char ploca[N][N]);
void crtanje(char ploca[N][N], int x, int y);
int provjera_pobjede(char ploca[N][N]);

int main()
{
    char ploca[N][N];
    int x = 0, y = 0;
    char igrac = 'X';
    bool game_over = false;
    int potezi = 0;

    inicijalizacija(ploca);

    while (!game_over)
    {
        system("cls");

        crtanje(ploca, x, y);
        printf("\nNa potezu: %c\n", igrac);
        printf("SPACE = postavi znak\n\n\n\n");

        int ch = _getch();

        // STRELICE
        if (ch == 224)
        {
            ch = _getch();

            switch (ch)
            {
            case 72: if (x > 0) x--; break;         // gore
            case 80: if (x < N - 1) x++; break;     // dolje
            case 75: if (y > 0) y--; break;         // lijevo
            case 77: if (y < N - 1) y++; break;     // desno
            }
        }

        // SPACE
        else if (ch == ' ')
        {
            if (ploca[x][y] == ' ')
            {
                ploca[x][y] = igrac;
                potezi++;

                // provjera pobjede
                int rez = provjera_pobjede(ploca);
                if (rez != 0)
                {
					system("cls");
                    crtanje(ploca, x, y);
                    printf("\nPobjednik: %c\n", igrac);
                    game_over = true;
                    break;
                }

                // neriješeno
                if (potezi == 9)
                {
					system("cls");
                    crtanje(ploca, x, y);
                    printf("\nNerijeseno!\n");
                    game_over = true;
                    break;
                }

                // promjena igraca
                igrac = (igrac == 'X') ? 'O' : 'X';
            }
        }

        // ESC za izlaz
        else if (ch == 27)
        {
            break;
        }
    }

    return 0;
}

// inicijalizacija ploce
void inicijalizacija(char ploca[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ploca[i][j] = ' ';
}

// crtanje ploce
void crtanje(char ploca[N][N], int x, int y)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == x && j == y)
                printf("[%c]", ploca[i][j]);
            else
                printf(" %c ", ploca[i][j]);

            if (j < N - 1) printf("|");
        }
        printf("\n");
        if (i < N - 1) printf("---+---+---\n");
    }
}

// provjera pobjede
int provjera_pobjede(char b[N][N])
{
    // redovi
    for (int i = 0; i < N; i++)
        if (b[i][0] != ' ' && b[i][0] == b[i][1] && b[i][1] == b[i][2])
            return 1;

    // stupci
    for (int i = 0; i < N; i++)
        if (b[0][i] != ' ' && b[0][i] == b[1][i] && b[1][i] == b[2][i])
            return 1;

    // dijagonale
    if (b[0][0] != ' ' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
        return 1;

    if (b[0][2] != ' ' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
        return 1;

    return 0;
}