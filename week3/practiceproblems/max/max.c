// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    // Validate that the number of elements is more than 1
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    // Prompt the user for an element n times
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i + 1);
    }

    // Print the max value of the elements array
    printf("The max value is %i.\n", max(arr, n));
}

// Return the max value
int max(int array[], int n)
{
    // Initialize a max_value as the first value of the string
    int max_value = array[0];

    // Compare each value of the array with the max_value
    for (int i = 0; i < n; i++)
    {
        if (max_value < array[i])
        {
            // If the value of the array is larger than the max_value, replace the max_value with the array value in that position.
            max_value = array[i];
        }
    }

    // Return the max_value
    return max_value;
}
