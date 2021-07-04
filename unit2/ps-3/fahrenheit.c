/*
Problem Set 2-2 : Old Friend (Fahrenheit)
Written By: Phuykong Meng
20-10-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        //Converting user's argument into a float by the atof() function
        float x = atof(argv[1]);
        //Take the input value and calculate it wioth the formula
        float y = ((x * 9) / 5) + 32 ;
        //print result to one decimal place
        printf("%.1f\n", y);
        return 0;
    }
    else
    {
        return 1;
    }
}
