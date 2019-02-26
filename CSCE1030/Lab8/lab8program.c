/*
 *Robert Malone	
 * CSCE 1030 
 * 3/27/2013
 *
 */
 
#include <stdio.h> 
 
int main(){

 int start, end,x, num, factorial,y; // Declare your variables
 factorial = 1; 
 y = 1;
 
  printf("Robert Malone CSCE 1030 Lab 8\n\n");
  
  printf("Enter starting number: "); // Ask the user for the inputs
  scanf("%d", &start);
  printf("Enter a second number: ");
  scanf("%d", &end);
  
  
 while(start<end){ //By using a while loop start must be less than num
  for(x=0;start<end;x++){ // Use a for loop to add according to start and end
   if(start%2==1)   // Using the odd number if statement and printf command to just print the odd numbers 
     printf("%d,",start);
     start+=1;       
   } 
   printf("\n"); // Print a new line each time
  }
  
  printf("Enter a number: ");
  scanf("%d", &num);
    
  do{
   factorial *= y; // Multiply according to what the user input
   y++;
   }while(y<=num); 
  
  printf("%d! = %d\n",num,factorial); 
   
  
  
  

 return 0;
}    
 