/*
 * =====================================================================================
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

void crack(string userInput, int digits);
int main(int argc, string argv[])
{
    string hash = argv[1];
    if(argc == 2){
        crack( hash, 0 );
    }else{
        printf("NOPE\n");
        return 1;
    }
    return 0;
}
void crack(string userInput, int digits ){
    /* int *chars = 0; */
    string salt = "50";
    char secret[5];
    string secretCrypted;
    for (size_t i = 0; i < strlen(secret); ++i) {
        for (char c = 65; c < 122; ++c) {
           if(isalpha(c) && digits < 5){
               if(islower(c)){
                   secret[i] = c;
                   printf("%s\n",secret );
                   secretCrypted =crypt(secret, salt)
               }else if(isupper(c)){
                   secret[i] = c;
                   printf("%s\n",secret );
                   secretCrypted =crypt(secret, salt)
               }
           }
        }
    }
    if(userInput == secretCrypted){
        printf("yuju");
    }
}
