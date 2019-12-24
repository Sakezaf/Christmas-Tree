/* 
*------------------------------------------*
       Adding music to linux systems. 
*------------------------------------------*

This won't work on Windows, because I don't have a 
windows system to test Beep() on.

First compile beep.c with
gcc beep.c -o beep

Then you can run this :3

Make sure to use sudo to run, because the beeps.
Otherwise you get warnings instead of a song :D

Merry Christmas!

*------------------------------------------*
-Sakezaf
*------------------------------------------*


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/kd.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1B[37m"

#ifdef _unix_
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#define RED ""
#define GREEN ""
#define YELLOW ""
#define BLUE ""
#define MAGENTA ""
#define CYAN ""
#define RESET ""
#endif

#ifndef CLOCK_TICK_RATE
#define CLOCK_TICK_RATE 1193180
#endif

void clrscr()
{
    system("@cls||clear");
}

void printRandLeaf()
{
    char leaftypes[5] = {'.', '*', '+', 'o', 'O'};
    int temp = rand() % 4;

    if (temp == 1)
    {
        printRandColorOrnaments();
        printf("%c ", leaftypes[rand() % 5]);
        printf(RESET);
    }
    else
    {
        printRandColorLeaves();
        printf("%c ", leaftypes[1]);
        printf(RESET);
    }
}

void printRandSpace()
{
    char spacetypes[3] = {' ', '*', '+'};
    int temp = rand() % 10;

    if (temp == 1)

        printf("%c", spacetypes[rand() % 3]);

    else
        printf("%c", spacetypes[0]);
}

void printRandColorOrnaments()
{
    int temp = rand() % 7;

    switch (temp)
    {
    case 0:
        printf(RESET);
        break;
    case 1:
        printf(YELLOW);
        break;
    case 2:
        printf(BLUE);
        break;
    case 3:
        printf(CYAN);
        break;
    case 4:
        printf(YELLOW);
        break;
    case 5:
        printf(MAGENTA);
        break;
    default:
        printf(RED);
        break;
    }
}

void printRandColorLeaves()
{
    int temp = rand() % 3;

    switch (temp)
    {
    case 0:
        printf(RESET);
        break;

    default:
        printf(GREEN);
        break;
    }
}

void triangle(int f, int n, int toth)
{
    int i, j, k = 2 * toth - 2;

    for (i = 0; i < f - 1; i++)
        k--;

    for (i = f - 1; i < n; i++)
    {

        printf("*");

        for (j = 0; j < k; j++)
            printRandSpace();

        k = k - 1;

        for (j = 0; j <= i; j++)
            printRandLeaf();

        for (j = 0; j < k + 1; j++)
            printRandSpace();

        printf("*");

        printf("\n");
    }
}

void printTree(int h)
{
    int start = 1, stop = 0, diff = 3, i;

    for (i = 0; i < (h * 2) - 8; i++)
        printf(" ");

    printf("Merry Christmas!\n");

    for (i = 0; i < (h * 4); i++)
        printf("*");

    printf("\n");

    while (stop < h + 1)
    {
        stop = start + diff;
        triangle(start, stop, h);
        diff++;
        start = stop - 2;
    }
}

void printLog(int n)
{
    int i, j, k = 2 * n - 4;

    for (i = 1; i <= 4; i++)
    {
        printf("*");

        for (j = 0; j < k; j++)
            printRandSpace();

	printf("\x1b[47m");
        for (j = 1; j <= 6; j++)
            printf("#");
	printf("\x1b[m");

        for (j = 0; j < k; j++)
            printRandSpace();

        printf("*");

        printf("\n");
    }

    for (j = 0; j < (k * 2) + 8; j++)
        printf("*");

    printf("\n");
}

int main()
{
    srand(time(NULL));
    int ht = 20;
    printf(RESET);

    if(fork()== 0) {
        song();
    }

    while (1)
    {
        clrscr();

        printTree(ht);

        printLog(ht);

        sleep(1);
    }


    return 0;
}

void song() {
    int  i;

    char *C4[]={"./beep","-f 261","-l 600",NULL}; 
    char *D8[]={"./beep","-f 293","-l 300",NULL};
    char *e8[]={"./beep","-f 329","-l 300",NULL};
    char *f2[]={"./beep","-f 349","-l 1200",NULL}; 
    char *f4[]={"./beep","-f 349","-l 600",NULL}; 
    char *f8[]={"./beep","-f 349","-l 300",NULL}; 
    char *g4[]={"./beep","-f 394","-l 600",NULL};
    char *g8[]={"./beep","-f 394","-l 300",NULL}; 
    char *a4[]={"./beep","-f 440","-l 600",NULL}; 
    char *a8[]={"./beep","-f 440","-l 300",NULL};
    char *b8[]={"./beep","-f 466","-l 300",NULL};
    char *b4[]={"./beep","-f 466","-l 600",NULL}; 
    char *c2[]={"./beep","-f 523","-l 1200",NULL};
    char *c4[]={"./beep","-f 523","-l 600",NULL};
    char *c8[]={"./beep","-f 523","-l 300",NULL};
    char *d4[]={"./beep","-f 587","-l 600",NULL}; 
    char *d8[]={"./beep","-f 587","-l 300",NULL};
    
    while(1)
    {
        note(f4);
        note(f8);
        note(e8);
        note(f4);
        note(C4);

        note(a4);
        note(a8);
        note(g8);
        note(a4);
        note(f4);

        for(i = 0; i < 2; i++) {
            note(a4);
            note(d4);
            note(c2);
        }

        note(c4);
        note(c8);
        note(d8);
        note(c4);
        note(a4);

        note(b4);
        note(b8);
        note(c8);
        note(b4);
        note(g4);

        for(i = 0; i < 2; i++) {
            note(a4);
            note(g4);
            note(f2);
        }

    }
}

void note(char *note[]) {
    if(fork() == 0) {
        execv(note[0],note);
    }
    wait(NULL);
}

