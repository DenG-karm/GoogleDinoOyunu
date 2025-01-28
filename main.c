#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <iostream>
void moveto(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void pause(unsigned int milliseconds) {
    clock_t goal = milliseconds + clock();
    while (goal > clock()) ;
}

void displaygameinfo() {
    system("cls");
    moveto(10,2);
    printf("Cikis icin X,Ziplamak icin Space");
    moveto(62,2);
    printf("SKOR : ");
    moveto(1,25);
    for (int x = 0; x<79; x++)
        printf("n");
}
    int jumpheight,gamespeed = 40;


void displaycharacter(int jumptype = 0) {
    static int animationstate = 1;

    if (jumptype == 0)
        jumpheight = 0;
    else if (jumptype == 2)
        jumpheight--;
    else
        jumpheight++;



    moveto(2, 15 - jumpheight);
    printf("                ");
    moveto(2, 16 - jumpheight);
    printf("     мллл      ");
    moveto(2, 17 - jumpheight);
    printf("    ллллллл     ");
    moveto(2, 18 - jumpheight);
    printf("   ллллллллл    ");
    moveto(2, 19 - jumpheight);
    printf("  лллллплллл   ");
    moveto(2, 20 - jumpheight);
    printf(" млллллппллллм  ");
    moveto(2, 21 - jumpheight);
    printf(" ллллллпплллллл ");
    moveto(2, 22 - jumpheight);
    printf(" пллллллппллллп ");
    moveto(2, 23 - jumpheight);

    if (jumptype == 1 || jumptype == 2) {
        printf("   ллп плпппл   ");
        moveto(2, 24 - jumpheight);
        printf("   лм   лм      ");
    }
    else if ( animationstate == 1) {
        printf("  пллп  ппп     ");
        moveto(2, 24 - jumpheight);
        printf("     лм         ");
        animationstate = 2;
    }
    else if ( animationstate == 2) {
        printf("   плм пл       ");
        moveto(2, 24 - jumpheight);
        printf("         лм     ");
        animationstate = 1;
    }
    moveto(2,25-jumpheight);
    if (jumptype != 0) {
        printf("                   ");
    }
    else {
        printf("ппппппппппппппппп");
    }
    pause(gamespeed);
}

void displayObstacle() {
    static int obstacleposition = 0,score=0;

    if (obstacleposition==56 && jumpheight<4) {
        score =0;
        gamespeed=40;
        moveto(36,8);
        printf("Oyun bitti!");
        getch();
        moveto(36,8);
        printf("           ");
    }
    moveto(74 - obstacleposition,20);
    printf("л    л ");
    obstacleposition++;
    if (obstacleposition==73) {
        obstacleposition=0;
        score++;
        moveto(70,2);
        printf("        ");
        moveto(70,2);
        printf("%d",score);
        if (gamespeed > 20)
            gamespeed--;
    }
}

int main() {
    system("mode con: lines=29 cols=82");
    char input;
    int i;
    displaygameinfo();

    while(true) {
        while (!kbhit()) {
            displaycharacter();
            displayObstacle();
        }
        input=getch();
        if (input== ' ') {
            for (i =0; i<10; i++) {
                displaycharacter(1);
                displayObstacle();
            }
            for (i =0; i<10; i++) {
                displaycharacter(2);
                displayObstacle();
            }
        }
        else if (input== 'x') {
            return (0);
        }
    }
    return 0;
}


