// Helper functions

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    //Condition to check for when there are no more number
    if (n < 0)
    {
        return false;
    }

    //Start at index 0
    int start = 0;
    //Last location of the list
    int end = n - 1;

    //A while loop that will keep on looping until there are no more number in the list
    while (n > 0)
    {
        //Finding the middle of the list
        int m = (start + end) / 2;

        //Check if the middle of the list is actually the value, return true if it is
        if (values[m] == value)
        {
            return true;
        }
        //If the middle is value is bigger than the user's value then look only to the left of the list
        else if (values[m] > value)
        {
            //Changing the location of end
            end = m - 1;

        }
        //If the user's value is biggger than the middle value then look to the right of the list
        else if (values[m] < value)
        {
            //Change the start of the list
            start = m + 1;

        }

        //Modify the value of n until it is less than 0
        n = end - start + 1;
    }
    return false;
}


// Sorts array of n values
void sort(int values[], int n)
{
    //For loop until the second last item on the list
    for (int i = 0; i < n - 1  ; i++)
    {
        //Initiate a variable that stores the minimum value of the first list
        int min = i;

        //Another for loop that starts on the next character of the list
        for (int j = i + 1; j < n; j++)
        {
            //Check to see if the next character value is smaller than the first minimum value
            if (values[min] > values[j])
            {
                //Change the minimum value if it is
                min = j;
            }

        }

        //Check the value of min to the first min, if it is different then swap the character
        if (min != i)
        {
            //A variable for swapping the value in the list
            int swap = values[min];
            values[min] = values[i];
            values[i] = swap;
        }
    }
    return;
}
