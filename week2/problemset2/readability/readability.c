#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Declare function protoypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for the text
    string text = get_string("Text: ");

    // Retrieve the number of letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the L and S values
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    // Calculate and round the index value
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Print the grade depending on the index value.
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Function to count the number of letters in the text string
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// Function to count the number of words in the text string
int count_words(string text)
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    words++;

    return words;
}

// Function to count the number of sentences in the text string
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        switch (text[i])
        {
            case '.':
                sentences++;
                break;

            case '!':
                sentences++;
                break;

            case '?':
                sentences++;
                break;

            default:
                break;
        }
    }

    return sentences;
}
