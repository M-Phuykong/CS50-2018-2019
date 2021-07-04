/*
Problem Set 2-5: Crack
Written By: Phuykong Meng
12-11-2018
*/
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#define _XOPEN_SOURCE

//Start command line argument
int main(int argc , char *argv[])
{
    //If statement to accept only two arguments
    if (argc == 2)
    {
        //Declare an array from a-Z
        char alphabet[] = {"\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        //Declare a key array with a memory slot of 5, unused memory will be replace with '\0' (Terminator)
        char key[5] = {'\0'};
        int comp;

        //For loop to loop through the array
        for (int i = 0; i <= 52; i++)
        {
            //Change the first character of array "key" with the array "alphabet"
            key[0] = alphabet[i];

            //A string to hold the function of crypt for later compairison
            char *hash1 = crypt(key, "50");

            //String comparing function with starting hashed(argv[1) and each alphabet hashed
            comp = strcmp(argv[1], hash1);

            //Return 0 if both string is the same and execute the if command
            if (comp == 0)
            {
                //Print the key which is the same hashed as the starting hashed
                printf("%s\n",key);
                //Quit Program after printing
                exit(0);
            }

            //Another For loop for two characters password, i.e(aa,ab,ac...ZZ)
            for (int j = 0 ; j <= 52; j++)
            {
                //Change the second character instead
                key[1] = alphabet[j];
                comp = strcmp(argv[1],crypt(key, "50"));
                if (comp == 0)
                {
                    printf("%s\n",key);
                    exit(0);
                }

                //For loop for three characters password,i.e(aaa,aac...ZZZ)
                for (int k = 0 ; k <= 52 ; k++)
                {
                    //Change the third character
                    key[2] = alphabet[k];
                    comp = strcmp(argv[1],crypt(key, "50"));
                    if (comp == 0)
                    {
                        printf("%s\n",key);
                        exit(0);
                    }

                     //For loop for four characters password,i.e(aaaa,aaab...ZZZZ)
                     for (int l = 0 ; l <= 52 ; l++)
                        {
                            //Change the four character
                            key[3] = alphabet[l];
                            comp = strcmp(argv[1],crypt(key, "50"));
                            if (comp == 0)
                                {
                                    printf("%s\n",key);
                                    exit(0);
                                }
                        }
                }

            }

        }

    }
    else
    {
        //Exit the program if arguments is not met
        return 1;
    }
}


//Andy: "hi" hashed: 50.jPgLzVirkc time: 0m4.614s
//Jason: "JH" hashed: 50YHuxoCN9Jkc time: 0m21.425s
//Malan: "NOPE" hashed: 50QvlJWn2qJGE time: 0m23.950s
//Mzlatkova: "ha" hashed: 50CPlMDLT06yY time: 0m4.023s
//Patrick: "Yale" hashed: 50WUNAFdX/yjA time: 0m34.198s
//Rbowden: "rofl" hashed: 50fkUxYHbnXGw time: 0m11.368s
//Summer: " FTW" hashed: 50C6B0oz0HWzo time: 0m18.766s
//Stelios: "ABC" hashed: 50nq4RV/NVU0I time: 0m15.896s
//Wmartin: "haha" hashed: 50vtwu4ujL.Dk time: 0m4.800s
//Zamyla: "lol" hashed: 50i2t3sOSAZtk time: 0m7.195s