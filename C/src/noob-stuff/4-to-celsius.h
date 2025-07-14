#include <stdio.h>

#define FAHRENHEIT_OFFSET 32.0f

void toCelcius()
{
    float inFahrenheit;

    printf("Input temperature in Fagrenheit: ");
    scanf("%f", &inFahrenheit);

    printf("Temperature in Celsius: %.1f\n", inFahrenheit - FAHRENHEIT_OFFSET);
}