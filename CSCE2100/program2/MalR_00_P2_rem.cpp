#include<iostream>
#include<string>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
using namespace std;
/*Robert E Malone Program 2
  CSCE 2100 
  RobertMalone@my.unt.edu Whoever grades my code please email me what I did right/wrong
	                      I really want to know.

Update 10/18: So even with the week extended once again I could not find a way to fix my ID problem
I tried switching my original struct code to a class when a member in my group told me too. 
It did work for the ID part however when I tried to convert my sorting algorithmm, duplicate, and removing things. It failed.
I thought it would be best for me to keep my original code for now and turn it in the way I planned
hoping someone could help me figure out what I did wrong. By programming assignment 3 I hope to have this problem
sorted out.					  
*/					


struct Node{           
    string data;
    Node *next;
    int id;
};

/* Trying to get the ID was a tricky part for me. I could get each string to
have an ID but I coundl't find a way to store it. */

class UniqueID {                        
private:
    int count;
	Node *top;
	Node *bottom;
public:
   int getID(){
	    Node* temp;
		id=id+count;
	   if(count == 0)
			{
				top=bottom=temp;
				temp->next = NULL;
				count++;
			}
			else
			{
				bottom->next =temp;
				bottom=temp;
				temp->next = NULL;
				count++;
			}
	   return id;
   }
};


/* Trying to find a duplicate as well as delete it also took me sometime
I included the output to inform the user that a duplicate was found and removed */

void RemoveDuplicates(Node *head){
	
Node *pLastNode = NULL;
	while(head)
	{
		if(pLastNode && pLastNode->data == head->data)
		{

			Node *DupNode = head;
			pLastNode->next = head->next;
			delete DupNode;
			head = pLastNode->next;
                        cout << "Duplicate" <<  endl;
			continue;
		}
		else
		{
			pLastNode = head;
			head = head->next;
		}
       }
	
}

void addList(Node *head)
{
    bool quit = false;
    string temp;
    Node *current;
	int id = 1;
    UniqueID a;
	
    while (head)
	{

       cout << "ADD  ";
        cin >> temp;
		
            current = new Node;
            current->data = temp;
            current->next = head->next;
            head->next = current;
            cout << "ADDED: ID " << setw(3) << setfill('0') << a.id << " "<< temp << endl << endl;
	        return;
        
    }

}


void deleteFromList(Node *head){
    string deletion;
    cin >> deletion;

    Node *prev = head;
    Node *current = head->next;

    while (current)
    {
        if (current->data == deletion){
            prev->next = current->next;
            delete current;
            cout << "Removal Successful: " << deletion << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    if (!current){
        cout << "ERROR: Not Found for Removal: " << deletion << endl;
    }
}
/* In my print list I found that the indentifiers I gave the strings countinued to add
as they were printed. I expect points off for this, but I would like to know what I did wrong*/

void printList(Node *head){
    if (!head->next)
    {
        cout << "NO NAMES IN LIST" << endl;
        return;
    }

    Node *current;
    current = head->next;
    UniqueID a;
     while (current)  
     {
        cout << "ID: " << setw(3) << setfill('0') <<  a.id << " "<< current->data << endl << endl;
        current = current->next;
     }
         
    
}

void SortList(Node *head){

    for(Node *current=head; current->next != NULL; current = current->next)
    {
      for(Node *prev = current->next; prev !=NULL; prev = prev->next)
        {
           if(current->data > prev->data)
            {
               string temp = current->data;
	           current->data = prev->data;
	           prev->data = temp;
            }
        }
    }
}

void searchList(Node *head)
{
    Node *current;
    string search;
 	  cout << "SEARCH: ";
          cin >> search;
    

    while(current != NULL)
	{
  
       if(current->data == search)
	   {
       current = current->next;
       cout << "TRUE: " << search << " " << endl;
       return;
       }
        current = current->next;
    }
 
    cout << "FALSE: " << search << endl;
}

/* I couldn't find a way to get the csv file to open as now it will always 
 tell the user that the file can not open. I also understand that I will get 
 points off for this. My problem was trying to find a way to get the file to 
 open as well as read the commands*/


void File(Node *head)
{
  Node *current;
  current = new Node;
  string filename;

  getline(cin, filename);
  fstream file(filename.c_str());
   
    if(!file)
	{
     cout << "ERROR: Can't open input File" << endl;
     return;
    }
     else
    {
        cout << "The List Contains the Following: \n";

        while(current != NULL)
        {
            cout<< current->next <<endl;
            current = current->next;
        }
    }  
}


void addList(Node *head);
void deleteFromList(Node *head);
void printList(Node *head);
void searchList(Node *head);
void SortList(Node *head);
void RemoveDuplicates(Node *head);
void File(Node *head);

/* I used if and else statements for the input. Since we weren't allowed to used
the case and switch commands. Which won't let us use strings rather than numbers. I 
felt it this was the best way to receive an upper case and lower input from the user */


int main(){

bool quit = false;
string choice;
Node *head = new Node;
head->next = NULL;



while(1){
    cout << "Robert's ADDRESS BOOK" << endl
         << "add <name>" << endl
         << "search <name>" << endl
         << "remove <name>" << endl
         << "print" << endl
         << "file <filename>" << endl
         << "quit" << endl;
    cout << "cmd> ";
     cin >> choice;


	  if(choice == "ADD" || choice == "add"){		
			addList(head);
                        RemoveDuplicates(head);
	  }

	  else if(choice == "PRINT" || choice == "print"){
		        SortList(head);
			printList(head);
          }         

	  else if(choice == "SEARCH" || choice == "search"){
                        searchList(head);

          }
          
          else if(choice == "REMOVE" || choice == "remove"){
                        deleteFromList(head);
	  }
          
          else if(choice == "FILE" || choice == "file"){
                        File(head);
          }
	
          else if(choice == "QUIT" || choice == "quit"){
                        exit(1);
          }
           else{
                   cout << "Not a command!" << endl;
                }
         }
return 0;
}