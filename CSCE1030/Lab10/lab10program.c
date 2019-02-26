/* 
 * Author Robert Malone
 *Class CSCE 1030
 *4/10/2013
 *
 */




#include <stdio.h>
#define PI 3.14159F

 //Calculate the area of a circle
 float area_circle(float radius){
   if(radius < 0){
     return -1.0F;
  } else { 
   return( PI * radius * radius);
    } 
   }
 //Calculate the area of a rectangle
 float area_rect(float length, float width){
  if (length < 0||width < 0){
   return -1.0F;
   } else { 
    return (length * width);
   }
  }  
 //Calculate the area of a triangle
 float area_tri(float base, float height){
  float half = .5;
   if (base < 0 || height < 0){
    return -1.0F; }
      else { 
    return (half * base * height);
   } 
  }    
 //Display the area with validity checking
 void printArea(float area){
         if (area < 0.0F){
                printf("Invalid args!\n");
         } else {
                printf("Area= %.2f\n", area);
         }
     }      
 
 
 int main(){
  char shape;// assign variables
  float length, width, base, height, area, radius;
  int end = 0; 
   
    printf("Lab program 10 Robert Malone CS1030 \n\n");  // Set up a chart
    printf("Calculate the area of a shape given shape code and parameters. \n");
    printf("Shape codes: Circle(c|C)  Rectangle(r|R)   Triangle(t|T)       \n");
     
     do{  // Use a do while loop with a switch command to keep asking to user for shapes and numbers until it can't accept a certain shape
        printf("Enter the shape and numbers: ");
        scanf("%c",&shape);
         switch(shape){
          case 'c':
          case 'C': printf("Enter the radius: ");
                   scanf("%f%*c",&radius);
                   area = area_circle(radius);
                   printArea(area);
                   break;
          case 'r':
          case 'R': printf("Enter the length: ");
                   scanf("%f%*c", &length);
                   printf("Enter the width: ");
                   scanf("%f%*c", &width);
                    area = area_rect(length,width);
                    printArea(area);
                    break;
          case 't':
          case 'T': printf("Enter the base: ");
                    scanf("%f%*c", &base);
                    printf("Enter the height: ");
                    scanf("%f%*c", &height);
                     area = area_tri(base, height);
                     printArea(area);
                     break;
            default: printf("Invalid shape: %c(%d)\n", shape, shape);
                     end = 1;
             }
           }while(end == 0);
           
 return 0;
}                            
                                                