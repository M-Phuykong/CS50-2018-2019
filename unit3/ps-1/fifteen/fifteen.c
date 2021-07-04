/*
Problem Set: 3-0: Fifteen
Written Partly By: Phuykong Meng

*/
// Implements Game of Fifteen (generalized to d x d)

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    //Declare the value of m to use it as a counter
    int m = 1;
    //Start a for loop to loop and assign each array a value
    for (int i = 0 ; i < d ; i++)
    {
        //Declare J to access each array in terms of i
        for (int j = 0 ; j < d ; j++)
        {
            //Assigne the value of global array "Board"
            board[i][j] = (d * d) - m;
            //Increment m by 1 after each loop
            m++;
            //Check if the board is an even number; if it is then swapped '2' and '1'
            if (d % 2 == 0)
            {
                //Change the value of the thrid to last array to 1
                board[d - 1][d - 3] = (d * d) - m + 2;
                //Change the value of the second to last array to 2
                board[d - 1][d - 2] = (d * d) - m + 3;
            }

        }
    }
}

// Prints the board in its current state
void draw(void)
{
    //A loop to print out the number from the global variable of "board"
    for (int i = 0 ; i < d ; i ++)
    {
        for (int j = 0 ; j < d ; j++)
        {
            //Convert the last character of the array into a "_"
            if (board[i][j] == 0)
            {
                printf("  _");
            }
            else
            {
                printf(" %2i", board[i][j]);
            }

        }
        printf("\n");
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    //For loop to go through the board tile
    for (int i = 0; i < d ; i ++)
    {
        for (int j = 0; j < d ; j++)
        {
            //Go into the loop once the board array matches the user's input
            if (board[i][j] == tile)
            {
                //If statement to check the right side of the board
                if (board[i][j + 1] == 0 && j - (d - 1) < 0)
                {
                    //Make another variable to store the value for later use to swap
                    int swap = board[i][j];
                    board[i][j] = board[i][j + 1];
                    board[i][j + 1] = swap;
                    return true;
                }
                //Check the left side of the board
                else if (board[i][j - 1] == 0 && j - 1 >= 0)
                {
                    int swap = board[i][j];
                    board[i][j] = board[i][j - 1];
                    board[i][j - 1] = swap;
                    return true;
                }
                //Check above the board's array
                else if (board[i - 1][j] == 0 && i - 1 >= 0)
                {
                    int swap = board[i][j];
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = swap;
                    return true;
                }
                //Check below the board's array
                else if (board[i + 1][j] == 0 && i - (d - 1) < 0)
                {
                    int swap = board[i][j];
                    board[i][j] = board[i + 1][j];
                    board[i + 1][j] = swap;
                    return true;
                }
            }
        }
    }

    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    //create a new variable as a checker
    int m = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d;  j++)
        {
            //Set a statement so that m will loop until the last grid of the board
            if (m < (d * d))
            {
                //Return false if one of the character in the board is not in the right place
                if (board[i][j] != m)
                {
                    return false;
                }
                //If it is then increment m until the if become false
                m++;
            }
        }
    }
    return true;
}