
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

template <class Comparable>
class BinarySearchTree
{
   public:
     BinarySearchTree();
     BinarySearchTree(const BinarySearchTree & rhs);
     ~BinarySearchTree();

     const Comparable & findMin() const;
     const Comparable & findMax() const;
     bool contains(const Comparable & x) const;
     bool isEmpty() const;
     void printTree() const;
     bool makeEmpty();
//     bool makeEmpty(){size=0;}
     void insert(const Comparable & x);
     void remove(const Comparable & x);
     const BinarySearchTree & operator=(const BinarySearchTree & rhs);



     //begin();  begin & end methods for BST
     //end();
     //checkSize();  check size of the BST function

   private:
     struct BinaryNode
     {
	Comparable element;
	BinaryNode *left;
	BinaryNode *right;
	//BinaryNode *parent; Might need parent node

	BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
	    : element(theElement), left(lt), right(rt){}

     };

//     unsigned size;
     BinaryNode *root;

     void insert(const Comparable & x, BinaryNode * & t) const;
     void remove(const Comparable & x, BinaryNode * & t) const;
     BinaryNode * findMin(BinaryNode *t) const;
     BinaryNode * findMax(BinaryNode *t) const;
     bool contains(const Comparable & x, BinaryNode *t) const;
     void makeEmpty(BinaryNode * & t);
     void printTree(BinaryNode *t) const;
     BinaryNode * close(BinaryNode *t) const;
};


//bool contains(const Comparable & x) const
//{
//   returns contains(x,root);e *t) const;
//}


//void remove(const Comparable & x)
//{
//   remove(x, root);
//}

//void insert(const Comparable & x)
//{
//   insert(x, root);
//}


//void contains(const Comparable & x, BinaryNode *t)
//{
//    if(t == NULL)
//	return false;
//    else if(x < t-element)
// 	return contains(x, t->left);
//   else if(t->element < x)
//	return contains(x, t->right);
//    else
//	return true;
//}

template<class Comparable>
BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t)
{
   if(t != NULL)
   {
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
   }
    t = NULL;
}

//template<class Comparable>
//BinarySearchTree<Comparable>::~BinarySearchTree()
//{
//    makeEmpty();
//}


int main(){


return 0;
}


 
