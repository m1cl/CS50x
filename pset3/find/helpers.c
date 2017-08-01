/*
 * =====================================================================================
 *
 *       Filename:  helpers.c
 *
 *    Description:  helper functions
 *
 *        Version:  1.0
 *        Created:  25.04.2017 12:23:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Ajala, 
 *   Organization:  CS50 
 *
 * =====================================================================================
 */
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    n = sizeof(&values)/( sizeof(int) );
    int mid = n / 2;
    int left = 0;
    do{
        if( values[mid] == value ) {
            return true;
        }
        if( values[mid] < value ){
            left = mid + 1 ;
            mid = (n - left) * 2  ;
        } else if( values[mid] > value ) {
            n = mid - 1;
            mid = n / 2;
        } else {
            return false;
        }
    } while( n > 0);

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    n = sizeof(&values) / ( sizeof(int) );
    int hiSize;
    for (int i = 0; i < n; ++i) {
        hiSize = values[i] > values[i+1] ? values[i] : values[i+1];
    }
    int arraySize[hiSize+1];
    do {
      for (int i = 0; i < hiSize; ++i) {
          arraySize[values[i]] += 1;
        }
      }
    } while(n <= 0);
    return;
}
