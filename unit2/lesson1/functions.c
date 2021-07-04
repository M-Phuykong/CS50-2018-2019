#include <stdio.h>
#include <cs50.h>

int cubed(int n);

int main(void)
{
    int number = get_int("Enter an int: ");

    printf("Cube: %d\n ", cubed(number));
}

int cubed(int n)
{
    return n*n*n;
}
