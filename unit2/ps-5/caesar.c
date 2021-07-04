/*
Problem Set 2-4: Caesar 
Written By: Phuykong Meng
02-11-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        //Defining each variable beforehand
        int key ;
        string plaintext;
        //Used unsigned char for value over 127
        unsigned char cipherchar;

        //Atoi() function to convert string into a integer
        key = atoi(argv[1]);

        plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        //Loop for every character in the string
        for (int i = 0 ; i < strlen(plaintext) ; i++)
        {
            //Check if the character is a letter with the isalpa() function
            if (isalpha(plaintext[i]))
            {
                cipherchar = plaintext[i] + key;
                
                //If statement for if the ASCII value goes over 122
                if (cipherchar > 122)
                {
                    //Do while loop to minus 26 from the ASCII value until it is less than 122(Z)
                    do
                    {
                        cipherchar = cipherchar - 26;
                    } 
                    while (cipherchar > 122);

                    printf("%c", cipherchar);
                }
                //Else If statement to check for the special character if the ASCII value reaches it
                else if ((cipherchar > 90) && (cipherchar < 97))
                {
                    cipherchar = cipherchar - 26;
                    printf("%c", cipherchar);
                }
                //Prints the char of ASCII value that was moved with the key
                else
                {
                    printf("%c", cipherchar);
                }
            }
            
            else
            {
                //Prints non-letter , special case
                printf("%c", plaintext[i]);
            }
        }

        printf("\n");
    }
    else
    {
        //Exit program if user doesn't meet the required argument counter
        return 1;
    }
}

