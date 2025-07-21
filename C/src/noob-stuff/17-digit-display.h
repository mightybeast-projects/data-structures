#include "stdio.h"

void displayDigit()
{
    // clang-format off
    char digitDisplay[5][10][6] = { 
        { " ___ ", "     ", " ___ ", " ___ ",  "    ", " ___ ", " ___ ", " ___ ", " ___ ", " ___ " },
        { "|   |", "    |", "    |", "    |", "|   |", "|    ", "|    ", "    |", "|   |", "|   |" },
        { "|   |", "    |", " ___|", " ___|", "|___|", "|___ ", "|___ ", "    |", "|___|", "|___|" },
        { "|   |", "    |", "|    ", "    |", "    |", "    |", "|   |", "    |", "|   |", "    |" },
        { "|___|", "    |", "|___ ", " ___|", "    |", " ___|", "|___|", "    |", "|___|", " ___|" }
    };
    // clang-format on

    int d;
    printf("Enter a number to display: ");
    scanf("%d", &d);

    for (int row = 0; row < 5; row++)
        printf("%s\n", digitDisplay[row][d]);
}