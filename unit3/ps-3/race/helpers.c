// Helper functions for the sort race

#include <cs50.h>
#include <string.h>
#include "helpers.h"

// Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    //If condition to check if the user's input is one of these valid flag
    //If it is the same, strcmp will return 0 and then return true else return false
    if (strcmp(str,"-a") == 0)
    {
        return true;
    }
    else if (strcmp(str,"-b") == 0)
    {
        return true;
    }
    else if (strcmp(str,"-r") == 0)
    {
        return true;
    }
    else if (strcmp(str,"-s") == 0)
    {
        return true;
    }
    return false;
}

// Sorts array of n values using bubble sort
void bubble(int values[], int n)
{
    //First For to loop through the list of (n - 1) times to ensure that it looped enough to sort the list
    for (int pass = 0; pass < n - 1; pass++)
    {
        //For to go through all the character in the list, i starts at 0 (first index)
        for (int i = 0; i < n - 1; i ++)
        {
            //Another for to compare it against i, j starts at the next character of i hence (i + 1)
            for (int j = i + 1; j < n; j++)
            {
                //Check to see if the value of i is bigger than j, if it is then swap them
                if (values[j] < values[i])
                {
                    //Create another variable to store the value for swapping
                    int swap = values[i];
                    values[i] = values[j];
                    values[j] = swap;
                }

            }
        }
    }
    return;
}

// Sorts array of n values using selection sort
void selection(int values[], int n)
{
    //For loop that iterates from the first character to the second last character of the array
    for (int i = 0; i < n - 1; i++)
    {
        //Store the first value character in the variable for comparision
        int min = i;

        //Another FOR loop that iterates through the array but starts after the index 'i'
        for (int j = i + 1; j < n; j++)
        {
            //Compare and if the min value is smaller then replace min value with the new value
            if (values[min] > values[j])
            {
                min = j;
            }
        }

        //Check the value of min, if it's not the same as i then swap the array
        if (min != i)
        {
            int swap = values[min];
            values[min] = values[i];
            values[i] = swap;
        }
    }
    return;
}

// Sorts array of n values using insertion sort
void insertion(int values[], int n)
{
    //A loop that start at the second list since index[1] = second item
    for (int i = 1; i < n - 1; i++)
    {
        //Store the value in the variable
        int element = values[i];
        //Store the index number in another variable
        int j = i;

        //While condition keep on running until the condition is met
        while (j > 0 && values[j - 1] > values[j])
        {
            //Change the value to the beginning value
            values[j] = values[j - 1];
            //Move j back to the original position
            j = j - 1;
        }

        //Insert the old value back into the original position
        values[j] = element;
    }
    return;
}
