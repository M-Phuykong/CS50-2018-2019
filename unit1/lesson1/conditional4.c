#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char ans = get_int("Enter an integer: ");

    switch (ans)
    {
        case 4:
            printf("4\n");
        case 3:
            printf("3\n");
        case 2:
            printf("2\n");
        case 1:
            printf("1\n");
            break;
        default:
            printf("idk\n");
    }
}