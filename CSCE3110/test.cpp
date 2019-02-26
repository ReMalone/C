//Robert Malone (RobertMalone@my.unt.edu)
//CSCE3110 Programming Assignment #4
//Comment: Ran of time couldn't add my other functions in time
//Managed to get it to compile however I ran into segmentation errors
//First program that has given me trouble all semester

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


 struct BinaryNode
     {
	int element;
	BinaryNode *left;
	BinaryNode *right;
        BinaryNode(int x) {element=x; left=right=NULL;}

     };

     BinaryNode *root;

class BinarySearchTree
{
   public:


     BinarySearchTree(){root = NULL;}

   //  ~BinarySearchTree();
   //  ~BinarySearchTree(){root = makeEmpty(root);}

     bool isEmpty();

     void printTree();
     void printTree(BinaryNode* t);
     void makeEmpty();

     void insert(int x, BinaryNode* t);
     void remove(int x, BinaryNode * t);
     BinaryNode* findMin(BinaryNode *t) const;
     BinaryNode* findMax(BinaryNode *t);
     int size(BinaryNode *t) const;
     void makeEmpty(BinaryNode * & t);

     //begin();  begin & end methods for BST
     //end();
     //checkSize();  check size of the BST function
};

bool BinarySearchTree::isEmpty(){
   if(root == NULL){
	return true;
   }
   else
	return false;
}

void BinarySearchTree::makeEmpty(BinaryNode * & t){
   if(t != NULL){
     makeEmpty(t->left);
     makeEmpty(t->right);
     delete t;
   }
    t = NULL;
}

void BinarySearchTree::insert(int x, BinaryNode* t){
   if(t == NULL){
	t = new BinaryNode(x);
    }
    else if (x < t->element){
        cout << "Inserted to the left";
	insert(x, t->left);
    }
    else if (t->element < x){
	cout << "Inserted to the right";
	insert(x, t->right);
    }
    else;
}

void BinarySearchTree::printTree(){
    if(isEmpty()){
	cout << "The Tree is empty";
    }
    else
	printTree(root);
}

void BinarySearchTree::printTree(BinaryNode* t){
    if(t != NULL){
        printTree(t->left);
	cout << t->element << endl;
	printTree(t->right);
    }
}


void BinarySearchTree::remove(int x, BinaryNode* t){
   if(t == NULL){
	return;
   if(x < t->element)
	remove(x, t->left);
   else if(t->element < x)
	remove(x, t->right);
   else if(t->right != NULL && t->left != NULL){
	t->element = findMax(t->left)->element;
	remove(t->element, t->left);
   }
    else{
	  BinaryNode *tempNode = t;
	  t = (t->left != NULL) ? t->left : t->right;
	  delete tempNode;
    }
 }
}

int BinarySearchTree::size(BinaryNode *t) const{
   if( t == NULL){
    cout << "No nodes can't check size" << endl;
     return 0;
   }else{
     return size(t->left) + size(t->right) + 1;
  }
}


BinaryNode* findMax(BinaryNode *t){
   if(t != NULL)
	while(t->right != NULL)
	      t = t->right;
	return t;
}

BinaryNode* findMin(BinaryNode *t){
   if(t != NULL)
	while(t->left != NULL)
	      t = t->left;
	return t;
}


int main(){

bool quit = false;
string choice;
BinarySearchTree BST;
BinaryNode *root;
int num;

   while(1){
	cout << "Binary Search Tree (Type what you want to do)" << endl
	     <<"insert <number>" << endl
	     <<"check" << endl
	     <<"size" << endl
	     <<"print" << endl
	     <<"delete" << endl
	     <<"max" << endl
	     <<"min" << endl
	     <<"quit" << endl;
        cout <<"cmd> ";
	 cin >> choice;

	if(choice == "insert"){
	   cin >> num;
	   BST.insert(num,root);
        }
	else if(choice == "check"){BST.isEmpty();}
	else if(choice == "size"){BST.size(root);}
	else if(choice == "print"){BST.printTree(root);}
	else if(choice == "delete"){BST.remove(num, root);}
	else if(choice == "max"){BST.findMax(root);}
	else if(choice == "min"){BST.findMin(root);}


	else if(choice == "quit"){
	   exit(1);
	}
	else{
	   cout << "Not a command!" << endl << endl;
	}
}

return 0;
}

