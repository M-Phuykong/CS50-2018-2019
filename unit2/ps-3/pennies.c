/*
Problem Set 2-2: Old Friends (Pennies)
Written By: Phuykong Meng
20-10-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        //Initiate the variable from the beginning so that we don't need to initiate it later
        float x;
        float y;
        //Store as double due to big numbers and precision (in cents and dollars)
        double z;
        double i;

        //Convert String of Argument[1] into the float "x"
        x = atof(argv[1]);
        if (x < 28 || x > 31)
        {
            return 1;
        }
        //Convert last argument into the float "y"
        y = atof(argv[2]);
        if (y <= 0)
        {
            return 1;
        }

        //Use the function pow() from <math.h> for power; used Geometric Sequence equation for answer A(x) = A(1) * q^(x-1)
        //Store result in 'z' for converting in 'i'
        z = y * (pow(2, x));

        //Subtract starting pennies from the result and then divide it by 100 for dollars and cents
        i = ((z - y) / 100);

        //Print result to the nearest two decimal place
        printf("$%.2f\n", i);
        return 0;
    }
    else
    {
        return 1;
    }
}