

/*
Robert Malone
Computer Science 1040
Lab 2
9/17/13
*/


 #include <stdio.h>
 #include <stdlib.h>
 
 int main(void)
 {
       char cities[10][10];   // city names
       char command;	      // command being processed
       int city1, city2;      // the cities' ids
       float distance;        // the distances

 while(scanf("%c", &command) != EOF) {
  if(command == 'c') {
    scanf("%d", &city1);
    scanf("%s", cities[city1-1]);
    printf("%c %d %s", command, city1, cities[city1-1]);
   }
   else if(command == 'a') {
    scanf("%d %d %f", &city1, &city2, &distance);
    printf("%c %d %d %f", command, city1, city2, distance);
    }
    printf("\n");
   } 

       
       return 0;
 }      