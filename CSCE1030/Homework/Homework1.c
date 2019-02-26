


#include <stdio.h> //Begin with normal C header 

int main() {
   
 float ht, a, b, c, d, e, f, g, h, totalVolume, area1, area2, area3, area4;
 int tonnage; // Assign your varibles 

   printf("Robert Malone, darkgenezis@gmail.com , CS 1030, We will ask the use\n");
   printf("for inputs on dimensions and then calculate them for the volume of the space\n");
       
   
   printf("Please enter the Dimensions of your house\n\n");
   printf("First side a: "); // Ask the user for inputs a-h including ht
   scanf("%f", &a);
   printf("Then side b: ");
   scanf("%f", &b);
   printf("Then side c: ");
   scanf("%f", &c);
   printf("Then side d: ");
   scanf("%f", &d);
   printf("Then side e: ");
   scanf("%f", &e);
   printf("Then side f: ");
   scanf("%f", &f);
   printf("Then side g: ");
   scanf("%f", &g);
   printf("Then side h: ");
   scanf("%f", &h);
                                       
   printf("Last the height: ");
   scanf("%f", &ht); 
   
   area1 = (h*a)*ht; // Find the volume of each square in the wall
   area2 = (g*f)*ht;
   area3 = (d*c)*ht;
   area4 = (b*e)*ht;
 
 totalVolume = area1 + area2 + area3 + area4; // Add each volume sum from the square to get the total volume
  
   printf("The total volume is %.2f in Cubic feet\n", totalVolume);
   
   tonnage = totalVolume / 10000;
   printf("The proper tonnage for this home is %d ton unit\n", tonnage); // Last divide the total volume by 10000 to get the tonnage
   
 return 0;
}