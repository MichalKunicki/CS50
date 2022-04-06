#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int answer, rows, columns, spaces;
    do
    {
        //Prompt user for integer 1-8 defining height of the pyramid.
        answer = get_int("Height: ");
    }
    while (answer < 1 || answer > 8);

    for (rows = 0; rows < answer; rows++)
    {
        for (spaces = 0; spaces < answer - rows - 1; spaces++)
        {
            //Printing spaces in front of hashes to make the pyramid right-oriented.
            printf(" ");
        }
        for (columns = 0; columns <= rows; columns++)
        {
            // Printing hashes
            printf("#");
        }
        //Printing rows
        printf("\n");
    }
}
