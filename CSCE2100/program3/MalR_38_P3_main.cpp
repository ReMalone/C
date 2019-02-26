/*Program 3. For this program I used classes instead of structs and I found it to be much easier.
I reused somethings from program 2 and old class exams from old programs. As well I figured out
why I couldn't open my file from program 2 was because I forget to include '#include<fstream> and
<istream>. However even when I got the file to open I couldn't get it to read all my other inputs
as well as I couldn't get the search function to work, but I managed to get my ID's to work. 
Also please rename the file to "Prog3_Test.csv" that is how I got mines to open for some reason. Robert Malone*/

#include <iostream>
#include <istream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
using namespace std;

class Name{
   private:
	string Firstname;
	
   public:
	Name(){
	Firstname=' ';
	}
	
    void setFirstname(string data){
	Firstname = data;
    }
	
	string getFirstname(){
	return Firstname;
	}
};

class Information{
   private:

    string ID;
    string StreetName;
    string city;
    string zipcode;
    string state;
    string Birthdate;
    string Deathdate;
    string Weddate;
    Name* temp;
   
   public:   

 Information(){
 Birthdate=Deathdate=Weddate=state=zipcode=city=StreetName = "";
 }
 
 void setID(string theID){
   ID=theID;
 }
 
 void setName(Name* tmp){
  temp = tmp;
 }
 string getName();
 
 string getDeath(){
   return Deathdate;
 }
 
 string getWed(){
   return Weddate;
 }
 
 string getCity(){
   return city;
 }
 
 string getBirth(){
   return Birthdate;
 }
 
 string getState(){
   return state;
 }
 
 string getZip(){
   return zipcode;
 }
 
 string getStreet(){
   return StreetName;
 }

 string getID(){
  return ID;
}
 
 void setDeath(string data){
    Deathdate = data; 
 }
 
 void setBirth(string data){
    Birthdate = data; 
 }
 
 void setWed(string data){
    Weddate = data;
 }
 
 void setState(string data){
   state = data;
 }
 
 void setZip(string data){
   zipcode = data;
 }
 
 void setCity(string data){
   city = data;
 }
 
 void setStreet(string data){
   StreetName = data;
 }
 
};

class myFamily{
    private:
	  Information* top;
	  Information* Child[3];
	  Information* Spouse;
	  int countChild;

    public:
	  myFamily(){
	   countChild = 0;
	   Spouse = Child[0]=Child[1]=Child[2]= NULL;
	  }
	
     Information* getTop(){
	   return top;
	 }
	 
	 Information* getSpouse(){
	   return Spouse;
	 }
	 
	 Information* getChild(int num){
	   return Child[num];
	 }
	 
	 int getCount(){
	  return countChild;
	 }
	 
	 void setTop(Information* tmp){
	   top = tmp;
	 }
	 
	 void setSpouse(Information* tmp){
	   Spouse = tmp;
	 }
	 
	 void setChild(Information* tmp){
	  Child[countChild] = tmp;
	  countChild++;
	 }
	 
};

void addList(list<myFamily> &address, string data);
void printAll(list<myFamily> &address);
void printList(list<myFamily>::iterator Rat1);
void File(list<myFamily> &address);
string makestream(int num);
list<myFamily>::iterator SearchByID(list<myFamily> &address, string data);
list<myFamily>::iterator Search(list<myFamily> &address, string data);

string Information::getName()
{  
   string data;
   data = temp->getFirstname();
   return data;
}

string makestring(int num)
{
	stringstream ss;
	ss<<num;
	return ss.str();
}

void addList(list<myFamily> &address, string data){


 //int id = 0;
 static int ID = 0;
 string unqid;
 Name* point1;
 myFamily* point2;
 Information* point3;
 list<myFamily>::iterator Rat1;


 point1 = new Name;
 point2 = new myFamily;
 point3 = new Information;

 Rat1 = Search(address, data);
 
 if(Rat1 != address.end()){
  cout <<"DUPLICATE"  << endl;
  return;
 }

 ID++;
 point1->setFirstname(data); 

 if(ID < 10)
  unqid = "ID00" + makestring(ID);
 else if(ID < 100)
  unqid = "ID0" + makestring(ID);
 else
  unqid = "ID" + makestring(ID);
 
  point2->setTop(point3);
  point2->getTop()->setID(unqid);
  point2->getTop()->setName(point1);
  
  if(address.empty())
   address.insert(address.begin(), *point2);
   
   else{ 
   for(Rat1 = address.begin(); Rat1 != address.end(); Rat1++)
     if(Rat1->getTop()->getName() >= point1->getFirstname()){
	    address.insert(Rat1, *point2);
		break;
	    }
         if(Rat1 == address.end())
	     address.insert(Rat1, *point2);
		} 

	cout<<"ADDED: "	<< point2->getTop()->getName() << " UID: " << unqid << endl;
}

list<myFamily>::iterator Search(list<myFamily> &address, string data){

  list<myFamily>::iterator Rat1;
 
  if(address.empty()){
	return address.end();
  }
 
  for(Rat1 = address.begin(); Rat1 != address.end(); Rat1++)
    if(Rat1->getTop()->getName()== data)
       return Rat1;	
       
    if(Rat1 == address.end())
	  return address.end();
}

list<myFamily>::iterator SearchByID(list<myFamily> &address, string data){

  list<myFamily>::iterator Rat1;
   
  if(address.empty()){
	return address.end();
  }
 
  for(Rat1 = address.begin(); Rat1 != address.end(); Rat1++)
    if(Rat1->getTop()->getID()== data)
       return Rat1;	
       
    if(Rat1 == address.end())
	  return address.end();
}

void printAll(list<myFamily> &address){

 list<myFamily>::iterator Rat1;
 
  for(Rat1 = address.begin(); Rat1 != address.end(); Rat1++)
    cout<< Rat1->getTop()->getName() << "UID: " << Rat1->getTop()->getID()<< endl;
 
}

void printList(list<myFamily>::iterator Rat1){

 Information* tmp;
 tmp = Rat1->getTop();
 int count  = 0;

    cout << endl;
    cout << "UID: " << tmp->getID() << endl;
    cout << "NAME: "<< tmp->getName() << endl;
    cout << "ADDRESS1: " << tmp->getStreet() << endl;
    cout << "CITY: "<< tmp->getCity() << endl;
    cout << "STATE: " << tmp->getState() << endl;
    cout << "ZIP: "<< tmp->getZip() << endl;
    cout << "DATE_BIRTH: " << tmp->getBirth() << endl;
    cout << "DATE_WEDDING: " << tmp->getWed() << endl;
    cout << "DATE_DEATH: "<< tmp->getDeath() << endl;
 
    if(Rat1->getSpouse() != NULL){
	    cout<< "SPOUSE: " << Rat1->getSpouse()->getName() << endl;
	}
    if(Rat1->getChild(0) != NULL){
	 for(count = 0; count < Rat1->getCount(); count++){
	    cout<< "CHILD: " << Rat1->getChild(count)->getName() << endl;
	  }
	}
	cout << endl;
	return;

}

 void File(list<myFamily> &address){
	  list<myFamily>::iterator Rat1, Rat2;
	 int swit; 
     string choice, tmp, OPFile, data;
	 fstream TheFile;
	 
	 cout<< "Filename> ";
	 cin>> OPFile;
	 TheFile.open(OPFile.c_str());
	 
	 if(TheFile.fail()){
		cout << "Can't open" << endl;
		return;
	 }
	 
	 do{	 
		swit = 0;
        getline(TheFile, choice, ',');
		
	 if(choice == "add"){
		getline(TheFile,choice,',');
	 if(choice == "name")
      swit = 1;
     else if(choice == "child")
      swit = 2;
     else if(choice == "spouse")
      swit = 3;
     else if(choice == "zip")
      swit = 4;
     else if(choice == "state")
      swit = 5;
     else if(choice == "address1")
      swit = 6;
     else if(choice == "date_birth")
      swit = 7;
     else if(choice == "date_wedding")
      swit = 8;
     else if(choice == "date_death")
      swit = 9;
     else if(choice == "city")
      swit = 10;
     }
     else if(choice == "commands")
    swit = 11;
     else if(choice == "search") 
    swit = 12;
     else if(choice == "print") 
    swit = 13;
     else if(choice == "file") 
    swit = 14;
     else if(choice == "quit") 
    swit = 15;
     else swit = 16;
	 
	getline(TheFile,tmp,','); 

    switch(swit){	
	
	case 1:
     addList(address, tmp);
	 TheFile.ignore(256,'\n');
    break;
   
    case 2:
    Rat1 = SearchByID(address,tmp);
    getline(TheFile, tmp, '\n');
    
      Rat2 = Search(address,tmp);
     if(Rat2!=address.end())
      Rat1->setChild(Rat2->getTop());
      else
      {
        addList(address,tmp);
        Rat2 = Search(address,tmp);
        Rat1->setChild(Rat2->getTop());
      } 

    break;

	case 3:

    Rat1 = SearchByID(address,tmp);
	getline(TheFile, tmp, '\n');
    Rat2 = Search(address,tmp);
    
    if(Rat2 != address.end()){
    Rat1->setSpouse(Rat2->getTop());
  //  Rat2->setSpouse(Rat1->getTop());
    }
    else
    {
     addList(address,tmp);
     Rat2=Search(address,tmp);
     Rat1->setSpouse(Rat2->getTop());
   //  Rat2->setSpouse(Rat1->getTop());
    }

    break;
	
	  
    case 4:
     
      Rat1 = SearchByID(address,tmp); 
	  getline(TheFile,tmp,'\n');
      Rat1->getTop()->setZip(tmp);
      cout << "ADDED ZIP: " << Rat1->getTop()->getZip() << " UID: " << Rat1->getTop()->getID() << endl;
    break;
	   
    case 5:
      cin >> tmp;
      if((tmp < "ID001") || (tmp > "ID999")){
       break;
       }
      Rat1 = SearchByID(address,tmp);

      if(Rat1 == address.end()){
      break;
      }
   
	  getline(TheFile,tmp,'\n');
      Rat1->getTop()->setState(tmp);
      cout << "ADDED STATE: " << Rat1->getTop()->getState() << " UID: " << Rat1->getTop()->getID() << endl;
    break;
	  
    case 6:

     Rat1=SearchByID(address,tmp);
     getline(TheFile, tmp, '\n');
     Rat1->getTop()->setStreet(tmp);
 
     cout <<"ADDED ADDRESS1: " << Rat1->getTop()->getStreet() << "UID " << Rat1->getTop()->getID() << endl;
    break;
	
    case 7:

     Rat1 = SearchByID(address,tmp);
     getline(TheFile,tmp,'\n');
     Rat1->getTop()->setBirth(tmp);
	
     cout <<"ADDED BIRTH DATE: " << Rat1->getTop()->getBirth() << " UID " << Rat1->getTop()->getID() << endl;
    break;
	  
    case 8:
		 
     Rat1 = SearchByID(address,tmp);
     getline(TheFile,tmp,'\n');
     Rat1->getTop()->setWed(tmp);

     cout <<"ADDED WEDDING DATE: " << Rat1->getTop()->getWed() << " UID " << Rat1->getTop()->getID() << endl;
    break;
	
    case 9:
	
     Rat1 = SearchByID(address,tmp);
     getline(TheFile,tmp,'\n');
     Rat1->getTop()->setDeath(tmp);

     cout <<"ADDED DEATH DATE: " << Rat1->getTop()->getDeath() << " UID " << Rat1->getTop()->getID() << endl;
   break;
	
    case 10:
	
     Rat1=SearchByID(address,tmp);	
     getline(TheFile,tmp,'\n');
     Rat1->getTop()->setCity(tmp);

     cout<<"ADDED CITY: "<< Rat1->getTop()->getCity() << " UID " << Rat1->getTop()->getID() <<endl;
	break;
	
    case 11:
	cout << "add name <name> ==>  Add a new name (First Last) to the Address Book" << endl;
	cout << "add spouse <uid> <name>==> Add spouse of <uid> (First Last) to the Address Book"<< endl;
	cout << "add child  <uid> <name>  ==> Add a child of <uid> (First Last) to the Address Book" << endl;
	cout << "add address1 <uid> <address>  ==> Add/change the address for <uid>" << endl;
	cout << "add city <uid> <city>   ==> Add/change the city for <uid>" << endl;
	cout << "add state <uid> <state>  ==> Add/change the state for <uid>" << endl;
	cout << "add zip <uid> <zipcode>  ==> Add/change the zipcode for <uid>" << endl;
	cout << "add date_birth <uid> <ddmmyyyy>  ==> Add/change the birthday for <uid>" << endl;
	cout << "add date_wedding <uid> <ddmmyyyy>   ==> Add/change the wedding day for <uid>" << endl;
	cout << "add date_death <uid> <ddmmyyyy>   ==> Add/change the date of death for <uid>" << endl;
	cout << "search <name>  ==> searches for name (First Last) and returns the <uid>, if found" << endl;
	cout << "print all ==> Prints a list of ALL of the names in the Address Book with their <uid>" << endl;
	cout << "print <uid>  ==> Prints all of the fields for <uid>" << endl;
	cout << "file <filename> ==> user is prompted for a filename that contains correctly formatted commands" << endl;
	cout << "the file must be in CSV format with one full command per line" << endl;
	cout << "quit" << endl;
	cout << endl;
      break;
	  
   case 12:
     Rat1 = Search(address,tmp);
     if(Rat1 == address.end()){
     cout<<"NOT FOUND: "<< tmp << endl;  
        TheFile.ignore(256,'\n');	 
    break;
     }
     else if(Rat1->getTop()->getName() == tmp){
      cout << "FOUND: " << Rat1->getTop()->getName() << "UID: " << Rat1->getTop()->getID() << endl; 
	  TheFile.ignore(256,'\n');
    break;
     }
	break;
	
   case 13:
      if(tmp == "all"){
         printAll(address);
	     TheFile.ignore(256,'\n');
        }  
      else{
       Rat1 = SearchByID(address,tmp);
       TheFile.ignore(256,'\n');
       printList(Rat1);
       }
       break;
	   
    case 14:
    File(address);
    break;

    case 15:
    break;

  default:
     cout <<" Not a Command!" << endl;
     break;

 } 
  }while(!TheFile.eof());
   TheFile.close(); 
 }
 
int main(){

//bool quit = false;
string choice, tmp;
char data[30];
std::list<myFamily> address;
std::list<myFamily>::iterator Rat1, Rat2;
int swit = 0, num;

myFamily* Fam;

do{
 swit = 0;
 cout<<"cmd> ";
 cin >> choice;
 cin.ignore(1);
 
   if(choice == "add"){
   cin >> choice;
   
if(choice == "name")
    swit = 1;
 else if(choice == "child")
    swit = 2;
 else if(choice == "spouse")
    swit = 3;
 else if(choice == "zip")
    swit = 4;
 else if(choice == "state")
    swit = 5;
 else if(choice == "address1")
    swit = 6;
 else if(choice == "date_birth")
    swit = 7;
 else if(choice == "date_wedding")
    swit = 8;
 else if(choice == "date_death")
    swit = 9;
 else if(choice == "city")
    swit = 10;
     }
 else if(choice == "commands")
    swit = 11;
 else if(choice == "search") 
    swit = 12;
 else if(choice == "print") 
    swit = 13;
 else if(choice == "file") 
    swit = 14;
 else if(choice == "quit") 
    swit = 15;
 else swit = 16;
 

switch(swit){
  
    case 1:
     cin.getline(data,30);
     addList(address, data);
     break;
    
    case 2:
     cin >> tmp;
     Rat1 = SearchByID(address,tmp);
     cin.getline(data,30);
    
     Rat2 = Search(address,data);
     if(Rat2!=address.end())
     Rat1->setChild(Rat2->getTop());
      else
      {
        addList(address,data);
        Rat2 = Search(address,data);
        Rat1->setChild(Rat2->getTop());
      } 
    break;

	case 3:
     cin >> tmp;
     Rat1 = SearchByID(address,tmp);
     cin.getline(data,30);
     Rat2 = Search(address,data);
    
     if(Rat2 != address.end()){
      Rat1->setSpouse(Rat2->getTop());
      Rat2->setSpouse(Rat1->getTop());
      }
      else
      {
      addList(address,data);
      Rat2=Search(address,data);
      Rat1->setSpouse(Rat2->getTop());
      Rat2->setSpouse(Rat1->getTop());
      }
    break;
	  
	case 4:
      cin >> tmp;
      Rat1 = SearchByID(address,tmp);
      cin >> tmp;
     
      Rat1->getTop()->setZip(tmp);
      cout << "ADDED ZIP: " << Rat1->getTop()->getZip() << " UID: " << Rat1->getTop()->getID() << endl;
      break;
	   
    case 5:
      cin >> tmp;
      Rat1 = SearchByID(address,tmp);

      cin >> tmp;
      Rat1->getTop()->setState(tmp);
      cout << "ADDED STATE: " << Rat1->getTop()->getState() << " UID: " << Rat1->getTop()->getID() << endl;
    break;
	  
	case 6:
      cin >> tmp;
      Rat1=SearchByID(address,tmp);
      cin >> tmp;
      Rat1->getTop()->setStreet(tmp);
 
      cout <<"ADDED ADDRESS1: " << Rat1->getTop()->getStreet() << "UID " << Rat1->getTop()->getID() << endl;
    break;
	
    case 7:
      cin >> tmp;
      Rat1 = SearchByID(address,tmp);
      cin >> tmp;
  
      Rat1->getTop()->setBirth(tmp);

      cout <<"ADDED BIRTH DATE: " << Rat1->getTop()->getBirth() << " UID " << Rat1->getTop()->getID() << endl;
    break;
	  	  
	case 8:
      cin >> tmp;
      Rat1 = SearchByID(address,tmp);
      cin >> tmp;
  
      Rat1->getTop()->setWed(tmp);

      cout <<"ADDED WEDDING DATE: " << Rat1->getTop()->getWed() << " UID " << Rat1->getTop()->getID() << endl;
    break;
	
	
    case 9:
      cin >> tmp;
      Rat1 = SearchByID(address,tmp);
      cin >> tmp;
  
      Rat1->getTop()->setDeath(tmp);

      cout <<"ADDED DEATH DATE: " << Rat1->getTop()->getDeath() << " UID " << Rat1->getTop()->getID() << endl;
      break;
  
    case 10:
       cin>>tmp;
       Rat1=SearchByID(address,tmp);	
       cin>>tmp;
       Rat1->getTop()->setCity(tmp);

       cout<<"ADDED CITY: "<< Rat1->getTop()->getCity() << " UID " << Rat1->getTop()->getID() <<endl;
	break;
	
    case 11:
	cout << "add name <name> ==>  Add a new name (First Last) to the Address Book" << endl;
	cout << "add spouse <uid> <name>==> Add spouse of <uid> (First Last) to the Address Book"<< endl;
	cout << "add child  <uid> <name>  ==> Add a child of <uid> (First Last) to the Address Book" << endl;
	cout << "add address1 <uid> <address>  ==> Add/change the address for <uid>" << endl;
	cout << "add city <uid> <city>   ==> Add/change the city for <uid>" << endl;
	cout << "add state <uid> <state>  ==> Add/change the state for <uid>" << endl;
	cout << "add zip <uid> <zipcode>  ==> Add/change the zipcode for <uid>" << endl;
	cout << "add date_birth <uid> <ddmmyyyy>  ==> Add/change the birthday for <uid>" << endl;
	cout << "add date_wedding <uid> <ddmmyyyy>   ==> Add/change the wedding day for <uid>" << endl;
	cout << "add date_death <uid> <ddmmyyyy>   ==> Add/change the date of death for <uid>" << endl;
	cout << "search <name>  ==> searches for name (First Last) and returns the <uid>, if found" << endl;
	cout << "print all ==> Prints a list of ALL of the names in the Address Book with their <uid>" << endl;
	cout << "print <uid>  ==> Prints all of the fields for <uid>" << endl;
	cout << "file <filename> ==> user is prompted for a filename that contains correctly formatted commands" << endl;
	cout << "the file must be in CSV format with one full command per line" << endl;
	cout << "quit" << endl;
	cout << endl;
      break;
	  
    case 12:
     cin.getline(data,30);
     Rat1 = Search(address,data);
     if(Rat1 == address.end()){
     cout<<"NOT FOUND: WAT"<< data << endl;   
     break;
     }

     else if(Rat1->getTop()->getName() == data){
      cout << "FOUND: " << Rat1->getTop()->getName() << "UID: " << Rat1->getTop()->getID() << endl; 
        break;
     }
	 break;
	
    case 13:
       cin >> tmp;
       if(tmp == "all")
	    {
          printAll(address);
        }
       else{
        Rat1 = SearchByID(address,tmp);
 
        printList(Rat1);
       }
       break;
	   
    case 14:
    File(address);
    break;
	
	case 15:
	break;

    default:
     cout <<" Not a Command!" << endl;
     break;
 }
}while(swit != 15);
 return 0;
} 