#include <stdio.h>

#define INCHES_PER_POUND 166

void shippingBoxes(void)
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