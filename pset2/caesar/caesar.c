/*
 * =====================================================================================
 *
 *       Filename:  caesar.c
 *
 *    Description:  encypts messages using Caesar's cipher
 *
 *        Version:  1.0
 *        Created:  08.02.2017 13:52:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Ajala, 
 *   Organization:  CS50 -  http://docs.cs50.net/problems/caesar/caesar.html
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
/*
 * --------------------------------------------- 
 * 1. get the key from command line argument
 * 2. turn key into integer
 * 3. prompt for plaintext
 * 4. for each character in the plaintext string
 *     preserve case
 *     shift plaintext character by key
 * 5. print ciphertext
 * --------------------------------------------- 
 * alpha wraparound
 * ================
 * 1. start with: ASCII values
 * 2. enciper: alphabetical index
 * 3. print: ASCII values
 * ---------------------------------------------
 * */
/*
 *  implement your program in a file called caesar.c in a directory called caesar.
 *  your program must accept a single command-line argument, a non-negative integer. let’s call it k for the sake of discussion.
 *  if your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
 *  you can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., 1). no need to check that it’s indeed numeric.
 *  do not assume that k will be less than or equal to 26. your program should work for all non-negative integral values of k less than 231 - 26. in other words, you don’t need to worry if your program eventually breaks if the user chooses a value for k that’s too big or almost too big to fit in an int. (recall that an int can overflow.) but, even if k is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. for instance, if k is 27, a should not become [ even though [ is 27 positions away from a in ascii, per asciichart.com; a should become b, since b is 27 positions away from a, provided you wrap around from z to a.
 *  your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
 *  your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by k positions; non-alphabetical characters should be outputted unchanged.
 *  your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
 *  After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
*/
/* islower */
/* isupper */
int main(int argc,string argv[])
{
    printf("plaintext:");
    int key = argv[1] ? atoi(argv[1]) : 0;
    if( argc == 2 ) {
        string userInput = get_string();
        printf("ciphertext:");
        for (size_t i = 0; i < strlen(userInput); ++i) {
            if(isalpha(userInput[i])){
                if(isupper(userInput[i])){
                   printf("%c",((userInput[i]-65+key)%26)+ 65);
                }
                else if(islower(userInput[i])){
                   printf("%c",((userInput[i]-97+key)%26 )+ 97);
                }
            }else{
                printf("%c", userInput[i]);
            }
        } 
        printf("\n");
        return 0;
    }else {
       printf("USAGE: ./cipher k\n");
       return 1;
    }
}
