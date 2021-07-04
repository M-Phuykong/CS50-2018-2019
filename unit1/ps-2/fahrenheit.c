/*
Problem Set 1-2 : Celcius to Fahrenheit Converter
Written By: Meng Phuykong
25-09-2018
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Getting an input from user and store in x that is a float
    float x = get_float("C:");
    //Take the input value and calculate it wioth the formula
    float y = ((x * 9) / 5) + 32 ;
    //print result to one decimal place
    printf("%.1f\n", y);
}
