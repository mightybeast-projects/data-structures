#include <stdbool.h>
#include <stdio.h>

void toCOrNotToC()
{
    printf("To c or not to c? That is the question.\n");

    bool toC = true;
    bool notToC = false;

    if (toC || notToC)
        printf("Look at the code for answer.\n");

    return;
}

void largestNumbers()
{
    int randomInt = 2147483;

    printf("%d is (not) the largest int.\n", randomInt);

    float randomFloat = 30234.12f;

    printf("%f is (not) the largest float.\n", randomFloat);
}

int main()
{
    toCOrNotToC();
    largestNumbers();

    return 0;
}

// DO NOT USE COMMENTS

/*
THESE TOO
*/