#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Declare a constant of how many bits are in a byte
const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Prompt the user for the message to be encrypted
    string message = get_string("Message: ");

    // Loop through each character of the message
    for (int i = 0; i < strlen(message); i++)
    {
        // Declare the necessary variables for calculation
        unsigned char byte = message[i];
        int binary[BITS_IN_BYTE];
        int quotient = byte;
        int remainder;

        // Transform ASCII to Binary
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            remainder = quotient % 2;
            binary[j] = remainder;
            quotient /= 2;
        }

        // Print backwards each bulb representing each bits in a byte
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
