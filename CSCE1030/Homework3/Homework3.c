

#include <stdio.h>
#include <string.h>

void rev(char s[]){ 
 int a,b,c;
  for (b = 0, c = strlen(s)-1; b < c; b++, c--) {
  a = s[b];
  s[b] = s[c];
   s[c] = a;
  }
  return;
}
          
 
int main(){
 
  char x[100];
  char y[100];  
  
  printf("Robert Malone CSCE 1030 darkgenezis@gmail.com\n\n");  
  printf("Enter a sentence: ");
   gets(x);
  
  strcpy(y,x);
  rev(y);
  
 if(strcasecmp(x,y)== 0)
  printf("This is a Palindrome 1\n");
   else
  printf("This is not Palindrome 0\n");   
   
  return 0;
}  