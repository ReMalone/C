#Robert E Malone
#Minor 4
#Couldn't get my duplicate to work in time
#Also had trouble trying to get my SIGINT to register 3 times before
#closing 
#!/bin/bash


echo "$(date) ) intial users logged in"
num1=$(users | wc -w)

#Manage to set trap comment to exit when Ctrl-c
trap '' INT

#Used a forloop to check how many users are logged in and which users
for USER in $(who -q | grep $USER)
do   
   echo ">$USER logged in" 
   echo "$(date) ) # of users: $num1" 
   trap exit INT
   sleep 10
done

