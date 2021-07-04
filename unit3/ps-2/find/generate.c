// Generates pseudorandom numbers in [0,LIMIT), one per line

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Check for user's input to see if they meet the correct arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Convert string of argv[1] into an integer 
    int n = atoi(argv[1]);

    // If statement for when user enters three argument in the beginning
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // For loop in which it loops based on the user's input while printing out a 'random' number per line
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // Success
    return 0;
}
