/*
 * =====================================================================================
 *
 *       Filename:  credit.c
 *
 *    Description:  Validate a user's creditcard number
 *
 *        Version:  1.0
 *        Created:  25.01.2017 22:10:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Ajala , 
 *   Organization:  CS50 - credit card - PSET 1 
 *
 * =====================================================================================
 */
  /* int americanExpressLength = 15; "34 or 37"; */
  /* char *13 , 16  visaStartsWith = "4"; */
  /* char *16  masterCardStartsWith = "51,52,53,54,55"; */
  
#include <stdio.h>
#include <cs50.h>
#include <math.h>
long unsigned square(int digits);

int main(void)
{
  long long creditCardNumber = 0;
  char* creditCardCompany; 
  int digits = 0;
  int sum = 0;
  long nullen;

  /* let the user type a number between 13 - 16 digits */
    do{
        printf("Enter your Number:\n");
        creditCardNumber = get_long_long();
        digits = floor(log10(labs(creditCardNumber)))+1;
    }
    while(!creditCardNumber);

    nullen = square(digits);
    switch (digits) {
        case 13:
            if (creditCardNumber/nullen == 4) {
               creditCardCompany = "VISA";
            }
            break;
        case 15:
            nullen/=10;
            if (creditCardNumber/nullen == 34||creditCardNumber/nullen == 37){
               creditCardCompany = "AMEX";
            }
            break;
        case 16:
             if (creditCardNumber/nullen == 4) {
               creditCardCompany = "VISA";
            } 
            nullen/=10;
           if (creditCardNumber/nullen == 51||creditCardNumber/nullen == 52||creditCardNumber/nullen == 53||creditCardNumber/nullen == 54||creditCardNumber/nullen == 55) {
               creditCardCompany = "MASTERCARD";
            }            
           break;
    }

    /* get the second digit of the credit card number */
    do{
        int everySecondDigit = ( creditCardNumber %100 ) / 10;
        
        everySecondDigit =  everySecondDigit * 2 ;
        if(everySecondDigit < 10){
            sum = sum + everySecondDigit;
        } else {
            sum = sum + (everySecondDigit%10) + (everySecondDigit/10);
        }
        sum = sum + ( creditCardNumber%10 );
        creditCardNumber = creditCardNumber / 100;

        digits = floor(log10(labs(creditCardNumber)))+1;
    } while(digits > 0);
    if(sum %10 == 0){
        printf("%s\n", creditCardCompany);
    } else{
        printf("INVALID\n");
    }

    return 0;
}

long unsigned square(int digits) {
    long x = 1;
    for (int i = 1; i < digits; ++i) {
       x*=10; 
    }
    return x;
}

