#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);


int main(int argc, string argv[])
{
    // Check for exactly one command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check for command line argument validity
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the command line argument to an integer and store it in k
    int k = atoi(argv[1]);

    // Prompt the user for a string of plaintext
    string plaintext = get_string("plaintext: ");

    // Print the header for the ciphertext
    printf("ciphertext: ");

    // Rotate eacg character by k and print the rotated character
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char new_char = rotate(plaintext[i], k);
        printf("%c", new_char);
    }

    // Print a newline character
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    bool valid = true;

    // Loop through each character in the string
    for (int i = 0; i < strlen(s); i++)
    {
        // If the character is not a digit, set valid to false and return it
        if (!isdigit(s[i]))
        {
            valid = false;
            return valid;
        }
    }

    // If all characters are digits, return true
    return valid;
}

char rotate(char c, int n)
{
    // If the character is uppercase, rotate it by n positions
    if (isupper(c))
    {
        char new_char = (((c - 65) + n) % 26) + 65;
        return new_char;
    }
    // If the character is lowercase, rotate it by n positions
    else if (islower(c))
    {
        char new_char = (((c - 97) + n) % 26) + 97;
        return new_char;
    }
    // If the character is not a letter, return it as it is
    else
    {
        return c;
    }
}
