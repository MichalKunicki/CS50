#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Loop around the alphabet (26 characters)
    int string_to_int = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        int ascii_difference = isupper(plaintext[i]) ? 65 : 97;

        int a = plaintext[i] - ascii_difference;
        int b = (a + string_to_int) % 26;

        printf("%c", b + ascii_difference);
    }
    printf("\n");
}

