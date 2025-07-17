#include <stdbool.h>
#include <stdio.h>

void repeatedDigits()
{
    bool repeated[10] = { false };
    bool seen[10] = { false };

    printf("Enter a number: ");

    long int number;
    scanf("%ld", &number);

    while (number % 10 > 0)
    {
        int digit = number % 10;

        if (seen[digit])
            repeated[digit] = true;
        else
            seen[digit] = true;

        number /= 10;
    }

    printf("Repeated digits:");

    for (int i = 0; i < 10; i++)
        if (repeated[i])
            printf(" %d", i);

    printf("\n");
}