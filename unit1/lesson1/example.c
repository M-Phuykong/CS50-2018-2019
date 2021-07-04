/*
Program to say hello
Written by MengKong
On 24/09/2018
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Enter your name:");

//Always comment on your code
   printf("Hello, %s\n", name);
}