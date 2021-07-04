#include <stdio.h>

//Declaring main to accept command line argument
int main(int argc, char *argv[])
{

    //Check for correct number of argument
    if (argc != 2)
    {
        //Print the message to stderr instead of the usual stdout with printf
        fprintf(stderr, "Usage: ./recover [name of recover files]\n");
        return 1;
    }

    //Open and read file from the first argument which is "card.raw" in this case
    FILE *image_file = fopen(argv[1], "r");
    //Check to see if the file exist
    if (image_file == NULL)
    {
        //Print the message if the format is wrong or file doesn't exist
        fprintf(stderr, "Could not read files\n");
        return 2;
    }

    //Declare variable for the loop
    //Unsigned char which means no negative number
    unsigned char buffer[512];
    //Declare array as 8 because "###.jpg" and '/0'
    char image[8];
    //Flag for if a JPEG is found
    int found = 0;
    //For naming each JPEG
    int file_count = 0;
    //Null so that it could be declare to a file later
    FILE *photo = NULL;

    //Loop that will keep on going until it reach EOF where it doesn't return a 1
    //Function also read from the raw 512 bits at a time and store it in buffer
    while (fread(buffer, 512, 1, image_file) == 1)
    {
        //If condition to check for JPEG header files
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //Check to see if it was already found
            if (found == 1)
            {
                //Close if has already been found
                fclose(photo);
            }
            else
            {
                //Flag it as found when it's first found
                found = 1;
            }

            //Use the function to make the JPEG file name that goes up on the file count; starts at 000
            sprintf(image, "%03i.jpg", file_count);

            //Declare a pointer to the newly open file that has the option to append
            photo = fopen(image, "a");

            //Write from the string "buffer" into the newly opened file
            fwrite(buffer, 512, 1, photo);

            //Increase the file count by 1 everytime an image is done
            file_count++;

        }
        //Continue to append into the JPEG file until a new header is found in the raw file
        else if (found == 1)
        {
            fwrite(buffer, 512, 1, photo);
        }
    }
    //Close all file
    fclose(photo);
    fclose(image_file);
    return 0;

}