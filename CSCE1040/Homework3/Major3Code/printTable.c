#include <stdio.h>
#include "set.h"

void printTable(int [][29], char [], int , int );

int printDFATable(int table[][29], char variables[], int initialState,
                  int finalStates[], int numRows, int numColumns)
{
   int i;
   Set finals;
   printf("\n\n\t\t\tThe DFA State Transition Table is\n\n");
   printTable(table,variables,numRows,numColumns);
   printf("The initial state is %d\n",initialState);
   clearSet(finals);
   for(i = 0; i < numRows; i++)
       if( finalStates[i] )
           add2Set(finals,i);
   printf("The set of final states is:");
   printSet(finals);
   printf("\n");
}

int printNFATable(int table[][29], char variables[], int initialState,
                  int finalState, int numRows, int numColumns)
{
   printf("\n\t\t\tThe NFA State Transition Table is\n\n");
   printTable(table,variables,numRows,numColumns+3);
   variables[numColumns] = 'e';
   variables[numColumns+1] = 'e';
   variables[numColumns+2] = 'e';
   printf("The initial state is %d\n",initialState);
   printf("The final state is %d\n",finalState);
}

void printTable(int table[][29], char v[], int rows, int cols)
{
    int i,j;

// printf header row
   printf("State number\t");
   for( j = 0; j < cols; j++)
       printf("\t%c",v[j]);
   printf("\n");

// now for the table data
   for(i = 0; i < rows; i++ )
   {
       printf("   q%d\t\t",i);
       for(j = 0; j < cols; j++)
	       if( table[i][j] != -1 )
               printf("\tq%d",table[i][j]);
           else
	       printf("\t"); 
       printf("\n");
   }
}
