// this version of Mario if feeling more comfortable
//  # #
// ## ##
//### ###

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter the number of rows");
    }
    //testing whether n is between 1 to 8 or not. else reasking the user to insert in the range
    while (n < 1 || n > 8);
    for (int i = 1; i <= n; i++) //for each row from 1 to n
    {
      for (int j = 1; j <= n-i; j++) //for each column in a row,print n-i space
       {
        printf(" ");
       }
      for(int k=1;k<=i;k++) //for each column in a row print i hashes
      {
       printf("#");
       }
      printf("  ");
      for(int l=1; l<=i;l++) //for each column in a row print i hashes
      {
        printf("#");
      }
     printf("\n");
    }
}
