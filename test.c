/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description: test functions
 *
 *        Version:  1.0
 *        Created:  05.05.2017 20:12:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Ajala, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

int main(){
    int array[10];
    int value = 4;
    int arraySize = sizeof(array)/sizeof(int);
    int start = ( arraySize / arraySize ) -1 ;
    int mid = arraySize / 2;
    int fuck =  0;
    for (int i = 0; i < arraySize+1; ++i) {
    printf("%i\n", start);
       array[i] =  i;
       printf("array value: %i\n", array[i]);
       /* printf("%i\n", start); */
    do{
        if(array[mid] < value ){
           start = mid +1;
           mid = arraySize / (start / 2);
           printf("middle value: \t%i\n", mid); 
        } else{
            arraySize = mid -1;
        }
        
    }while(fuck);
    }
}
