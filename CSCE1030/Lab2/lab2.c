#include <stdio.h>

 int main() {

  int Income; // Create your variables according the assignment.
  float IncomeTax, SStax, Med, Net, NewIncome;

  printf("Robert Malone CSCE 1030, darkgenezis@gmail.com\n"); // Starting off with who I am

  printf("How much money do you make a month?: "); // Ask the user how much income they make
   scanf("%d",&Income);

 IncomeTax = Income * .05; 
  printf(" %.2f Has been deducted from your Income due to taxs!\n", IncomeTax); //Displays how much the user loses.
 
 SStax = Income * .0765; 
  printf("%.2f Has been deducted from your Income due to SS!\n", SStax); //Continues to display the loss
 
 NewIncome = Income - IncomeTax - SStax; // The taxes will be deducted from your current Income to make a temp new one
 Med = NewIncome  - 300; // Take away $300 due to med and Dental
  printf("$300 has been deducted due to medical and dental!\n"); //Simply subtract med and dental since they are the same
  
 Net = Med; //Since net pay is the full amount after taxes have been deducted set Med equal to Net
  printf("You now have this much money left after the taxes have been deducted: %.2f \n", Net); //Lastly display the total income
       
  

return 0;
}
