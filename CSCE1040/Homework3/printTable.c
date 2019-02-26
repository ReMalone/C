#include "stack.h"

int printTable(int table[][26], char variables[], int initialState, 
               int finalState, int numRows, int numColumns)
{
    int i,j;

    printf("\t\t\tThe NFA in table form is:\n\n");
// printf header row

   printf("State number");
   for( j = 0; j < numColumns; j++)
       printf("\t%c",variables[j]);
   printf("\te1\te2\te3\n");

// now for the table data
   for(i = 0; i < numRows; i++ )
   {
       printf("   q%d\t",i);
       for(j = 0; j < numColumns+3; j++)
	       if( table[i][j] != -1 )
               printf("\tq%d",table[i][j]);
           else
	       printf("\t"); 
       printf("\n");
   }
   printf("The initial state is %d\n",initialState);
   printf("The final state is %d\n",finalState);
}
