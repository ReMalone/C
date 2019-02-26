/*Robert E Malone (RobertMalone@my.unt.edu)
 *CSCE 3110 
 *Program Assignment 1
 *9/13/17
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
using namespace std;

template <class T>
class OrderedCollection{
// private:
//  int capacity = 256;
//  T *tmp = new T[capacity];
 // size = capacity
//  contents = tmp
 public:
 OrderedCollection(){}
 ~OrderedCollection();
 bool insert(T x);
 int capacity;
 T *tmp;




};

template<class T>
OrderedCollection<T>::~OrderedCollection(){
  int capacity = 256;
 // T *tmp = new T[capacity];
}


template<class T>
bool OrderedCollection<T>::insert(T x){
  for(int y=0; y<capacity; y++){
   if(0 == tmp[y] ){
      tmp[y] = x;
      return true;
     }
    }
  T *temp = new T[capacity << 1];
  for(int y=0; y<capacity; y++){
     temp[y] = tmp[y];
    }
  capacity *= 2;
  delete[] tmp;
  tmp = temp;
}



int main(){

int InsertNum;
string choice;
bool quit = false;
OrderedCollection<int> OC;

   while(1){
	cout <<" Ordered Collection (Type what you want to do)" << endl
  	     <<"insert"<< endl  //insert
  	     <<"empty"<< endl  //make empty
             <<"check"<< endl  //check empty
  	     <<"remove"<< endl  //remove
  	     <<"min"<< endl  //find min
  	     <<"max"<< endl  //find max
             <<"print"<< endl  //print
             <<"quit"<<endl;
	cout <<"cmd> ";
         cin >> choice;

        if(choice == "INSERT" || choice == "insert"){
      //  cout << "Insert number into the collecton" << endl;
         cin >> InsertNum;
         OC.insert(InsertNum);
        }
        else if(choice == "empty" || choice == "EMPTY"){
    //     cout << "Collection is now empty" << endl;
      //   OC.makeEmpty();
        }
        else if(choice == "check" || choice == "CHECK"){
	// OC.isEmpty();
        }
        else if(choice == "remove" || choice == "REMOVE"){
      //  cout << "Enter number to remove" << endl;
	 cin >> InsertNum;
	// OC.remove(InsertNum);
	}
        else if(choice == "min" || choice == "MIN"){
     //   cout << "Printing the Minimum number in collection" << endl;
	//  OC.findMin();
	}
        else if(choice == "max" || choice == "MAX"){
    //    cout << "Printing the Maximum number in collection" << endl;
	// OC.findMax();
	}
        else if(choice == "print" || choice == "PRINT"){
//	 OC.print();
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
