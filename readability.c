#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 0;

    string text = get_string("Text:");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }

        if (isblank(text[i]))
        {
            wordCount++;
        }

        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentenceCount++;
        }

    }


    float L = 100 * (float) letterCount / (float) wordCount;
    float S = 100 * (float) sentenceCount / (float) wordCount;


    float grade = (0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (grade > 15)
    {
        printf("Grade 16+\n");
        return 0;
    }
    
    printf("Grade %i\n", (int) round(grade));

}