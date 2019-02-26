#include <stdio.h>
#include <string.h>


char encrypt(char str[],int offset){ // create your function for encrypting
  int x;
 
 for (x = 0; x < strlen(str); ++x) // create a for loop to get the string length
   {
    str[x] = str[x] - offset; //This equation will generate a word or symbols to what the user enters
   }
 
} 

char decrypt(char str[],int offset){ // create you function for decrypting
 int x;
 for(x = 0; x < strlen(str); ++x)
   {
    str[x] = str[x] + offset; // This equation will return the encrypting message back to its original state
   }
}    


int main(){

char ch;  // assign your varibles
char str[42] = "abcdefghijklmnopqrstuvwxyz";
int off;

 printf("Robert Malone CS1030 darkgenezis@gmail.com \n\n");

printf("Do you want to encrypt(E) or decrypt(D)?: "); // ask the user if they want to encrypt or decrypt
 scanf("%c", &ch);
printf("Enter the Offset number: ");
 scanf("%d", &off); 


 if (ch == 'E'){  // Use the if statements to call to the functions and print out what is given.
 printf("what do you wish to encrypt?: ");
  scanf("%s", str);  
 encrypt(str, off);  
 printf("Encrypyed string is %s \n", str);
 }
else if (ch == 'D'){
 printf("What do you wish to decrypt?: ");
  scanf("%s", str);
 decrypt(str, off);
 printf("The decrypted string is %s \n", str);
}
 
 
 return 0;
 }
 


