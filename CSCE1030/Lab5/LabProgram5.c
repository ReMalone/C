
/*
 *Author: Robert Malone (darkgenezis@gmail.com)
 *Class: CSCE 1030
 *Date 2/27/2013
 *This program is a currency exchange calculator, which
 *changes one country's currency to US dollars
 *
 */




#include <stdio.h>


int main(){

   int Money;  // Assign your variables
   char ch;
   float CER, USD;
   
   printf("Robert Malone CSCE 1030, darkgenezis@gmail.com\n\n");
   printf("This program is a currency exchange calculator, which\n");
   printf("changes one country's currency to US dollars\n");
   
   printf("Please enter a country name: "); // Ask the user for one the 4 country's given
    scanf("%c", &ch);
    
    if (ch == 'B') //Begin using if statements to display what the user inputs
     {
      printf(">>>Changing Brazilian currency to US dollars>>>\n");
      printf("What's today's exchange rate(USD:Brazilian): "); //Take what is given and make a chart
       scanf("%f", &CER);
      printf("How much do you want to change: ");// Ask the user for the rate and money to exchange
       scanf("%d", &Money);
      USD = Money / CER; // Calculate to see how much US dollars they will receive
      printf(" From    To        CER      Money        USD\n");
      printf("---------------------------------------------\n");
      printf("Brazil   USD       2.0301      %d        %.4f \n", Money, USD); // Print the results.
      } // Repeat for letters C, M, and A
     else if (ch == 'C')
      {
      printf(">>>Changing Canadian currency to US dollars>>>\n");
      printf("What's today's exchange rate(USD:Canadian): ");
       scanf("%f", &CER);
      printf("How much do you want to change: ");
       scanf("%d", &Money);
      USD = Money / CER;
      printf(" From    To        CER      Money        USD\n");
      printf("---------------------------------------------\n");
      printf("Canadian   USD      0.9789      %d        %.4f \n", Money, USD);
      }                                                         
     else if (ch == 'M')
      {
      printf(">>>Changing Mexican Peso to US dollars>>>\n");
      printf("What's today's exchange rate(USD:Peso): ");
       scanf("%f", &CER);
      printf("How much do you want to change: ");
       scanf("%d", &Money);
      USD = Money / CER;
      printf(" From    To        CER      Money        USD\n");
      printf("---------------------------------------------\n");
      printf(" MP   USD         13.7955      %d        %.4f \n", Money, USD);
      }
      else if (ch == 'A') // Display a negative messeage since they already have US dollars
      {
       printf("You can't a US dollar to a US dollar dummy!\n");
      }
     else // Anything else will not be accepted.
      printf("We ain't taking your money! We don't want it!\n\n"); 
                                                              
      
      
  return 0;
  
}  