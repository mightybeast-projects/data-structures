#include <stdio.h>

#include "1-to-c-or-not-to-c.h"
#include "10-types-limits.h"
#include "11-message-length.h"
#include "12-reversing-numbers.h"
#include "13-repeated-digits.h"
#include "14-interest-rates.h"
#include "15-hand-of-cards.h"
#include "2-largest-numbers.h"
#include "3-shipping-boxes.h"
#include "4-to-celsius.h"
#include "5-upc-check-digit.h"
#include "6-broker-commision.h"
#include "7-legal-date-format.h"
#include "8-table-of-squares.h"
#include "9-number-of-digits.h"
#include "main.h"

void main()
{
    printDescriptions();
    scanAndRunSelectedProgram();
}

void printDescriptions()
{
    printf("1 - To C or not to C\n");
    printf("2 - 'Largest' numbers\n");
    printf("3 - Shipping boxes\n");
    printf("4 - To Celsius\n");
    printf("5 - UPS check digit\n");
    printf("6 - Broker commision\n");
    printf("7 - Legal date format\n");
    printf("8 - Table of squares\n");
    printf("9 - Number of digits\n");
    printf("10 - Types limits\n");
    printf("11 - Message length\n");
    printf("12 - Reversing numbers\n");
    printf("13 - Repeated digits\n");
    printf("14 - Interest rates\n");
    printf("15 - Hand of cards\n");
}

void scanAndRunSelectedProgram()
{
    printf("Enter program id: ");

    int id;
    scanf("%d", &id);
    printf("---------------------\n");

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
    case 8:
        tableOfSquares();
        break;
    case 9:
        numberOfDigits();
        break;
    case 10:
        typesLimits();
        break;
    case 11:
        messageLength();
        break;
    case 12:
        reversingNumbers();
        break;
    case 13:
        repeatedDigits();
        break;
    case 14:
        interestRates();
        break;
    case 15:
        handOfCards();
        break;
    }
}