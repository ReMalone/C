/*Robert E Malone (RobertMalone@my.unt.edu)
 *CSCE 3600 September 12th, 2016
 *Lab 01
 */



#include <stdio.h>

int main(int argc, char *argv[]){

int i;
printf("command: ");

 while(--argc > 0)
  {
   printf("%s%s", *++argv, (argc > 1)?" " :"");
   for(i=1; i<argc; ++i)
      {
       printf("Option %d: \n", argc);
      } 
  }



printf("\n");

return 0;
}

