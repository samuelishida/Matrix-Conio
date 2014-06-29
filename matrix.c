#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>//for Sleep(), but it can be replaced depending on the OS
#include<conio2.h>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

char lista[50];
short cont = 0;

struct posicoes
{
    short x;
    short y;
    short tam;

}pos[400];

void preenche_lista()
{
    int i, j;

    for(i=0, j=97; j<=122; j++, i++)
        lista[i] = j;

    for(j=35; j<=38; j++, i++)
        lista[i] = j;

    for(j=48; j<=57; j++, i++)
        lista[i] = j;
}

void matrix()
{
    int x, y, x1, y1, ch, i, j;

    ch = rand() % 40 + 10;

    for(i=0; i<400; i++)
    {
        if(pos[i].tam == NULL) break;

        else if(pos[i].y >= pos[i].tam)
        {
            for(j=i; j<399; j++)
            {
                pos[j] = pos[j+1];
            }
            cont--;
        }

        textcolor(LIGHTGREEN);
        gotoxy(pos[i].x, pos[i].y);
        printf("%c", lista[ch+1]);

        gotoxy(pos[i].x, ++pos[i].y);
        textcolor(WHITE);
        printf("%c", lista[ch]);
    }

    gotoxy(1,1);
    insline();

    if(cont != 0)
    {
        for(i=0; i<cont; i++)
            pos[i].y++;
    }

    x = pos[cont].x = rand() % 80 + 1;
    y = pos[cont].y = rand() % 50 + 1;

    pos[cont].tam = rand() % 30 + 20;

    cont++;

    gotoxy(x,y);
    textcolor(LIGHTGREEN);
    printf("%c", lista[ch]);

    //Sleep(30);
}

int main()
{
    int i;
    for(i=0; i<400; i++)
        pos[i].tam = NULL;
    preenche_lista();
	textcolor(LIGHTGREEN);
	clrscr();
	gotoxy(80,25);
	srand(time(NULL));
	while(1)
	{
	    matrix();
	}
    getch();
	clrscr();
}
