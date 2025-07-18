#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateNumber();
void promptForRestart();

void guessTheNumber()
{
    srand(time(NULL));

    printf("Guess the secret number between 1 and 100.\n");

    generateNumber();
}

void generateNumber()
{
    int n = rand() % 100;

    printf("A new number has been chosen.\n");

    int guess, guessCount = 0;

    while (guess != n)
    {
        printf("Enter guess: ");
        scanf("%d", &guess);

        if (guess > n)
            printf("Too high; try again.\n");
        if (guess < n)
            printf("Too low; try again.\n");

        guessCount++;
    }

    printf("You won in %d guesses!\n", guessCount);

    promptForRestart();
}

void promptForRestart()
{
    printf("Play again? (Y/N): ");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y')
        generateNumber();
    else if (answer == 'n' || answer == 'N')
        return;
    else
        promptForRestart();
}