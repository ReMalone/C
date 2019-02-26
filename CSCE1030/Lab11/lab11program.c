


#include <stdio.h>

//Display your matrix
void printMatrix(int mat[][13], int rows)
  {
    int x,y;
     for(x=0;x<rows;x++){
      for(y=0;y<13;y++)
       printf("%d  ",mat[x][y]);
        printf("\n");
      }
      printf("\n\n");
    }// Print the matrix

//Find the smallest in the matrix
int findMin(int mat[][13],int rows)
 {
   int i,j;
   int min = 100;
   int small;
   for(i=0;i<13;i++){
    for(j=0;j<rows;j++){
  if(mat[i][j]>small){
   small = mat[i][j];
     }
    }
   }      
  }
  
//Find the largest in the matrix
int findMax(int mat[][13], int rows)
  {
   int i,j;
   int max = 100;
   int large;
    for(i=0;i<13;i++){
     for(j=0;j<rows;j++){
      if(mat[i][j]<large){
     large = mat[i][j];
      }
     }
    }
   }
  
//Calculate the sum
int calcSum(int mat[][13], int rows)
   {
   int i,j;
   for(i=0;i<13;i++){
    for(j=0;j<rows;j++){
     printf("%d", mat[j][i]);
     }
    }
   }
   
void transposeMatrix(int mat[][13], int rows, int cols){
   int x,y;
  for(x=0;x<cols;x++){
   for(y=0;y<rows;y++){
    printf("%d\n", mat[y][x]);
    }
   }
  }  
  
int main(){

 int addTable[11][13];
 int randTable[11][13];
 int i,j;
 
 for(i=0;i<11;i++){
  for(j=0;j<13;j++){
    addTable[i][j] = i+j;
    randTable[i][j] = rand() % 100;
   }
  }  
 
  printf("\n\nRobert Malone CSCE1030 darkgenezis@gmail.com\n\n");
 
  printMatrix(addTable,11);

 
  printf("================ Random Table Operation =====================\n\n");
  printMatrix(randTable,11); 
 
 
  
 
 return 0;
 }             