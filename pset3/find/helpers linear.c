/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */


    // TODO: implement a searching algorithm      
    // search(needle, haystack, size)
 
bool search(int needle, int values[], int size)
{
    for( int i = 0; i < size; i++)
    {
        if( values[i] == needle )
            {
            return false;
            }
       return i;  
    }
  return false;  
} 
   
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
   { // Implementation of Bubble Sort
    // TODO: implement an O(n^2) sorting algorithm
    
    for (int i = 0; i < n; i++)
    {
     int temp = values[i];
     int j = i;
        while (j > 0 && values[j-1] > temp)
        {
            values[j] = values[j-1];
            j = j-1;
            values[j] = temp;
        }
    
      }
   
   }
