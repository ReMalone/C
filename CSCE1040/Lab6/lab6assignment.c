/*Robert Malone (darkgenezis@gmail.com or RobertMalone@my.unt.edu
 * 10/15/2013
 * CSCE 1040
 * Lab Assignment #6
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* noVowel(char *buffer)
{
 char y = buffer[0];
 int i;
 if( y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'o')
 return ;
 else
  for( i = 0; i < strlen(buffer) - 1; i++){
  buffer[i] = buffer[i+1]; 
  }
 buffer[i] = y;
 return noVowel(buffer);

}


int main() {
  
  char word[20];
  char vowel[21];
  

  while(scanf("%s", word) != EOF){
  
  printf("%21s", word);
  if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u'){
  strcat(word, "mida");
   }  
  else {
    noVowel(word);
    strcat(word,"fah");
    }
    printf("%21s\n", word); 
 } 
 
 return 0;
} 
