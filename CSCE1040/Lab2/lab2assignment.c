
/*
Robert E Malone & Dashone Kelly
CS 1040
Lab 2 assignment
09/17/13

*/


  #include <stdio.h>
  #include <stdlib.h>
  
  int main(void)
  {
    char name[50][50]; // names
    char command;
    char sym[50][10];
    float percent;
    float high, low, closing;
    int marketCap;
    float stockVal;
    float change;
    
    
     int index = 0;
     
 while(scanf("%c", &command) != EOF) {
    if(command == 'p' || command == 'n') {
             scanf("%s", sym[index]);
             scanf("%f", &high);
             scanf("%f", &low);
             scanf("%f", &closing);
             scanf("%d", &marketCap);
             scanf("%f", &stockVal);
             scanf("%f", &percent);
      printf("%c %s %f %f %f %d %f %f", command, sym[index], high, low, closing, marketCap, stockVal, percent);
   }
   else if (command == 's') {
    scanf("%s %f %f %f %d", sym[index], &high, &low, &closing, &marketCap);
    printf("%c %s %f %f %f %d", command, sym[index], high, low, closing, marketCap);
    }// end of if
        
   printf("\n");
   } // end of while
   
   
  return 0;
  } 