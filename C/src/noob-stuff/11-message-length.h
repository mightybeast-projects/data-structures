#include <stdio.h>

void messageLength()
{
    getchar();

    printf("Enter a message: ");

    int counter = 0;

    while (getchar() != '\n')
        counter++;

    printf("Your message was %d character(s) long.\n", counter);
}