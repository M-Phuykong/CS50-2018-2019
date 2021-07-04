#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Enter an integer:");

    if (x % 2 == 0)
    {
        printf("Your number is even.\n");
    }
    else
    {
        printf("Your number is odd.\n");
    }
}