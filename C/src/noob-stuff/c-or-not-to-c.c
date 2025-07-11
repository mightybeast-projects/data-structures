#include <stdbool.h>
#include <stdio.h>

int main()
{
    toCOrNotToC();

    return 0;
}

void toCOrNotToC()
{
    printf("to c or not to c \n");
    printf("that is the question. \n");

    bool toC = true;
    bool notToC = false;

    if (toC)
        printf("just c already \n");

    if (notToC)
        printf("nah man, do not c \n");
}