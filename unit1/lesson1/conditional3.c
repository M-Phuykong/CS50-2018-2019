#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char ans = get_char("Y or N:");

    switch (ans)
    {
        case 'Y':
        case 'y':
            printf("Yes.\n");
            break;
        case 'N':
        case 'n':
            printf("No.\n");
            break;
    }
}