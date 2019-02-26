/*Robert E Malone (RobertMalone@my.unt.edu)
 *CSCE 3110
 *Program 2
 *Single List Program
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

class singleList{
  public:				   //Did not need a Private 
	struct Node
        {
          int x;
	  struct Node *next;
	  Node() {};
          void GetX(int aX) {x = aX;};
          void GetNode(Node *anext) {next = anext;};
          int X() {return x;};
          Node *Next(){return next;};
     } *head, *ptr;

   singleList(){ head = NULL;}
   ~singleList();

   int checkSizeList(struct Node *ptr);    //return the size of the list
   void printList()const;                  //Print the list
   void checkList(Node *head)const;        //Check if list is empty
   void testValueList(int );	           //Test if x value is in the list
   void addList(int x);                    // Add a value to the list
   void removeFromList(int );	           //Remove a value from the list
};

singleList::~singleList(){
  Node *current,*temp;
  current = head;
  temp = new Node;
  while(current != NULL){
       current = current->next;
       delete temp;
       temp = current;
 }
}

void singleList::addList(int x){
  Node *newNode = new Node();
  newNode->GetX(x);
  newNode->GetNode(NULL);

  Node *temp = head;

 if ( temp != NULL ) {
    while ( temp->Next() != NULL ) {
        temp = temp->Next();
    }
    temp->GetNode(newNode);
    }
    else {
    head = newNode;
    }
 cout << "Added node to the list" << endl << endl;
}

  void singleList::printList()const{

  struct Node* temp = head;
  while(temp != NULL){

   cout << temp->x << endl;
   temp=temp->next;
 }
}


void singleList::checkList(struct Node *ptr)const{
  if (!ptr){
     cout <<"The list is empty" << endl << endl;
     return;
     }
   else {
    cout << "The list is not empty" << endl << endl;
  }
 }

int singleList::checkSizeList(struct Node *ptr){
 int z = 0;
 struct Node *current = ptr;

 while(current != NULL)
  {
  z++;
  current = current->next;
  }
  return z;
}

void singleList::testValueList(int w){
  struct Node* temp = head;
  while(temp != NULL){
   if(temp->x == w){
   cout << "The number is in the list" << endl << endl;
    return;
   }
   temp = temp->next;
  }
   cout << "The number is not in the list" << endl << endl;
}

void singleList::removeFromList(int q){
 struct Node* temp = head;

 while(temp != NULL)
  {
   if(temp->x == q){
    free(temp);
  cout << "removed from list" << endl << endl;
    return;
  }
   cout <<" This number is not in the list" << endl << endl;
    return;
  }

}

int main(){

bool quit = false;
string choice;
singleList myList;
singleList::Node *head;
int numb;

while(1){
   cout <<"A Single List(Type what you want to do)" << endl
        <<"add <number>" << endl
	<<"check"<< endl
	<<"print"<< endl
	<<"size" << endl
        <<"search <number>" << endl
        <<"remove <number>" << endl
        <<"quit" << endl;
   cout <<"cmd> ";
    cin >> choice;

    if(choice == "ADD" || choice == "add"){
      cin >> numb;
      myList.addList(numb);
    }
    else if(choice == "PRINT" || choice == "print"){
      myList.printList();
    }
    else if(choice == "CHECK" || choice == "check"){
      myList.checkList(myList.head);
    }
    else if(choice == "SIZE" ||  choice == "size"){
      cout << "The size of the list is " << myList.checkSizeList(myList.head) << endl << endl;
    }
    else if(choice == "SEARCH" || choice == "search"){
      cin >> numb;
      myList.testValueList(numb);
    }
    else if(choice == "REMOVE" || choice == "remove"){
      cin >> numb;
      myList.removeFromList(numb);
    }
    else if(choice == "QUIT" || choice == "quit"){
    exit(1);
    }
     else{
    cout << "Not a command!" << endl << endl;
    }
}
return 0;
}
