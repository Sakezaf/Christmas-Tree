#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifdef _unix_
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

void clrscr()
{
    system("@cls||clear");
}

void printRandLeaf()
{
    char leaftypes[5] = {'.', '*', '+', 'o', 'O'};
    int temp = rand() % 4;

    // Giving preference to *
    if (temp == 1)
        printf("%c ", leaftypes[rand() % 5]);
    else
        printf("%c ", leaftypes[1]);
}

void printRandSpace()
{
    char spacetypes[3] = {' ', '*', '+'};
    int temp = rand() % 10;

    // Giving preference to *
    if (temp == 1)
        printf("%c", spacetypes[rand() % 3]);
    else
        printf("%c", spacetypes[0]);
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

        for (j = 1; j <= 6; j++)
            printf("#");

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

    while (1)
    {
        clrscr();

        printTree(ht);

        printLog(ht);

        sleep(1);
    }

    return 0;
}