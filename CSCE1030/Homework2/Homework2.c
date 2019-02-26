



 #include <stdio.h>

 int main(){
 
   int quiz, score, average, total, counter;
    
     printf("Robert Malone Homework 2, CSCE 1030\n\n");
    
   do { // Make a do-while loop to ask to user to enter 1 to 13 for quizzes
     printf("How many quizzes have you from 1 to 13?: ");
     scanf ("%d", &quiz);
     if (quiz < 1 || quiz  > 13)
       printf("There aren't that many quizzes!\n");
   } while (quiz < 1 || quiz > 13);
  
    
  for (counter = 0; counter < quiz; counter++){ // create the for loop and ask to user for the score from the number of quizzes enter
    printf("Enter your quiz grades: ");
     scanf("%d", &score);
  
  
   while (score < 0 || score > 100){ // create a while loop if the score is out of range
    printf("Please enter your grades again: ");
     scanf("%d", &score);
    } 
 total += score; // add the total scores together
 }  
 
    average = total / quiz ; //Get the average from the total scores and number of quizzes. Divide and print the average 
     printf("Your average score from this quizzes is:  %d \n\n", average);  
    
  return 0;
}       