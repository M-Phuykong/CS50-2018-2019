/*
Problem Set 2-1: Initials(less)
Written By: Phuykong Meng
18-10-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //Getting user's input
    string name = get_string("");

    //Only works if the string fit with the size
    if (name != NULL)
    {
        //Check every character of the string
        //Strlen() function gets the string character lengths
        for (int i = 0, n = strlen(name) ; i < n ; i++)
        {
            //Conditional statement to print the first character always
            if (i == 0)
            {
                //Toupper() functions is to convert the char into an uppercase letter
                printf("%c", toupper(name[0]));
            }
            //Conditional statement checks for space and print the next char after space
            if (name[i] == ' ')
            {
                printf("%c", toupper(name[i + 1]));
            }
        }
        printf("\n");
    }
}