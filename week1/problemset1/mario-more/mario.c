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
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print hashes
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Print new line
        printf("\n");
    }
}