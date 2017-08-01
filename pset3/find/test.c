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

// TODO: mid kommt auf 10, arrayMaxIndex is 9, d.h. auf values[mid] liegt der variabel value FIXME
int main(){
    int values[20] = {1,6,9,40,55,66,77,88,92,100,323,344, 412, 542,699,711,722,733};
    int right = sizeof(values)/( sizeof(int) );
    int mid = right / 2;
    int left = 0;
    int value = 118;

    do{
        if(values[mid] == value){
          printf("TRUE\n");
            return 1;
        }
        if( values[mid] < value ){
            left = mid + 1;
            mid = (right - left) * 2 ;
        } else if(values[mid] > value ) {
            right = mid - 1;
            mid = right / 2;
        } else {
          printf("FALSE\n");
            return 0;
        }
    } while(right > 0);
    printf("FALSE\n");
    return 0;
}
