// Recursively searches for a query in a directory.

#define _BSD_SOURCE
#define _GNU_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAXLENGTH 50

// Struct to hold the file name and type
typedef struct
{
    string name;
    string type;
}
path;

// Struct to hold the directory info
typedef struct
{
    string name;
    int npaths;
    path *paths;
}
directory;

// String to hold the word to seek
string key;

// The function to search for files in a directory and populate the struct
directory populate(directory dir);

// The function to recursively iterate through directories and handle files
int seek(directory dir);


int main(int argc, char *argv[])
{
    // Create initial directory and set name string
    directory dir;

    // Check for the right amount of arguments
    if (argc == 2)
    {
        //Make the key as the first argument
        key = argv[1];
        //If no second argument is given then make the directory name "./" so that it starts from the top file
        dir.name = "./";
    }
    else if (argc == 3)
    {
        //Check for if the given directory has a "/" at the last character
        if (argv[2][strlen(argv[2]) - 1] != '/')
        {
            printf("Must include '/' at the end of the second argument!\n");
            return 1;
        }
        else
        {
            key = argv[1];
            //Make the directory based on the user second arguments
            dir.name = argv[2];
        }
    }
    else
    {
        printf("Proper usage: ./finder string directory[optional]\n");
        return 1;
    }

    return seek(dir);
}

directory populate(directory dir)
{
    // Initialize all pointers and values in the given struct
    dir.npaths = 0;
    dir.paths = NULL;
    DIR *dirp;
    struct dirent *entry;

    dirp = opendir(dir.name);
    if (dirp == NULL)
    {
        printf("Opening directory failed. Check your input filepath!\n");
        return dir;
    }

    while ((entry = readdir(dirp)) != NULL)
    {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            // Allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 2);
            strcat(name, dir.name);
            strcat(name, entry->d_name);
            strcat(name, "/");

            // Reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types
            path newPath = {.name = name, .type = "directory"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory
            dir.npaths++;
        }

        // Else if entry is a file, increase file count and populate the struct
        else if (entry->d_type == DT_REG)
        {
            // Allocate zeroed-out memory for the construction of the file name
            string name = calloc(1, strlen(dir.name) + strlen(entry->d_name) + 1);
            strcat(name, dir.name);
            strcat(name, entry->d_name);

            // Reallocate memory to expand the array
            dir.paths = realloc(dir.paths, (dir.npaths + 1) * sizeof(path));

            // Add a new element to the array containing names and types
            path newPath = {.name = name, .type = "file"};
            dir.paths[dir.npaths] = newPath;

            // Increase file count for the directory
            dir.npaths++;
        }
    }

    // Close directory stream using system call closedir and return struct
    closedir(dirp);
    return dir;
}

// Recursive function to iterate through directories and search files
int seek(directory dir)
{
    //populate the directory
    dir = populate(dir);

    //Loop that itereates through each file
    for (int i = 0; i < dir.npaths; i++)
    {
        //Check the type if it's a file and that it isn't the same as the newly create text file
        if ((strcmp(dir.paths[i].type, "file") == 0) && (strcmp(dir.paths[i].name, "./found.txt") != 0))
        {
            //Open and read the file
            FILE *fp = fopen(dir.paths[i].name, "r");

            if (fp == NULL)
            {
                printf("Can't Open File\n");
                return 2;
            }

            char str[50];

            //Iterate through the whole file until the end of file
            for (int x = 0; fgets(str, 50, fp) != NULL; x++)
            {
                char *found_w;
                char found[50] = "/0";

                //Strstr function to find the same word as key then store in the variable
                found_w = strstr(str, key);

                //If no word is found then set the variable to each word
                if (found_w == NULL)
                {
                    found_w = str;
                }

                //Ensure to make sure that only the key is brought not the whole word
                if (strlen(found_w) > strlen(key))
                {
                    strncpy(found, found_w, strlen(key));
                }

                //Compare if the string is the same
                if (strcmp(found, key) == 0)
                {
                    //Assign a bool value to work only once
                    static bool check = true;

                    //Create a file that we can append our location to
                    FILE *outfile = fopen("found.txt", "a");

                    if (outfile == NULL)
                    {
                        printf("Can't Write to File\n");
                        return 3;
                    }

                    //Only work once since check will become false afterwards to ensure that it only write once
                    if (check == true)
                    {
                        check = false;
                        //Append the path and the location of the key to the newly create file "found.txt"
                        fputs(dir.paths[i].name, outfile);
                        //Append a new line
                        fputs("\n", outfile);
                    }

                    //Close the file
                    fclose(outfile);
                    fclose(fp);

                }
            }

        }
        else if (strcmp(dir.paths[i].type, "directory") == 0)
        {
            //Create a new directory
            directory NewDir;
            //Make the directory name the path name of where the file is
            NewDir.name = dir.paths[i].name;
            //Recurssive function to go through until a file is found
            seek(NewDir);
        }

    }

    return 0;
}
