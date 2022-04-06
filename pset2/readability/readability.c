#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)

{
   //Prompt for a sentence.
   string sentence  = get_string("Text: ");

   int letters = 0;
   int words = 1;
   int sentences = 0;

   for (int i = 0, n = strlen(sentence); i < n; i++)

   //Calculate amount of letters.
   if (isalpha(sentence[i]))
       {
       letters++;
       }

    //Amount of words.
    else if (isspace(sentence[i]))
      {
       words++;
      }

    //Amount of sentences.
    else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
       {
       sentences++;
       }

    //Calculate the grade level.
    float L = letters / (float)words * 100;
    float S = sentences / (float)words * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    //Print Grade Level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}



