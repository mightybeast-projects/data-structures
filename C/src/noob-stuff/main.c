#include <stdio.h>

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

#define INCHES_PER_POUND 166

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

#define FAHRENHEIT_OFFSET 32.0f

void toCelcius()
{
    float inFahrenheit;

    printf("Input temperature in Fagrenheit: ");
    scanf("%f", &inFahrenheit);

    printf("Temperature in Celsius: %.1f\n", inFahrenheit - FAHRENHEIT_OFFSET);
}

void upcCheckDigit()
{
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;

    printf("Enter type (first) digit: ");
    scanf("%1d", &d1);

    printf("Enter first group of upc digits: ");
    scanf("%1d%1d%1d%1d%1d", &d2, &d3, &d4, &d5, &d6);

    printf("Enter second group of upc digits: ");
    scanf("%1d%1d%1d%1d%1d", &d7, &d8, &d9, &d10, &d11);

    int firstGroupSum = d1 + d3 + d5 + d7 + d9 + d11;
    int secondGroupSum = d2 + d4 + d6 + d8 + d10;
    int totalSum = firstGroupSum * 3 + secondGroupSum - 1;
    int dCheck = 9 - totalSum % 10;

    printf("Your check digit: %d\n", dCheck);
}

void main()
{
    // toCOrNotToC();
    // largestNumbers();
    // shippingBoxes();
    // toCelcius();

    upcCheckDigit();
}

// DO NOT USE COMMENTS

/*
THESE TOO
*/