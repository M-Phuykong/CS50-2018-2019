// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //Set a variable for equation
    int num, deno, x;

    //Take result from the string fraction and put it in the variable "num" and "deno"
    sscanf(fraction, "%d %*c %d", &num, &deno);

    //Converting the fraction to eighths by using the equation based on algebra
    x = (num * 8) / deno;

    //Return the last value
    return x;


}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int oct = 0, oct_diff;
    float n;
    char letter = 0, acc = '\0';

    //If statement to check if the string is either three letter long or two
    if (strlen(note) == 2)
    {
        //Scan from note and store it in variable
        sscanf(note, "%c %d", &letter, &oct);
    }
    else if (strlen(note) == 3)
    {
        //Same as above but store it in an extra variable "acc" to check if it's a "#" or "b"
        sscanf(note, "%c %c %d", &letter, &acc, &oct);
    }

    //Find the octaves different from A4
    oct_diff = oct - 4;

    //Switch case to set the value of n based on the understanding of how many semitones they are far apart from A4
    switch (letter)
    {
        case 'A':
        {
            n = 0;
            break;

        }
        case 'B':
        {
            n = 2;
            break;
        }
        case 'C':
        {
            n = -9;
            break;
        }
        case 'D':
        {
            n = -7;
            break;
        }
        case 'E':
        {
            n = -5;
            break;
        }
        case 'F':
        {
            n = -4;
            break;
        }
        case 'G':
        {
            n = -2;
            break;
        }
    }

    //Add a semitone if it's "#"
    if (acc == '#')
    {
        n += 1;
    }
    //Remove a semitone if it's "b"
    else if (acc == 'b')
    {
        n -= 1;
    }

    //Since each octone difference is 12 semitone apart
    //Check to see if it's either lower or higher than A4
    //If it is, add/substract 12 (more if the octone different is bigger)
    if (oct_diff != 0)
    {
        n += (oct_diff * 12);
    }

    //Calculate the frequency using the equation : 2^n/12 * 440
    //Make sure to round the result at the end so that it will be a whole number using the round() function
    int frequency = round(pow(2, (n / 12)) * 440);

    //Reutrn the final value of frequency
    return frequency;


}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //Comparing the string s to "" which is what get_string return when user doesn't enter anything
    if (strcmp(s, "") == 0)
    {
        //Return true if it's a space; representing a rest
        return true;
    }
    else
    {
        return false;
    }
}
