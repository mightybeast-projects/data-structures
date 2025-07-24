#include "stdio.h"
#include "string.h"

#define INPUT_SIZE 100

void displayDigit(void)
{
    // clang-format off
    char digitDisplay[5][10][6] = { 
        { " ___ ", "     ", " ___ ", " ___ ", "     ", " ___ ", " ___ ", " ___ ", " ___ ", " ___ " },
        { "|   |", "    |", "    |", "    |", "|   |", "|    ", "|    ", "    |", "|   |", "|   |" },
        { "|   |", "    |", " ___|", " ___|", "|___|", "|___ ", "|___ ", "    |", "|___|", "|___|" },
        { "|   |", "    |", "|    ", "    |", "    |", "    |", "|   |", "    |", "|   |", "    |" },
        { "|___|", "    |", "|___ ", " ___|", "    |", " ___|", "|___|", "    |", "|___|", " ___|" }
    };
    // clang-format on

    char input[INPUT_SIZE + 1];

    printf("Enter a number to display: ");
    scanf("%s", input);

    int length = strlen(input);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < length; j++)
        {
            int digit = input[j] - '0';

            printf("%s ", digitDisplay[i][digit]);
        }

        printf("\n");
    }
}