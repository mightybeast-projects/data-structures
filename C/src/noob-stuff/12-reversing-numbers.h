#include <stdio.h>

#define SIZE 5

void reversingNumbers(void)
{
    int a[SIZE];

    printf("Enter %d numbers: ", SIZE);

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");

    for (int i = SIZE - 1; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n");
}