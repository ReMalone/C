/*Robert Malone darkgenezis@gmail.com	
 *CSCE 1030 Major Assignment 4
 *12/ 3 / 13	
 *
 */
// So far I was going to this program in c++ but decided not too. 
//As well I was going to use a header file but also decided not too
//and I thought about doing Binary search tree


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct person_d{ //Using the giving functions I was able to make my structor
 char name[30];
 int balance;
 struct person_d *next;
}person;

person* getChildren(person parent, int *numberChildren){ //Using this function I was hoping it return the children who were listed alive.
  char child[80];
  char status[30];
   char semicolon[]=";";
  char alive[]="alive";
  
  person *Root,*conductor;
  conductor=&parent;
  Root=conductor;
conductor=conductor->next; 

conductor=malloc(sizeof(conductor));
  while(1){
  
  scanf("%s",conductor->name);
  if(strcmp(conductor->name,semicolon)==0)
    return Root;

  scanf("%s",status);
  if(strcmp(status,alive)==0){ 
    conductor=conductor->next;
    conductor=malloc(sizeof(conductor)); 
    conductor->next=0;
    numberChildren++;
  }
}                
 
}

void payDecendents(person ancestor){ //Instead of using the payPerson function I was trying to figure out a way to get the alive children
  person *children;                  //by calling to get getChildren and also getting the number of them as well as the money to be distrubted
  int *numberChildren;
  *numberChildren=0;
  person array[100];
  int i;

  children=getChildren(ancestor, numberChildren);
  printf("%d",*numberChildren);
  
 
    printf("%s", children->name);
    children=children->next;
  }

//Basically I was trying to figure out a way at the point to try and read separate the strings in the from dead or alive
//In which it would count the alive and divide by the pennies in which I would distribute said money to each person
//that was alive.

int main(){
  person ancestor;
  person *children;
  int *numberChildren;
  char file[200];

  while(scanf("%s",file) != EOF) 
  {
    printf("%s\n",file);
  payDecendents(ancestor);
}
  return 0;
}
