/*
 * =====================================================================================
 *
 *       Filename:  initials.c
 *
 *    Description:  Get the user's initials
 *
 *        Version:  1.0
 *        Created:  06.02.2017 15:58:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Ajala, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Design and implement a program, initials, that, given a person’s name, prints a person’s initials. */

/* Implement your program in a file called initials.c in a directory called initials. */

/* Your program should prompt a user for their name using get_string to obtain their name as a string. */

/* You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus spaces. You don’t need to worry about names like Joseph Gordon-Levitt, Conan O’Brien, or David J. Malan! */

/* But the user’s input might be sloppy, in which case there might be one or more spaces at the start and/or end of the user’s input or even multiple spaces in a row. */

/* Your program should print the user’s initials (i.e., the first letter of each word in their name) with no spaces or periods, followed by a newline (\n). */




int main(void)
{
    string userInput = get_string();

    for(size_t i = 0; i < strlen(userInput); i++)
    {
        if(userInput[i-1] == '\0' && userInput[i] != ' '){
            printf("%c", toupper(userInput[i]));
        }else if( userInput[i] != ' ' && userInput[i-1] == ' '){
            printf("%c", toupper(userInput[i]));
        }
    }
   printf("\n");
}






