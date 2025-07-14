#include <stdio.h>

void toCOrNotToC()
{
    printf("To c or not to c? That is the question.\n");
}

// DO NOT USE COMMENTS

/*
THESE TOO
*/

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

    printf("Enter upc code: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1,
        &d2,
        &d3,
        &d4,
        &d5,
        &d6,
        &d7,
        &d8,
        &d9,
        &d10,
        &d11);

    int firstGroupSum = d1 + d3 + d5 + d7 + d9 + d11;
    int secondGroupSum = d2 + d4 + d6 + d8 + d10;
    int totalSum = firstGroupSum * 3 + secondGroupSum - 1;
    int dCheck = 9 - totalSum % 10;

    printf("Your check digit: %d\n", dCheck);
}

void brokerCommision()
{
    float value;

    printf("Enter trade value: ");
    scanf("%f", &value);

    float commision;

    if (value < 2500)
        commision = 30 + value * 0.017f;
    else if (value < 6250)
        commision = 56 + value * 0.0066f;
    else if (value < 20000)
        commision = 76 + value * 0.0034f;
    else if (value < 50000)
        commision = 100 + value * 0.0022f;
    else if (value < 500000)
        commision = 155 + value * 0.0011f;
    else
        commision = 255 + value * 0.0009f;

    if (commision < 39)
        commision = 39;

    printf("Commision: %.2f\n", commision);
}

void main()
{
    // toCOrNotToC();
    // largestNumbers();
    // shippingBoxes();
    // toCelcius();
    // upcCheckDigit();
    brokerCommision();
}