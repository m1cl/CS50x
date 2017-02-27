#include <stdio.h>
#include <cs50.h>

void whitespace(int howManySpaces);
int main(void) 
{
    int height;
    do{
        height = get_int();
    } while( height < 0 || height > 24 );

    char* pyramid = "#";
    
    for (int i = 0; i < height; i++)
    {
       whitespace(height-i);
       for (int y = 0; y <= i; y++)
       {
           printf("%s", pyramid);
       }
           printf("  ");
           for (int x = 0; x <= i; x++) {
             printf("%s", pyramid);
           }
        printf("\n");
    }
}
void whitespace(int howManySpaces)
{
  char *whitespace = " ";
  for (int i = 0; i < howManySpaces; ++i) {
    printf("%s",whitespace );
  }
}
