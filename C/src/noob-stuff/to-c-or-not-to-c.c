#include <stdbool.h>
#include <stdio.h>

void toCOrNotToC()
{
    printf("To c or not to c; \n");
    printf("That is the question. \n");

    bool toC = true;
    bool notToC = false;

    if (toC || notToC)
        printf("Good question... \n");

    return;
}

int main()
{
    toCOrNotToC();

    return 0;
}