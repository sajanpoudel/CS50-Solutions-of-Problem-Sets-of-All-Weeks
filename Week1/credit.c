// American Express : 15 digits, starts with 34 or 37
// Mastercard : 16 digits, starts with 51,52,53,54, or 55
// VISA : 13 or 16 digits, starts with 4

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //variable declaration
 int count = 1, evensum = 0, oddsum = 0, totalsum = 0, rem;
 long number;
 string cardtype;
  
//prompt user to enter their card number unit he/she enters positive number
 do
 {
   number = get_long("enter your credit card number:");
 }
while (number < 0);
long temp = number;
  
//Luhn's Algorithm
//Start from second to last digit and multiply the digit by 2, and continue to next to its corresponding digit
// For card number: 4003600000000014 =1*2 + 0*2 + 0+2 +0*2 + 0*2 +6*2 +0*2 +4*2 = 2+12+8 = 2+ (1+2) +8 = 13
//Add remaning numbers:4+3+0 = 7
// Add total: 7+13 =20 (last digit is 0, so its is valid)

 while(temp > 0)
 {
     rem = temp % 10;
     if(count % 2 == 0){
         rem = rem * 2;
         if(rem > 9)
         {
             int mod_rem = rem % 10;
             int mult_rem = rem / 10;
             rem= mod_rem + mult_rem;

         }

         evensum = evensum + rem;

     }
     else{
         oddsum = oddsum + rem;

     }
     temp = temp / 10;
     count++;
   
     
 }
   //since counts starts with 1, so actual no of digits will be count-1
  
 totalsum = oddsum + evensum;
  
//findind first two digits to check the type of card
 int test = number/pow(10,count-3);
 if(totalsum % 10 == 0)
 {
     if(count - 1 == 15 && (test == 34 || test == 37))
     {
         cardtype = "AMEX";
     }
    else if(count - 1 == 16 && (test == 51 || test == 52 || test == 53 || test == 54 ||test == 55))
    {
        cardtype ="MASTERCARD";
    }
    else if((count - 1 == 13 || count - 1 == 16) && (test / 10) == 4)
    {
        cardtype = "VISA";

    }
    else
    {
        cardtype = "INVALID";
    }
 }
else
{
    cardtype = "INVALID";
}
printf("%s\n",cardtype);

}
