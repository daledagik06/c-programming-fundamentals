#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Sleep(int ms)
{
    usleep(ms * 2000);
}

void cls()
{
    printf("\033[2J");
    printf("\033[H");
}

void gotoxy(int r,int c)
{
    printf("\033[%d;%dH", r, c);
}

void borderColor()
{
    printf("\033[1;92m");
}

void pColor()
{
    printf("\033[1;91m");
}

void dColor()
{
    printf("\033[1;93m");
}

void sColor()
{
    printf("\033[1;94m");
}

void textColor()
{
    printf("\033[1;97m");
}

void lineHorizontal(int row,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        gotoxy(row,i);
        printf("#");
        fflush(stdout);
        Sleep(8);
    }
}

void lineVertical(int col,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        gotoxy(i,col);
        printf("#");
        fflush(stdout);
        Sleep(8);
    }
}

void drawBorder()
{
    borderColor();

    lineHorizontal(4,18,95);
    lineHorizontal(24,18,95);
    lineVertical(18,4,24);
    lineVertical(95,4,24);
}

void drawP()
{
    pColor();

    for(int i=8;i<=19;i++)
    {
        gotoxy(i,28);
        printf("##");
        fflush(stdout);
        Sleep(12);
    }

    lineHorizontal(8,28,38);
    lineHorizontal(13,28,38);

    for(int i=9;i<=12;i++)
    {
        gotoxy(i,38);
        printf("##");
        fflush(stdout);
        Sleep(12);
    }
}

void drawD()
{
    dColor();

    for(int i=8;i<=19;i++)
    {
        gotoxy(i,50);
        printf("##");
        fflush(stdout);
        Sleep(12);
    }

    lineHorizontal(8,50,60);
    lineHorizontal(19,50,60);

    for(int i=9;i<=18;i++)
    {
        gotoxy(i,60);
        printf("##");
        fflush(stdout);
        Sleep(12);
    }
}

void drawS()
{
    sColor();

    lineHorizontal(8,72,84);

    for(int i=9;i<=12;i++)
    {
        gotoxy(i,72);
        printf("##");
        fflush(stdout);
        Sleep(12);
    }

    lineHorizontal(13,72,84);

    for(int i=14;i<=18;i++)
    {
        gotoxy(i,84);
        printf("##");
        fflush(stdout);
        Sleep(12);
    }

    lineHorizontal(19,72,84);
}

void titleText()
{
    textColor();

    gotoxy(6,53);
    printf("GROUP 3");

    gotoxy(24,42);
    printf("DALE SOBREVINAS");

    gotoxy(25,42);
    printf("PRESS ENTER TO CONTINUE");
}

void splash()
{
    cls();

    drawBorder();
    drawP();
    drawD();
    drawS();
    titleText();

    printf("\033[0m");
    getchar(); 
}

int main()
{
    splash();
    return 0;
}