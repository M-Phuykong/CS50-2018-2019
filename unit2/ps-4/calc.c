/*
Problem Set 2-3: Calc
Written By: Phuykong Meng
23-10-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

//Start main by having a command line arguments
int main(int argc, char *argv[])
{
    //Check for user's argument , if more than 4 then don't run
    if (argc == 4)
    {
        float num1, num2, total = 0.0;
        char sign;
        int q;

        //Convert these argv into a float
        num1 = atof(argv[1]);
        num2 = atof(argv[3]);
        //Convert the second argv (sign) into a single char
        sign = argv[2][0];

        //Uses switch for conditional statenents
        switch (sign)
        {
            case '+':
                total = num1 + num2;
                printf("%f\n", total);
                break;
            case '-':
                total = num1 - num2;
                printf("%f\n", total);
                break;
            case 'x':
            case 'X':
                total = num1 * num2;
                printf("%f\n", total);
                break;
            case '/':
                total = num1 / num2;
                printf("%f\n", total);
                break;
            //Can't use '%' with float so uses formula that was given by CS50
            case '%':
                q = num1 / num2;
                total = num1 - (num2 * q);
                printf("%f\n", total);
                break;
            //If none of the case becomes true, exit the program
            default:
                return 1;

        }

    }
    else
    {
        return 1;
    }
}