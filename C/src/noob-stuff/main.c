#include "1-to-c-or-not-to-c.h"
#include "2-largest-numbers.h"
#include "3-shipping-boxes.h"
#include "4-to-celsius.h"
#include "5-upc-check-digit.h"
#include "6-broker-commision.h"
#include "7-legal-date-format.h"
#include <stdio.h>

void main()
{
    int id;

    printf("Enter program id (1 - 7): ");
    scanf("%d", &id);

    switch (id)
    {
    case 1:
        toCOrNotToC();
        break;
    case 2:
        largestNumbers();
        break;
    case 3:
        shippingBoxes();
        break;
    case 4:
        toCelcius();
        break;
    case 5:
        upcCheckDigit();
        break;
    case 6:
        brokerCommision();
        break;
    case 7:
        legalDateFormat();
        break;
    }
}