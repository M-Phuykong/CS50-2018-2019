/*
Problem Set 2-6: Vigenere
Written By: Phuykong Meng
20-11-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Declare a command line argument
int main(int argc, char *argv[])
{
    //Runs if user put in two arguments
    if (argc == 2)
    {
        //For loop to check if KEY is only a word
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            //Converts user's key input into an integer for checking
            int check = atoi(&argv[1][i]);
            if (check != isalpha(check))
            {
                //Print if there's a number/special character in KEY
                printf("Please use a word as a key!\n");
                //Exit the program with an error
                exit(1);
            }

        }

        //Declare a string for user's text that will be encrypted
        string plaintxt = get_string("Plaintext: ");

        printf("ciphertext: ");

        //Hard code value for encrypting since Lower and Upper case letter has different ASCII value
        int low_char = 97;
        int high_char = 65;
        //Declare an array with a size of 99
        int key[99];

        //For loop to convert KEY into value that could be incremented
        for (int k = 0 ; k < strlen(argv[1]) ; k++)
        {
            //If KEY is upper case then this if will run
            if (isupper(argv[1][k]))
            {
                //Mod the Ascii value of the KEY to 65 for uppercase
                key[k] = (argv[1][k]) % high_char;
            }
            //If KEY is lower case then this if will run
            else if (islower(argv[1][k]))
            {
                //Mod the Ascii value of the KEY to 97 for lowercase
                key[k] = (argv[1][k]) % low_char;
            }
        }


        //For loop to iterate over the user's plaintext
        //Declare another value of m so that it would only increment when it is a letter
        for (int j = 0, m = 0 ; j < strlen(plaintxt); j++)
        {
            //Check if plaintext is a letter
            if (isalpha(plaintxt[j]))
            {
                //Check for uppercase letter in user's plaintext
                if (isupper(plaintxt[j]))
                {
                    //This IF statement ensures that the value of m doesn't pass the length of user's KEY
                    if (m == strlen(argv[1]))
                    {
                        m = 0;
                    }
                    //Declare an int to hold the value of the new ASCII code after encrypting
                    int ciphertxt = (key[m] + plaintxt[j]);
                    //WHILE loop to check if the ASCII number is above 90('z'), if so minus 26 to wrapped back to 'a'
                    while (ciphertxt > 90)
                    {
                        ciphertxt = ciphertxt - 26;
                    }
                    //Print the newly encrypted text
                    printf("%c", ciphertxt);
                    //Increment m by one each time a letter is encrypted
                    m++;
                }
                //Run this loop if its a lower case letter
                //The same as uppercase loop
                else if (islower(plaintxt[j]))
                {
                    if (m == strlen(argv[1]))
                    {
                        m = 0;
                    }
                    int ciphertxt = (key[m] + plaintxt[j]);
                    while (ciphertxt > 122)
                    {
                        ciphertxt = ciphertxt - 26;
                    }
                    printf("%c", ciphertxt);
                    m++;
                }
            }
            //If the user's plaintext has a number/special character then print that without encrypting it
            else
            {
                printf("%c", plaintxt[j]);

            }
        }

        printf("\n");

        return 0; //Exit after encrypting making sure that the program works properly

    }
    else //Exit the program if user didn't put in two command line arguments
    {
        return 1;
    }
}