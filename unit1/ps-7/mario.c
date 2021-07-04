/*
Problem Set 1-7: Mario
Written By: Meng Phuykong
O9/10/2018
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Assigned all variable as an integer
    int get_height, space , z = 0 , y = 0;

    // Loop to check user's input
    do
    {
        get_height = get_int("Number (1-23) :");
    } while (get_height < 0 || get_height > 23);

    // Pyramid printing loop
    // Repeats as many time as the user's input
    for (int i = 0 ; i < get_height ; i++)
    {
        // Space are one less then the height itself therefore -1
        // Loop to print out one less space in each line
        for (z = (get_height - 1) ; z > i  ; z--)
        {
            printf(" ");
        }
        // Print "##" with two loop that's why (i+2)
        // Add "#" in each line until i == false
        for (y = 0 ; y < (i + 2)  ; y++)
        {
            printf("#");
        }
        // Create a new line after the first loop is done
        printf("\n");

    }
}