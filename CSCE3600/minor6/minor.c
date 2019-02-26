/*Robert Malone (RobertMalone@my.unt.edu)
 *CSCE 3600 Minor 6
 *11/5/16
 *
 *
 * Couldn't get my wait command to work but managed to execute and provide an error message
 */




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//enum { READ, WRITE };

#define READ 0
#define WRITE 1

int main(int argc, char *argv[]){

int fd[2];
int x;
char *chr[]={argv[1], NULL};
char *chr2[]={argv[2], NULL};



if (argc <= 2 && argc >= 2)
  {
     
     printf("error: too few or too many arguments\n");
     return EXIT_FAILURE;	
  }
 else 
  {
     printf("executing: %s | %s \n", argv[1], argv[2]);
	
  }

 switch(fork())
{
  case -1:
	perror("error \n");
        exit(2);
  case 0:

	dup2(fd[WRITE], WRITE);
	close(fd[READ]);
	close(fd[WRITE]);
        execvp(chr[0], chr);
	for(x=0; x<2; ++x)
        {
           wait(NULL);   
        }
	exit(3);  

  default: 
	dup2(fd[READ], READ);
	close(fd[WRITE]);
	close(fd[READ]);
	execvp(chr2[0], chr2);

	for(x=0; x<2; ++x)
        {
           wait(NULL);   
        }
	close(fd[WRITE]);
	exit(4);

}
//close(fd[WRITE]);

printf("command line pipe completed\n");

return 0;
}
