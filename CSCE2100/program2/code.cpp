#include<iostream>
#include<string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Using struct


struct Node{
    string data;
    Node *next;
   // static int ID = 0;
 //  int generateID(){
   //   static int s_itemID = 0;
    //  return s_itemID++;
   // }
  
};

//class IDGenerator
//{
//private:
  //  static int s_nNextID;
    
 
//public:
  //   static int GetNextID() { return s_nNextID++; }
//};
 
//int IDGenerator::s_nNextID = 1;

//class Something
//{
//private:
  //  static int s_nIDGenerator;
    //int m_nID;
//public:
 //  Something() { m_nID = s_nIDGenerator++; }
 
   // int GetID() const { return m_nID; }
//};
 
//int Something::s_nIDGenerator = 1;

class IDMaker
{
 private:
    static int s_nNextID;
    static int s_nIDGenerator;
    int m_nID;
 public:
    static int GetNextID() { return s_nNextID++;}
    IDMaker() { m_nID = s_nIDGenerator++;}
    int GetID() const {return m_nID;}
};
  int IDMaker::s_nNextID = 1;
  int IDMaker::s_nIDGenerator = 1;



//void generateId()
void addList(Node *head);
void deleteFromList(Node *head);
void printList(Node *head);
void searchList(Node *head);
void SortList(Node *head);
void RemoveDuplicates(Node *head);
void File(Node *head);

int main(){
    bool quit = false;
    int choice;
  //  string data;
    Node *head = new Node;
    head->next = NULL;

    while (!quit){
       cout << "ADDRESS BOOK" << endl
            << "1. ADD" << endl
            << "2. DELETE" << endl
            << "3. PRINT" << endl
            << "4. Search" << endl
            << "5. QUIT" << endl;
        cin >> choice;
        switch(choice){
        case 1: addList(head);
            break;
        case 2: deleteFromList(head);
            break;
        case 3: SortList(head);
            //RemoveDuplicates(head);
            printList(head);
            break;
        case 4: searchList(head);
            break;
        case 5: quit = true;
            break;
        default:
            cout << "Quitting the Program";
            quit = true;
        }
    }
 return 0;
}

void RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node *current=head,*temp;
    if(head == NULL)return ;
    if(head->next == NULL) return ;
    else {
       while(current->next != NULL){
           
           if(current->data == current->next->data){
               temp = current->next->next;
               current->next = temp;
               cout << "Duplicate: " << temp << endl;
           }
           else
           current=current->next;
       }
        return;
    }
    
}



void addList(Node *head){
    bool quit = false;
    string temp;
    Node *current;
    IDMaker id;
    while (head != NULL){

        cout << "ADD  ";
        cin >> temp;
        cout << "ADDED: ID " << setw(3) << setfill('0') << id.GetID() << " "<< temp << endl << endl;
       
  
       
            current = new Node;
            current->data = temp;

            current->next = head->next;
            head->next = current;
	   return;
             

    }


}


void deleteFromList(Node *head){
    string deletion;
    cout << "REMOVE ";
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
        cout << "ERROR: Not Found for Removal:" << deletion << endl;
    }
}

void printList(Node *head){
    if (!head->next)
    {
        cout << "NO NAMES IN LIST" << endl;
        return;
    }

    Node *current;
    current = head->next;
    IDMaker id;
    while (current)  
     {
        //cout << current->data << endl;
        cout << "ID: " << setw(3) << setfill('0') << id.GetID() << " "<< current->data << endl << endl;
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

void searchList(Node *head){
    Node *current;
    string search;
 	  cout << "SEARCH: ";
          cin >> search;
    

    while(current != NULL){
  
       if(current->data == search){
       current = current->next;
       cout << "TRUE: " << search << " " << endl;
       return;
         }
        current = current->next;
    }
 
    cout << "FALSE: " << search << endl;
}


