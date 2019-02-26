#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrone(char buffer[], int first, int last)
{


  if (first >= last)
   return 1;
  else if (buffer[first] != buffer[last])
   return 0;
  else if (buffer[first] == buffer[last])
   return isPalindrone(buffer, first+1, last-1);
}
           
int main()
{
  char word[80];
  
  scanf("%s", word);
  printf("%s\n", word);
  if(isPalindrone(word, 0, strlen(word)-1))
    printf("Yes, %s is a palindrone!\n",word);
  else
    printf("No, %s is not a palindrone.\n",word);
// return 0;
}


//int isPalidrome(char buffer[], int first, int last)
//{
 //if (first >= last)
 // return 1;
// else if (buffer[first] != buffer[last])
//  return 0;
// else if (buffer[first] == buffer[last])
 // return isPalindrome(buffer, first+1, last-1); 
//}