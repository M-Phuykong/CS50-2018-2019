/*
Problem Set 1-3: Greedy Algorithm
Written By: Meng Phuykong
26-09-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h> //import math library for round() function


int main(void)
{
    //define the float x for user input
    float x;

    //do while loop to check user's input
    do
    {
        x = get_float("How much change is owed?\n");
    } while (x < 0);

    //convert float value of x to y
    int y = x;

    //turn dollars into cent with the equation and round it off with the round()
    y = round(x * 100);

    //set the value of coin counter to 0
    int i = 0;

    //check if the input value of cents is bigger than 1 when divided by 25
    //If its bigger than 1 then the program will add one coin to the counter
    while ((y / 25) >= 1)
    {
        //counter to add the coin
        i++;
        //if 25cent is disposable then we remove 25 from the total input to cut down the value
        y = y - 25;
    }

    //same as 25 but with 10 instead for 10 cents
    while ((y / 10) >= 1)
    {
        i++;
        y = y - 10;
    }

    while ((y / 5) >= 1)
    {
        i++;
        y = y - 5;
    }

    while (y >= 1)
    {
        i++;
        y = y - 1;
    }

    //print the amount of coin that the variable 'i' stored after the equation
    printf("%d\n", i);

}
