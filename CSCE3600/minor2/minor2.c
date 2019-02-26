/* Robert E Malone (RobertMalone@my.unt.edu)
 * CSCE 3600 Minor 2
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{  
  int x;
  char var[80];
  char output[30];
  
  for(x=0; x<80; x++){
    var[x]= '\0';
  }

   strcpy(var, argv[1]);

     
 
return 0; 
}
