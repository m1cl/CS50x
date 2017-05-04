/*
 * =======================================================================================
 *
 *       Filename:  crack.c
 *
 *    Description:  Cracks passwords
 *
 *        Version:  1.0
 *        Created:  10.02.2017 00:18:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Ajala 
 *   Organization:  CS50  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#define _GNU_SOURCE
#include <crypt.h>

bool crack( string hash, string salt, char* array, int position );
int main(int argc, string argv[])
{
    if(argc <= 1){
        printf("Usage: ./crack hash");
        return 1;
    }
    char array[4];
    string hash = argv[1];

    bool result = crack(hash, "50", array , 0);

    if(result){
        printf("%s", array);
        return 0;
    }else{
        return 1;
    }
}

bool crack( string hash, string salt, char* array, int position ){

    string result;
    array[position+1] = '\0';

    for (char c = 65; c < 91 || c < 122; c++) { 
        c = c == 90 ? 97 : c; 

        array[position]  = c;
        result = crypt(array, salt);

        if(c < 121 && position < 3){
            crack(hash, salt, array, position +1);
        }

        if(strcmp(result,hash) == 0 ){
            return true;
        }
    }
    return false;
}    
