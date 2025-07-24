#include <stdio.h>

void upcCheckDigit(void)
{
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;

    printf("Enter upc code: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1,
        &d2,
        &d3,
        &d4,
        &d5,
        &d6,
        &d7,
        &d8,
        &d9,
        &d10,
        &d11);

    int firstGroupSum = d1 + d3 + d5 + d7 + d9 + d11;
    int secondGroupSum = d2 + d4 + d6 + d8 + d10;
    int totalSum = firstGroupSum * 3 + secondGroupSum - 1;
    int dCheck = 9 - totalSum % 10;

    printf("Your check digit: %d\n", dCheck);
}