#include <stdio.h>

#define INCHES_PER_POUND 166;

void toCOrNotToC()
{
    printf("To c or not to c? That is the question.\n");

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
    int height, width, length;

    printf("Input box's height: ");
    scanf("%d", &height);

    printf("Input box's width: ");
    scanf("%d", &width);

    printf("Input box's length: ");
    scanf("%d", &length);

    float volume = height * width * length;
    float dimensionalWeight = volume / INCHES_PER_POUND;

    printf("Dimensions: %d, %d, %d\n", height, width, length);
    printf("Volume: %f\n", volume);
    printf("Dimensional weight: %f\n", dimensionalWeight);
}

int main()
{
    // toCOrNotToC();
    // largestNumbers();
    shippingBoxes();

    return 0;
}

// DO NOT USE COMMENTS

/*
THESE TOO
*/