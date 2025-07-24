#include <stdio.h>

void interestRates(void)
{
    float deposit;
    printf("Enter deposit: ");
    scanf("%f", &deposit);

    int rate;
    printf("Enter interest rate: ");
    scanf("%d", &rate);

    int years;
    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("Years");

    for (int i = rate; i <= rate + 4; i++)
        printf("\t%d%%", i);

    printf("\n");

    for (int i = 1; i <= years; i++)
    {
        printf("%d", i);

        for (int j = rate; j <= rate + 4; j++)
        {
            float sum = deposit;

            for (int k = 0; k < i; k++)
                sum *= (1.0 + j / 100.0);

            printf("\t%.2f", sum);
        }

        printf("\n");
    }

    printf("\n");
}