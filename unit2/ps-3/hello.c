/*
Problem Set 2-2: Old Friends (Hello)
Written By: Phuykong Meng
20-10-2018
*/
#include <stdio.h>

//Instead of Void , put argc and argv for user's argument input
int main(int argc, char *argv[])
{
    //Check for the user's correct argument input
    if (argc == 2)
    {
        //Print "Hello" + user's argument input
        printf("Hello, %s!\n", argv[1]);
        return 0;
    }
    //If user enters anything more than 2 argument or less than 2 ; program will not run
    else
    {
        return 1;
    }
}