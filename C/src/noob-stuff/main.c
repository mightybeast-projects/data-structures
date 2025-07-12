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

    float randomFloat = 30234.1226f;

    printf("%.2f is (not) the largest float.\n", randomFloat);
}

void shippingBoxes()
{
    int height = 12;
    int width = 3;
    int length = 6;
    float volume = height * width * length;
    float dimensionalWeight = volume / 166;

    printf("Dimensions: %d, %d, %d\n", height, width, length);
    printf("Volume: %f\n", volume);
    printf("Dimensional weight: %f\n", dimensionalWeight);
}

int main()
{
    toCOrNotToC();
    largestNumbers();
    shippingBoxes();

    return 0;
}

// DO NOT USE COMMENTS

/*
THESE TOO
*/