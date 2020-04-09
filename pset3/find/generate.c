/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Verify the command-line arguments If its 2 or 3. This allows us to input the required argv[1] which is the no of Pseudorandom numbers and optional argc[2] which is the seed.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // This line includes the atoi() function which converts the string in the command-line argument in braces to an integer
    int n = atoi(argv[1]);

    // If we have two command-line argument which implies that we have s, then implement the function srand48 on argv[2] after converting it into an integer else implement srand48 and compute s as NULL
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // A for loop, initialize i to 0, for i < argv[1] as an integer, multiply int drand48() by LIMIT -- 65536   
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
