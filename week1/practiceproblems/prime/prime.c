#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Get min and max
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Print primes
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Returns true if number is prime, else false
bool prime(int number)
{
    if (number == 1)
    {
        return false;
    }
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}