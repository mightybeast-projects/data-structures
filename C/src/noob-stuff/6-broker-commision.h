#include <stdio.h>

void brokerCommision(void)
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