
/*
 *Robert Malone
 *CSCE 1030.001
 *4/15/13
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

char English[100][25];  //Assign your variables
char Spanish[100][25];
char con[25];
FILE *fp;
char ch;
char *trans;
char answer[25];
int i = 0;


 fp = fopen("words.dat", "r"); //Open your file;
 


 char Cont[100][25];
 int y = 0;
 
 while(fgets(Cont[y],25,fp) != NULL){
   y++;  
 }
 
 do{
 
 for(i=0; i<100; i++){ //Use a for loop to find the strings in the file by going through each line
  char*temp= Cont[i];
  trans = strsep(&temp, ",");
  strcpy(English[i],trans);
  strcpy(Spanish[i], temp);
   
  }
         
  printf("Enter an English String: ");  //Ask the user for a string
   scanf(" %s", con);
   
 for (i = 0; i<100; i++){  //Using a if statement to see if the user's input is in the file. It will print the translated word
 if (strcmp(con, English[i]) == 0){
   strcpy(answer, Spanish[i]);  
 printf("The translated word is %s\n", answer);
  }
 }
 
 printf("Do you wish to quit Y or N? :");
 ch = getchar();
  getchar();
 }while ( ch == 'Y' && ch == 'y');
 
 
 fclose(fp); //Close the file
               
 return 0;
}
             
             
             
             
             
             
             
             
             