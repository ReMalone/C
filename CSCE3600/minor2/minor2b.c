/* Robert E Malone (RobertMalone@my.unt.edu)
 * CSCE 3600 Minor 2
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{  
  char Command[80];
  char fName[30] = "";
  int x;
  int y;
  
 // printf("cmd: ");

  strcpy(Command, "du -a");
  if(argv[1] == '\0')
  {
	

for(x=2; x < strlen(argv[1]); x++)
  {
    sprintf(fName, "%s%c", fName, argv[1][x]);
  }  
    sprintf(Command, "%s%s", Command, fName);
    for(y = 2; y<argc; y++){
     if(argv[0][0] == '-' && argv[0][1] == 'g')
     {
      sprintf(Command,"%s ", Command);
      sprintf(Command, "%sgrep ", Command);

      for(x=2; x<strlen(argv[y]); x++){
      sprintf(Command, "%s%c", Command, argv[x][y]);
      }
     }

  if(argv[y][0] == '-' && argv[y][1] == 's')
    {
      sprintf(Command, "%s ", Command);
      sprintf(Command, "%ssort ", Command);
    } 
 
   if(argv[y][0] == '-' && argv[y][1] == 'o')
    {
      sprintf(Command, "%s >", Command);
      for(x=2; x<strlen(argv[y]); x++){
       sprintf(Command, "%s%c", Command, argv[y][x]);
      }
     }
    }
  printf("%s\n", Command);

    return 0;  


return 0; 
}
