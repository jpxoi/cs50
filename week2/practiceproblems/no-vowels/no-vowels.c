#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function prototype
string replace(string word);

int main(int argc, string argv[])
{
    // Check for correct command line argument format
    if (argc < 2) // if no command-line arguments are provided
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    else if (argc > 2) // if more than one command-line argument is provided
    {
        printf("Too many command-line arguments\n");
        return 1;
    }

    // Call replace function and print the resulting string
    printf("%s\n", replace((string) argv[1]));
}

// Function definition for string replacement
string replace(string word)
{
    // Declare and initialize variables
    long len = strlen(word);
    long new_len = len + 1;
    char word_chars[new_len];
    word_chars[len] = 0;

    // Loop through the input string and replace each character as needed
    for (int i = 0; i < len; i++)
    {
        switch (word[i])
        {
            case 'a': // if character is 'a', replace with '6'
                word_chars[i] = '6';
                break;

            case 'e': // if character is 'e', replace with '3'
                word_chars[i] = '3';
                break;

            case 'i': // if character is 'i', replace with '1'
                word_chars[i] = '1';
                break;

            case 'o': // if character is 'o', replace with '0'
                word_chars[i] = '0';
                break;

            default: // if character is not one of the above, keep the original character
                word_chars[i] = word[i];
                break;
        }
    }

    // Convert character array to string and return the new string
    string new_word = word_chars;
    printf("Generating...\n");
    return new_word;
}
