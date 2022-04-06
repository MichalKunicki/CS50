#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;

    //Ask user for money owed.
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    //Converting cents to a round number
    int cents = round(change * 100);

    //Integer counting coins.
    int coins = 0;

    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }

    //Print amount of coins
    printf("%i\n", coins);
}