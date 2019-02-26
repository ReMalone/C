#!/bin/bash
#Robert E Malone (RobertMalone@my.unt.edu)
#CSCE 3600 Minor 3 assignment

#Started with an if statement to check if the user did not enter what was needed

if [ $# -eq 0 ] 
 then
 echo "usage: minor name [euid]"  
 exit
else
 echo "Hello, $1 $2 ! Nice to meet you!"
fi

#Added while loop to ensure the case will loop when an input is an invalid
while :;
do
#Here is the menu for inputs
    echo "+*****************************************************************+
          Enter one of the following options: 				    |
	  1) List and count all non-hidden files in the current directory.  |
          2) Check if given user (default = current user) is logged in, then|
             ... list all active processes for the user.                    |
          3) Display prime factors of user-entered positive integer.        |
          4) Exit this shell script.                                        |
          +*****************************************************************+
          "
 read -p "> " CHOICE

#Case commands for a selection 1-4
 case $CHOICE in
     1|[1])  echo "Displaying all non-hidden files"
            ls -l ;;

     2|[2])  echo "Active processes for $2:"
             ps -u $2
               ;;

     3|[3])  echo "Display prime factors of user-entered intergers:"
             read -p "Enter a positive integer to find its prime factors: " Number
             factor $Number ;;

  
     4|[4])  echo "==>Exiting Shell script:"
             echo "Thanks, $1! Have a great day!"
         exit 1 ;;
      *) echo "Invalid choice! Try again"
          ;;              
esac
done
