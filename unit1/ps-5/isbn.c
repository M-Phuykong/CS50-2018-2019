/*
Problem Set 1-5: ISBN
Written By: Meng Phuykong
28-09-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Assign user input of ISBN code to 'x' with long due to big numbers
    long x = get_long("ISBN:");
    //Set 'z' to zero for later addition
    long z = 0;

    //For loop for getting modulo of each digit
    // i > 0 so it will loop 10 times since ISBN has 10 digits
    //i-- ,decrement the starting value of i until less than 0
    for (int i = 10; i > 0 ; i--)
    {
        //Getting modulo of the last digit
        long y = (x % 10);
        //Move decimal place to the left so that it could move to the next digit
        x = (x / 10);
        //Times by the value of "i"
        y = (y * i);
        //Increment (plus) the value of y  for the next 10 times and assigned it to "z"
        z += y;
    }

    //Check if "z" is dividable by 11 ; if so it will print "yes" , else it would print "no"
    if ((z % 11) == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

}