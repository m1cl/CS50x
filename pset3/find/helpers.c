/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int arraySize = sizeof(&values)/sizeof(int);
    int mid;
    int start;
    if (n < 0) {
        return false;
    }
    for (int i = 0; i < arraySize; ++i) {
        mid = arraySize/2;
        if( values[mid] < value ){
            mid = ( mid - 1 ) / 2;
        } else {
            start = mid;
        }
    }
    return true;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
