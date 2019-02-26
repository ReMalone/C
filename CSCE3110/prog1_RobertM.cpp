/*Robert E Malone (RobertMalone@my.unt.edu)
 *CSCE 3110 
 *Program Assignment 1
 *9/13/17
 *
 * Ran out of time before I could truly finish. I couldn't call to my functions correctly so,
 * I'm turning in what I have.
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
class OrderedCollection{
  private:
  unsigned size;
  unsigned maxSZ;
  T *data;

  private:
  void Init();
  void Free();
  bool Invalid(int Num){return(Num >= 0 && Num < size) ? true:false;}
  void inserted(int capacity, const T &t){
    for(int x = size-1; x >= capacity; --x){
	data[x+1] = data[x];
      }
       data[capacity] = t;
     }

  public:
  OrderedCollection(){Init();}
  OrderedCollection(int total, const T &t);
  OrderedCollection(const OrderedCollection &oc);
  OrderedCollection& operator=(const OrderedCollection &oc);
  T& operator[](int Num);

  ~OrderedCollection(){Free();};

  bool isEmpty() const{return size==0;}
  bool makeEmpty(){size=0;}
  unsigned getSize() const{return size;}
  void insert(int capacity, const T &t);
  void remove(int capacity);
  bool contains(const T &t) const;
  T& findMin();
  T& findMax();

  void print()const
   {
     for(int x=0; x<size; ++x)
	cout <<  data[x] << " ";
	cout << endl;
   }


};

 template <class T>
 void OrderedCollection<T>::Init(){
   size = 0;
   maxSZ = 1;
   data = new T[maxSZ];
}

 template <class T>
 void OrderedCollection<T>::Free(){
  delete[] data;
}

 template <class T>
 OrderedCollection<T>::OrderedCollection(int total, const T &t){
  if(size == 0)
     Init();
  else
   {
      size = total;
      maxSZ = total*2;
      data = new T[maxSZ];
      for(int x=0; x<total; ++x)
       data[x] = t;
   }
}

 template <class T>
 OrderedCollection<T>::OrderedCollection(const OrderedCollection &oc){
    size = oc.size;
    maxSZ = oc.maxSZ;
    data = new T[maxSZ];
    memcpy(data, oc.data, size*sizeof(T));
}

 template <class T>
 OrderedCollection<T>& OrderedCollection<T>::operator=(const OrderedCollection<T> &t){
   if(this == &t)
     return *this;
   size = t.size;
   maxSZ = t.maxSZ;
   T *tmp = new T[maxSZ];
   memcpy(tmp, t.data, size*sizeof(T));
   delete[] data;
   data = tmp;
   return *this;
}

 template <class T>
 T& OrderedCollection<T>::operator[](int Num){
  if(Num < 0 || Num >= size){
    cout << "Out of range." << endl;
    return data[size];
  }
  return data[Num];
}

 template <class T>
 void OrderedCollection<T>::insert(int capacity, const T &t){
  if(capacity < 0 || capacity >= size){
    cout << "Not inserted" << endl;
    return;
   }
    else{
    cout << "Input inserted" << endl;
   }
   if(size < maxSZ){
   inserted(capacity, t);
   }
    else{
    maxSZ = 2*maxSZ;
    T *tmp = new T[maxSZ];
    memcpy(tmp, data, size*sizeof(t));
    delete[] data;
    data = tmp;
    inserted(capacity, t);
   }
  ++size;
}

 template <class T>
 void OrderedCollection<T>::remove(int capacity){
   if(Invalid(capacity)){
      if(capacity == size){
       --size;
      }
   else{
   for(int x = capacity; x<size; ++x)
	data[x] = data[x+1];
	--size;
       }
     }
   else{
    cout << "Nothing found, not removed" << endl;
    return;
  }
}

 template <class T>
 bool OrderedCollection<T>::contains(const T &t) const{
	int temp = 0;
	for(int x=0; x<size; ++x){
	   if(data[x] == t)
		++data;
         }
	if(temp == 1)
	   return true;
	else
	   return false;
}

 template <class T>
 T& OrderedCollection<T>::findMax(){
    int Maximum = 0;
    for(int x=0; x<size; ++x){
	if(data[Maximum] > data[x]){
	 Maximum = x;
       }
    }
   return data[Maximum];
}

 template <class T>
 T& OrderedCollection<T>::findMin(){
 T tmp;
 int Minimum = 0;
 for(int x=0; x<size; ++x){
    if(tmp < data[x]){
     tmp = data[x];
     Minimum = x;
   }
  }
 return data[Minimum];
}


int main(){

bool quit = false;
int InsertNum;
int StoreNum;
string choice;
OrderedCollection<int> Num(StoreNum, InsertNum);

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
         cin >> InsertNum;
         Num.insert(StoreNum, InsertNum);
        }
        else if(choice == "empty" || choice == "EMPTY"){
         Num.makeEmpty();
        }
        else if(choice == "check" || choice == "CHECK"){
	 Num.isEmpty();
        }
        else if(choice == "remove" || choice == "REMOVE"){
        cout << "Enter number to remove" << endl;
	 cin >> InsertNum;
	 Num.remove(InsertNum);
	}
        else if(choice == "min" || choice == "MIN"){
	 Num.findMin();
	}
        else if(choice == "max" || choice == "MAX"){
	 Num.findMax();
	}
        else if(choice == "print" || choice == "PRINT"){
	 Num.print();
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
