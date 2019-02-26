
/*
 *Robert Malone
 *CSCE 1030
 *Date: 3/20/13
 *
 */
 
 
#include <stdio.h>

int main(){
 
 enum MONTHS{JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEPT,OCT,NOV,DEC} Month;
 int num;
 
 printf("Robert Malone CSCE 1030\n\n");
 
 printf("Enter a month code: ");
  scanf("%d", &num);
  
  Month = num;
  
 switch(Month){
  case 1: printf("There are 31 days in this month\n"); break;
  case 2: printf("There are 28 days in this month\n"); break;
  case 3: printf("There are 31 days in this month\n"); break;
  case 4: printf("There are 30 days in this month\n"); break;
  case 5: printf("There are 31 days in this month\n"); break;
  case 6: printf("There are 30 days in this month\n"); break;
  case 7: printf("There are 31 days in this month\n"); break;
  case 8: printf("There are 31 days in this month\n"); break;
  case 9: printf("There are 30 days in this month\n"); break;
  case 10: printf("There are 31 days in this month\n"); break;
  case 11: printf("There are 30 days in this month\n"); break;
  case 12: printf("There are 31 days in this month\n"); break;
  default: printf("Stupid Smarch weather!\n");
  }
  
return 0;
}
  