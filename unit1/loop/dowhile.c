#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int ans;

    do
    {
      ans = get_int("Enter a positive int:");
    } while (ans < 1);
}