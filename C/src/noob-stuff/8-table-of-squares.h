#pragma once
#include <stdio.h>

void tableOfSquares(void)
{
    int n;

    printf("Input number of squares :");
    scanf("%d", &n);

    int i = 1;

    while (i <= n)
    {
        printf("%d \t %d\n", i, i * i);
        i++;
    }
}