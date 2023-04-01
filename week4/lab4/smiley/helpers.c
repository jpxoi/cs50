#include "helpers.h"
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Choose the color you want. r for red, b for blue and g for green
    char color = 'r';

    // Change all black pixels to the chosen color
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Make black pixels turn the chosen color
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                if (color == 'r')
                {
                    image[i][j].rgbtRed = 0xff;
                }
                else if (color == 'b')
                {
                    image[i][j].rgbtBlue = 0xff;
                }
                else if (color == 'g')
                {
                    image[i][j].rgbtGreen = 0xff;
                }
            }
        }
    }
}
