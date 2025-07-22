#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS_SIZE 4
#define RANKS_SIZE 13

void handOfCards()
{
    int n;
    printf("Enter number of cards in hand: ");
    scanf("%d", &n);

    const char suits[4] = { 'h', 'c', 'd', 's' };
    const char ranks[13]
        = { '2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a' };

    printf("Your hand:");

    bool inHand[SUITS_SIZE][RANKS_SIZE] = { false };

    srand(time(NULL));

    while (n > 0)
    {
        const int suitsR = rand() % SUITS_SIZE;
        const int ranksR = rand() % RANKS_SIZE;

        if (inHand[suitsR][ranksR])
            continue;

        printf(" %c%c", ranks[ranksR], suits[suitsR]);

        inHand[suitsR][ranksR] = true;

        n--;
    }

    printf("\n");
}