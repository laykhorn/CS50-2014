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
int min = 0, max, size;
max = size;

int findMid(min, max)
    {
    return (min + max) / 2;
    }
 
 
 
bool search(int needle, int haystack[], int size)
{
    sort(int haystack[], int size)
    if(max < min)
        return -1;
    else
    sort(haystack, size);
        int mid = findMid(min, max);
        if(haystack[mid] < needle)
            { printf("Haystack[mid] : %i < needle : %i", haystack[mid],  needle);
            min = mid +=1;
            search(needle, haystack, size);
            }
        else if( haystack[mid] > needle)
            {
            printf("Haystack[mid] : %i > needle : %i", haystack[mid],  needle);
            size = mid -= 1;            
            search(needle, haystack, size);
            }
        else
            {printf("mid: %i", mid);
            return mid;}
}  

    
/**
 * Sorts array of n values.
 */
void sort(int haystack, int size)
   { // Implementation of Bubble Sort
    // TODO: implement an O(n^2) sorting algorithm
    
    int swaps = true;
    for (int i = 0; i < size; i++)
    {
     int sorthelper = haystack[i];
     int j = i;
        while (j > 0 && haystack[j-1] > sorthelper)
        {
            haystack[j] = haystack[j-1];
            j = j-1;
            haystack[j] = sorthelper;
        }
    
      }
   
   }
