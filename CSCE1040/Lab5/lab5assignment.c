
/*
 * Robert E Malone (darkgenezis@gmail.com & RobertMalone@my.unt.edu) 
 * October 10th 2013
 * Computer Science 1040 Sweany 
 */
 


#include <stdio.h>
#include <stdlib.h>

  void max(int x

int main() 
{ 

  char *p1[25];
  int *p2 = NULL;
  int x; 
  int i = 0;
  int max;
  int min;
  
  while(scanf("%d ", &x) !=EOF){
    p1[i] = (char *) malloc(x * sizeof(char));
    scanf("%s", p1[i]);
    printf(" %d = %s\n", x, p1[i]);
    i++;
    }


  



return 0;
}  