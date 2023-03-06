#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for name
    string name = get_string("What's your name? ");

    // Say hello and print name
    printf("hello, %s\n", name);
}