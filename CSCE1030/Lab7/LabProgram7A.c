/*
 *Author: Robert Malone(darkgenezis@gmail.com)
 *Class: CSCE 1030
 *Date: 3/20/13
 * This program asks the user to input two intergers while defining
 * operators that allow the user to get a sum
 */
 
#include <stdio.h>

#define PROMPT ("Enter a number: ") // set your definitions
#define prompt ("Enter another number: ")
#define DISPLAY printf
#define ADD(num1,num2) ((num1)+(num2))
#define SUB(num1,num2) ((num1)-(num2))
#define MULT(num1,num2) ((num1)*(num2))
#define DIV(num1,num2) ((num1)/(num2))
#define MOD(num1,num2) ((num1)%(num2))

int main(){
 
 int num1, num2, sum; // Assign your variables
 char op;
 char enter;
  
  DISPLAY("Robert Malone darkgenezis@gmail.com CSCE1030 3/20/2013\n\n"); 
  
  DISPLAY (PROMPT); // call to your functions and use a scanf to input
  scanf("%d%c", &num1,&enter);
  
  DISPLAY (prompt);
  scanf("%d%c", &num2,&enter);
  
 printf("Enter an operator: "); //Ask the user for an operator
  scanf("%c", &op);
  
  switch (op) {  // Use a Switch command when the user asks for an operator that way if they input anything else it's wrong
    case '+': sum = ADD(num1,num2); DISPLAY("Result: %d + %d = %d\n ",num1,num2,sum); break;
    case '-': sum = SUB(num1,num2); DISPLAY("Result: %d - %d = %d\n ",num1,num2,sum); break;
    case '*': sum = MULT(num1,num2); DISPLAY("Result: %d * %d = %d\n ",num1,num2,sum); break;
    case '/': sum = DIV(num1,num2); DISPLAY("Result: %d / %d = %d\n ",num1,num2,sum); break;
    case '%': sum = MOD(num1,num2); DISPLAY("Result: %d %% %d = %d\n ",num1,num2,sum); break;
    default : printf(" That ain't math dummy!\n\n");
  }
  
  
return 0;
}