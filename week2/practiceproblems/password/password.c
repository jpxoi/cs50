#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    // Prompt user for password
    string password = get_string("Enter your password: ");

    // Check if the password is valid
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    // Declare variables to keep track of the number of lowercase letters, uppercase letters, numbers and symbols
    int lower = 0;
    int upper = 0;
    int number = 0;
    int symbol = 0;

    // Iterate through the string and check if each character is a lowercase letter, uppercase letter, number or symbol
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            lower++;
        }
        else if (isupper(password[i]))
        {
            upper++;
        }
        else if (isdigit(password[i]))
        {
            number++;
        }
        else
        {
            symbol++;
        }
    }

    // Return true if the password has at least one lowercase letter, uppercase letter, number and symbol
    if (lower > 0 && upper > 0 && number > 0 && symbol > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
