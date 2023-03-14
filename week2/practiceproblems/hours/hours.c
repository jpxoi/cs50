#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Prompt the user for the number of weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // Iterate the prompt for housework hours for each week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Loop the prompt for choosing what to do with the hours as long as the answers do not meet the requirements
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Print the calculated hours
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculate the hours
float calc_hours(int hours[], int weeks, char output)
{
    // Declare the local variables
    int total = 0;
    float average = 0;
    float return_value = 0;

    // Calculate the total hours
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    if (output == 'T')
    {
        // Return the total
        return_value = (float) total;
    }
    else if (output == 'A')
    {
        // Calculate the average and return the value
        average = total / (float) weeks;
        return_value = average;
    }

    return return_value;
}
