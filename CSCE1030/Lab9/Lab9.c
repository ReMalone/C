
/*
 * Robert Malone
 * 4/3/2013
 * CSCE 1030
 *
 */


#include <stdio.h>
#include <string.h>

int main() {

 char First[10];
 char Middle[10];
 char Last[10];
 char Full[40];
 char i = 0;
 char str[40];
 char Newstr[40];
 printf("CSCE 1030 Lab 9 Robert Malone darkgenezis@gmail.com\n\n");
 
 printf("Enter your first name: ");
  scanf("%s",First);
 printf("Enter your middle name: ");
  scanf("%s",Middle);
 printf("Enter your last name: " );
  scanf("%s",Last);
  
  strcpy(Full,First);
  strcat(Full," ");
  strcat(Full,Middle);
  strcat(Full," ");
  strcat(Full, Last);
  printf("Welcome %s \n",Full);
  
 while(i<8){
  printf("Enter an 8 character long string: ");
   scanf("%s",str);
   i = strlen(str);
 }   
 printf("Valid String: %s \n",str);

strcpy(Newstr,str);
 str[0] = 65;
 str[1] = 98; 
 str[2] = 99;
 
 str == NULL;
  
 printf("Change a): %s\n",str);
 printf("Change b): "); 
 for (i = strlen(str)-1; i>=0;i--) 
  printf("%c",str[i]);
  printf("\n\n");
 
 
return 0;
}