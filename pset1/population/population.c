#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int population1, population2;
    // TODO: Prompt for start size
    do
    {
        population1 = get_int("Starting population size: ");
    }
    while (population1 < 9);

    // TODO: Prompt for end size
    do
    {
        population2 = get_int("End population size: ");
    }
    while (population2 < population1);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;

    while (population1 < population2)
    {
        population1 = population1 + (population1 / 3) - (population1 / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}