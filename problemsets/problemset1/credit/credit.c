#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define a boolean variable for the loop
    bool exit_code = false;
    do
    {
        // Prompt the user for a credit card number
        long long cc_number = get_long_long("Number: ");

        // Check if the number is valid
        if (cc_number > 0)
        {
            // Count the number of digits
            int digits = 0;
            long long cc_number_count = cc_number;
            while (cc_number_count > 0)
            {
                cc_number_count /= 10;
                digits++;
            }

            // Check if the number of digits is valid
            if (digits == 13 || digits == 15 || digits == 16)
            {
                // Execute Lunh's Algorithm
                int sum = 0;
                int digit = 0;
                int digit_count = 0;
                long long cc_number_lunh = cc_number;

                // Get the sum of the digits
                while (cc_number_lunh > 0)
                {
                    digit = cc_number_lunh % 10;

                    // Check if the digit is in an even position
                    if (digit_count % 2 == 0)
                    {
                        sum += digit;
                    }

                    // Check if the digit is in an odd position
                    else
                    {
                        digit *= 2;
                        if (digit > 9)
                        {
                            digit -= 9;
                        }
                        sum += digit;
                    }
                    // Update the variables
                    cc_number_lunh /= 10;
                    digit_count++;
                }

                // Check if the sum is valid
                if (sum % 10 == 0)
                {
                    // Get the first two digits
                    long first_two_digits = cc_number;
                    while (first_two_digits > 100)
                    {
                        first_two_digits /= 10;
                    }

                    // Check if the first two digits are valid for AMEX
                    if (first_two_digits == 34 || first_two_digits == 37)
                    {
                        printf("AMEX\n");
                        exit_code = true;
                    }
                    // Check if the first two digits are valid for MASTERCARD
                    else if (first_two_digits >= 51 && first_two_digits <= 55)
                    {
                        printf("MASTERCARD\n");
                        exit_code = true;
                    }
                    // Check if the first two digits are valid for VISA
                    else if (first_two_digits / 10 == 4)
                    {
                        printf("VISA\n");
                        exit_code = true;
                    }
                    // If the first two digits are not valid for any card type print INVALID and set exit_code to true
                    else
                    {
                        printf("INVALID\n");
                        exit_code = true;
                    }
                }
                // If the sum is not valid print INVALID and set exit_code to true
                else
                {
                    printf("INVALID\n");
                    exit_code = true;
                }

            }
            // If the number of digits is not valid print INVALID and set exit_code to true
            else
            {
                printf("INVALID\n");
                exit_code = true;
            }
        }
        // If the number is negative print INVALID and set exit_code to true
        else
        {
            printf("INVALID\n");
            exit_code = true;
        }
    }
    while (exit_code == false);

    return 0;
}