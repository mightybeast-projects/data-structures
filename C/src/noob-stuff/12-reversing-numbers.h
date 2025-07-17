#include <stdio.h>

#define size 10

void reversingNumbers()
{
    int a[size];

    printf("Enter 10 numbers: ");

    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");

    for (int i = size - 1; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n");
}