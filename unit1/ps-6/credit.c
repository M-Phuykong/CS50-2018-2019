/*
Problem Set 1-6: Credit
Written By: Meng Phuykong
04/10/2018
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Assigned all the variable as a long long
    long long numb, ndigit, z = 0, x, y, e, f, g = 0, check_value, a;

    // Loop to check if the user's input is less than 0 ; if so repeat
    do
    {
        numb = get_long("Number:");
        a = numb;
        ndigit = floor(log10(labs(numb))) + 1;
    } while (ndigit < 0);


    // If statement to check for input lengths
    if ((ndigit < 13 || ndigit > 16) || ndigit == 14)
    {
        printf("INVALID\n");
    }


    //For Loop to calculate card's validity
    for (int i = 8; i > 0; i--)
    {
        // Gets user's card last digit for calculation
        e = numb % 10;
        // Move one decimal to the left in order to calculate the next digit
        f = numb / 10;
        // Gets user's second to last digit
        x = ((numb / 10) % 10);
        // Multiply the second last digit by 2 and so on
        y = x * 2;
        numb = numb / 100;
        // Loop to check if the number that multiplied by 2 is bigger than 10
        while (y > 9)
            {
                // Find last digit of the number that is bigger than 10
                x = y % 10;
                y = y / 10;
                // Plus both digits together
                y += x;
            }
        // Add all of y together
        z += y;
        // Add all of e together
        g += e;

        // Assigned total of "g" and "z" to "check_value"
        check_value = g + z;
        // Find last digit of "check_value"
        check_value = check_value % 10;
    }

    // If statement for company's identifier
    if (ndigit == 16 && check_value == 0)
    {
        // Move decimal point to the left 14 times
        a = a / 100000000000000;
        // Gets both digit of the remaining number
        x = a % 100;

        // If statement to check for the last two digit
        if (x > 39 && x < 50)
        {
            printf("VISA\n");
        }
        else if (x > 50 && x < 56)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    // Else If statement to check for a different condition
    else if (ndigit == 15 && check_value == 0)
    {
        a = a / 10000000000000;
        x = a % 100;
        if (x == 34 || x == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (ndigit == 13 && check_value == 0)
    {
        a = a / 100000000000;
        a =  a % 100;
        if (ndigit >= 40 && ndigit <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Prints "INVALID" if none of the condition is sastified
    else
    {
        printf("INVALID\n");
    }
}