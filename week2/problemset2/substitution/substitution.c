#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool only_alphabetic(string s);
bool repeated_chars(string s);
string to_uppercase(string s);

int main(int argc, string argv[])
{
    // Check for exactly one command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate that the key contains only alphabetic characters
    if (!only_alphabetic(argv[1]))
    {
        printf("Key must contain alphabetic characters only\n");
        return 1;
    }

    // Validate that the key is 26 characters long
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // Validate that each character in the key is unique
    if (repeated_chars(argv[1]))
    {
        printf("Key must not contain repeated alphabetic characters\n");
        return 1;
    }

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // Convert the key to uppercase
    string key = to_uppercase(argv[1]);

    // Print the ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    // Print a newline character
    printf("\n");
    return 0;

}

bool only_alphabetic(string s)
{
    // Loop through each character in the string
    for (int i = 0; i < strlen(s); i++)
    {
        // If the character is not an alphabetic character, set valid to false and return it
        if (!isalpha(s[i]))
        {
            return false;
        }
    }

    // If all characters are alphabetic, return true
    return true;
}

bool repeated_chars(string s)
{
    // Loop through each character in the string
    for (int i = 0; i < strlen(s); i++)
    {
        // Loop through all characters that come after the current character
        for (int j = i + 1; j < strlen(s); j++)
        {
            // If two characters are the same, return true
            if (s[i] == s[j])
            {
                return true;
            }
        }
    }

    // If no repeated characters are found, return false
    return false;
}

string to_uppercase(string s)
{
    // Loop through each character in the string
    for (int i = 0; i < strlen(s); i++)
    {
        // If a character is lowercase, convert it to uppercase
        if (islower(s[i]))
        {
            s[i] = s[i] - 32;
        }
    }

    // Return the uppercased string
    return s;
}
