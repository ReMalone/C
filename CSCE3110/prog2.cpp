#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

template <class List>
class singleList{
  private:
 // List *data;
 // Test private template variable
  public:
	struct Node
	{
	   List x;   // Originally 'int x'
	   struct Node *next;
	   Node() {};
	   void GetX(int aX) {x = aX;};
	   void GetNode(Node *anext) {next = anext;};
	   int X() {return x;};
	   Node *Next(){return next;};
	} *head, *ptr;  // No tail node, set Node to public

   singleList(){head = NULL;}
   ~singleList();

   //int checkSizeList(struct Node *ptr);
   void printList()const;
   void checkList()const;   //Node *head
   void testValueList(int );
   void addList(int x);

};
//Remember to include 'template <class List> before every function
//Calling to function don't forget '<>' after the function name before '::'

template <class List>
singleList<List>::~singleList(){
  Node *current,*temp;
  current = head;
  temp = new Node;
  while(current != NULL){
	current = current->next;
	delete temp;
	temp = current;
 }
}

template <class List>
void singleList<List>::addList(int x){
  Node *newNode = new Node();
  newNode->GetX(x);
  newNode->GetNode(NULL);

  Node *temp = head;

  if(temp != NULL){
     while(temp->Next() != NULL){
	 temp = temp->Next();
     }
      temp->GetNode(newNode);
     }
      else {
	head = newNode;
     }
  cout << "Added node to the list" << endl << endl;
}



int main(){

bool quit = false;
string choice;
singleList myList;
singleList<int>::Node *head;
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

    if(){ // remember to call to the functions in the class

    }




 } 

return 0;
}