#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print pyramid
    for (int j = 0; j < height; j++)
    {
        // Print spaces
        for (int i = 0; i < height - j - 1; i++)
        {
            printf(" ");
        }

        // Print hashes
        for (int k = 0; k < j + 1; k++)
        {
            printf("#");
        }

        // Print new line
        printf("\n");
    }
}