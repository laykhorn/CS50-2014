/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
 
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 1) // Lets cover situations when our n may be less than 1, Defensive Programming.
    {
        return false;
    }
   
    sort(values, n); // Sort the values first. We need to sort before we can do Binary Search.
   
   
    // Implements a BINARY searching algorithm.
    int min = 0;
    int max = n-1;
   
    while (max >= min)
    {
        int mid = (min + max)/2; 	// Mid is our max added to min then divided by 2.
       
        if (max == min) // If the array only has one number, check that number.
        {
            if (value == values[n-1])
                return true;
        }
       
        if (max == 1) // If the array only has two numbers, check both
        {
            if (value == values[1])
                return true;
            if (value == values[0])
                return true;
        }
       
        if (value == values[mid]) 	// If number is at mid.
            return true;
           
        else if (value < values[mid])
        {
            max = mid - 1; 		//search left
        }
       
        else
        {
            min = mid + 1; 		//search right
        }
    }
    return false; 			//return false if(nothing found).
       
}
 
/**
 * Sorts array of n values.
 */
void sort(int values[ ], int n)
{
    // Bubble sort algorithm implementation.
   
    //  Needs to min off as true to keep track of swaps or nothing will happen.
    int swaps = true;
   
    // Sorting while loop. If no swaps are made swaps will remain false.
    while (swaps == true)
    {
        int temp;
        swaps = false;
        for (int i = 0; i < (n-1); i++)
        {
            if (values[i] > values[i+1])    //If Greater than the next
            {   //swap
                temp = values[i + 1];
                values[i + 1] = values[i];
                values[i] = temp;
                swaps = true;
            }
        }
    }
}
