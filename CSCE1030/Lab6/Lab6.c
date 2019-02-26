
/*
 * Robert Malone (darkgenezis@gmail.com)
 * CSCE 1030
 * 3/6/2013
 * This program asks the user to enter their drink and food then calculates the prices of each one
 */



#include <stdio.h>
#include <ctype.h>
 
int main(){

  char food, drink, member, student; // set your variables 
  int foodA, drinkA;
  float discount1, discount2, price, price1, price2, price3;
            
  printf(" Robert Malone\n");
                  
  printf("	Welcome to Geek's Restaurant		\n"); // display the menu
  printf("Type		Name		Code		Price\n");
  printf("****************************************************\n");
  printf("	       Pizza		 P		 10.0\n");
  printf("       Chicken Sandwich	        C	    7.9 \n");
  printf("Food       Noodles 		 N		 8.0 \n");
  printf("	 Kung Pao Chicken        K		 8.5 \n");
  printf("      3 Piece Beef Tacos         T 		 5.6 \n");
  printf("*****************************************************\n");        
  printf("	        Coke             C               1.5 \n");
  printf("Drink     Orange Juice           O               3.5 \n");
  printf("		Tea              T		 2.0 \n");
  printf("          Grape Juice 	       G            3.6 \n");
                                                          
  printf ("Select the Food: "); // Ask the user for the food and drink
   scanf ("%c%*c",&food);
  printf ("Select the Drink: ");
   scanf ("%c%*c",&drink);
   
  switch (food) { // Display a break command for food and drink including an error message
    case 'P' : foodA = 10.0; break;
    case 'C' : foodA = 7.9; break;
    case 'N' : foodA = 8.0; break;
    case 'K' : foodA = 8.5; break;
    case 'T' : foodA = 5.6; break;
    default  : printf("Wrong food idiot!\n");
    }
  switch (drink) {
    case 'C' : drinkA = 1.5; break;
    case 'O' : drinkA = 3.5; break;
    case 'T' : drinkA = 2.0; break;
    case 'G' : drinkA = 3.6; break;
    default  : printf("Might as well get a smoothie instead!\n");
    }
  printf("Own a membership card? ");// ask the user if they are a student or a member
   scanf("%c%*c", &member);      
  discount1 =  member == 'Y' ? .85 : 0; // display a ternary is the user says yes
                                           
  printf("Are you a student?: "); 
   scanf("%c%*c", &student);
    
   discount2 =  student == 'Y' ? .9 : 0;
     
     price = foodA + drinkA; // Set your calculations
     price1 = (discount1 * foodA) + (discount1 * drinkA);
     price2 = (discount2 * foodA) + (discount2 * drinkA);
     price3 = ((discount1 * discount2) * foodA) + ((discount1 * discount2) * drinkA);
                         
       printf("		Geek's Restaurant Receipt    \n"); // Display the recipt
       printf("Food:	%c	1	%.1d\n", food, foodA);
       printf("Drink:	  %c	  1	 %.1d\n", drink, drinkA);
       printf("Discount					\n");
       printf("		Member			-15%%\n"); 
       printf("		Student			-10%%\n");
                                                     
    if (price1 == discount1) // Use if statements to assign such total if the user was a member or student
      printf("Total Payment. %.2f\n",price1);                                                                
  else  if (price2 == discount2)
      printf("Total Payment..  %.2f\n", price2);                                                                      
 else  if (price3 == discount1 && price3 == discount2)
      printf("Total Payment... %.2f\n", price3);
  else
      printf("Total Payment   	%.2f\n",price);  
  
  
  

  return 0; 
  }