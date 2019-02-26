#include <stdio.h>
#include <string.h>
int main()
{
char a[100], b[100], c[100];
printf("Enter the first string\n");
scanf("%s", a);
printf("Enterthe second string\n");
scanf("%s", b);
// incorrect way to compare two strings:
printf("------------\n");
printf("Incorrect way to compare results in:\n");
if(a == b)
printf("%s and %s are equal.\n", a, b);
else
printf("%s and %s are not equal.\n", a, b);
// correct way to compare two strings
printf("------------\n");
printf("Incorrect way to compare results in:\n");
if(strcmp(a, b) == 0)
printf("%s and %s are equal.\n", a, b);
else
printf("%s and %s are not equal.\n", a, b);
printf("------------\n");
printf("String length:\n");
printf("%s is %d in length\n", a, strlen(a));
printf("%s is %d in length\n", b, strlen(b));
printf("------------\n");
printf("Copying %s\n", a);
strcpy(c,a);
printf("Copy ofstring: %s\n", c);
printf("------------\n");
strcat(a,b);
printf("%s is the combined strings\n", a);
return 0;
}