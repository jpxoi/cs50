#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    // Prompt the user for a positive integer
    string input = get_string("Enter a positive integer: ");

    // Validate if all the characters of the string are digits
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int len = strlen(input);

    // Base case for recursive function
    if (len == 1)
    {
        return input[0] - '0';
    }

    // Get the index of the last char in the string
    char last_digit = input[len - 1];

    // Convert this char into its numeric value
    int converted_last_digit = last_digit - '0';

    // Remove the last char from the string by moving the null terminator one position to the left
    input[len - 1] = '\0';

    // Return this value plus 10 times the integer value of the new shortened string
    return converted_last_digit + 10 * convert(input);
}