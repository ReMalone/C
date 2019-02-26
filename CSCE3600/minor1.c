
/* Robert E Malone (RobertMalone@my.unt.edu)
 * CSCE 3600 Minor Assignment 1
 */

#include <stdio.h>
int main(){

 int binaryNum;
 char ASCII;

 printf("Enter an ASCII character: ");
  scanf("%c", &ASCII);

 printf("The ASCII value of %c is: \n"
        "dec -- %d \n"
	"hex -- %x \n", ASCII, ASCII, ASCII);
 printf("oct -- %o \n", ASCII);
 printf("bin -- "); 
  
 for (binaryNum = 0; binaryNum < 8; binaryNum++){
    printf("%d", !!((ASCII << binaryNum) & 0x80));
  }

 printf(" ");
 printf("\n");

return 0;
}
