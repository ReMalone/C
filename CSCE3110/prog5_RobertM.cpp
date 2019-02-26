/* Robert Malone
 * RobertMalone@my.unt.edu
 * Program 5 CSCE 3110
 * November 10th, 2017
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int nextPrime(int n);
bool isPrime(int n);

template <typename HashedObj>
class HashTable
{

   public:
      
       explicit HashTable( int size = 101 ) : array(nextPrime(size))
        { makeEmpty();}

	bool contains( const HashedObj & x) const 
        {
	   return isActive(findPos(x));
        }

	void makeEmpty()
	{
          currentSize = 0;
          for(int i = 0; i < array.size(); i++)
            array[i].info = EMPTY;
	}


	bool insert(const HashedObj & x)
	{
          int currentPos = findPos(x);
          if(isActive(currentPos))
            return false;

          array[currentPos] = HashEntry(x, ACTIVE);
       
          if(++currentSize > array.size()/2)
            rehash();

          return true;
	}

	bool remove(const HashedObj & x)
        {
          int currentPos = findPos(x);
          if(!isActive(currentPos))
            return false;

          array[currentPos].info = DELETED;
          return true;
	}

    //    const HashTable & operator=( const HashTable & rhs );
	
	enum EntryType {ACTIVE, EMPTY, DELETED};

   private:
     struct HashEntry
     {
	HashedObj element;
	EntryType info;
      
	HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY)
	 :element(e), info(i){}
     };

    vector<HashEntry> array;
 //   vector<list<HashedObj> > oldLists = theLists;
    int currentSize;

    bool isActive(int currentPos) const
    {
	return array[ currentPos ].info == ACTIVE;
    }

    int findPos( const HashedObj & x) const
    {
        int offset = 1;
        int currentPos = myhash(x);

        while( array[currentPos].info != EMPTY &&
                array[currentPos].element != x)
        {
            currentPos += offset; 
            offset += 2;
            if(currentPos >= array.size())
                currentPos -= array.size();
        }

        return currentPos;
    }

    void rehash()
    {
        vector<HashEntry> oldArray = array;
        array.resize(nextPrime(2*oldArray.size()));
        for( int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

        currentSize = 0;
        for(int i = 0; i < oldArray.size(); i++)
            if(oldArray[i].info == ACTIVE)
                insert(oldArray[i].element);
    }

    size_t myhash(const HashedObj & x ) const
    {
       static hash<HashedObj> TestHash;
       return TestHash(x) % array.size();
    }
};

int hash(const string & key);
int hash(int key);

int nextPrime(int n)
{
    if( n % 2 == 0 )
        ++n;

    for(;!isPrime( n ); n += 2)
        ;
    return n;
}

bool isPrime(int n)
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}


int main(){ 
  const int NUM = 9999;
  const int COL = 21;
  int y;
  HashTable<int> Hash1;
  HashTable<int> Hash2;
   

//int rand;
//rand();


  cout <<"Checking however if there are no more outputs. It's a success" << endl;

  for(y=COL; y!=0; y=(y+COL) % NUM)
	Hash1.insert(y);
  Hash2 = Hash1;

  for(y=1; y<NUM; y += 2)
	Hash2.remove(y);

  for(y=2; y<NUM; y += 2)
        if(!Hash2.contains(y))
	 cout << "Failed Collision" << y << endl;

  for(y=1; y<NUM; y += 2)
  {
	if(Hash2.contains(y))
	  cout<<"Error" << y << endl;
  }
  
  


return 0;
}