#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
enum { READ, WRITE };
//#define PIPE_RD 0
//#define PIPE_WR 1

int main(int argc, char *argv[]){

int fd[2];
pid_t Pipeid;
pipe(cmd);

Pipeid = fork();
if (argc <= 3 || argc >= 3){
   perror("error: too few or too arguments: ");
  // exit(1);
  return 1;
}

if(Pipeid)
{
close(1);
dup2(argc, 1);
close(argc);
printf("executing: "); 
execvp(argv[2], &argv[2]);
}
return 0;
}

