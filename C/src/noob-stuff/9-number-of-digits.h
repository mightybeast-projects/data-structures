#include <stdio.h>

void numberOfDigits()
{
    int n;

    printf("Input integer number: ");
    scanf("%d", &n);

    int digits = 0;

    do
    {
        n /= 10;
        digits++;
    } while (n % 10 > 0);

    printf("Number has %d digits.\n", digits);
}