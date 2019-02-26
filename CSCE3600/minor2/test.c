#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ******************************************************************
//   Here's a "quick and dirty" assignment for you.  Write a program
//   that will take a command line and "parse" the arguments.  So,
//   we'll assume that your command line
//   looks something like:
//
//      pgmName  options
//
//   for example,  it might be
//
//   ls -ltga
//
//   What your program should do is 1) list the pgm name (ls in this
//   example) and each of the options (l, t, g, a) on separate lines.
//
//   We'll assume that each command has one set of options that start
//   the '-' character and includes each option as a single letter.
//
//   So, we could have sort -n, but not sort --key=1 since that wouldn't
//   fit our model at this point.
//
// ***********************************************************************

int main(int argc, char** argv)
{
  int j;
  //Check if atleast 2 attributes have been passed.
  if(argv[1] && argv[2]){
    printf("========START========\n");
    printf("PROGRAM NAME: %s\n",argv[1]);
    //FOR LOOP FOR argv[2]
    //EACH CHARACTER ON NEW LINE
    //Loop through char array looking for null terminatting character
    if(argv[2][0] == '-' && argv[2][1] == '-'){
      //Do not parse
      printf("Invalid Command\n");
    } else {
      for( j = 0; argv[2][j] != '\0'; j++)
	{
	  //Check for '-', don't print
	  if(argv[2][j] != '-') {
	    //else print
	    printf("Option #%u: %c\n", j,argv[2][j]);
	  }
	}
    }
    printf("========FINISH========\n");
    return;
  } else {
    //Not enough attrs
    printf("Not enough arguments. please have 'pgName options'\n");
    return;
  }
}