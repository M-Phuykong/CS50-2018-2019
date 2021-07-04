/*
Problem Set 1-4: Pennies
Written By: Meng Phuykong
27-09-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Initiate the variable from the beginning so that we don't need to initiate it later
    float x;
    float y;
    //Store as double due to big numbers and precision (in cents and dollars)
    double z;
    double i;

    //Do-while loop to check input of user when they enter the days in the month (28<=x<=31)
    do
    {
        //Assigned value of days in 'x'
        x = get_float("Days in month:");

    } while (x < 28 || x > 31);

    //Another do-while loop to check user's input for the starting amount of pennies (can't be less than 1)
    do
    {
        //Assigned starting pennies value to 'y'
        y = get_float("Pennies on First Day:");

    } while (y <= 0);

    //Use the function pow() from <math.h> for power; used Geometric Sequence equation for answer A(x) = A(1) * q^(x-1)
    //Store result in 'z' for converting in 'i'
    z = y * (pow(2, x));

    //Subtract starting pennies from the result and then divide it by 100 for dollars and cents
    i = ((z - y) / 100);

    //Print result to the nearest two decimal place
    printf("$%.2f\n", i);
}