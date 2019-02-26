//
//  G_00_P4_functions.cpp
//  homework 4  - csce 2100
//
//  Created by Alexander Ortegren on 10/10/15.
//  Copyright (c) 2015 alex. All rights reserved.
//

#include "G_00_P4_class_header.h"


//
//	Prints the available commands
//

void print_commands()
{
    cout << "AVAILABLE COMMANDS:" << endl << endl;
    cout << "add name <name> ==> Add a new name (First Last) to the Address Book" << endl;
    cout << "add spouse <uid> <name> ==> Add spouse of <uid< (First Last) to the Address Book" << endl;
    cout << "add child <uid> <name> ==> Add a child of <uid> (First Last) to the Address Book" << endl;
    cout << "add address1 <uid> <address> ==> Add/change the adrress for <uid>" << endl;
    cout << "add city <uid> <city> ==> Add/change the city for <uid>" << endl;
    cout << "add state <uid> <state> ==> Add/change the state for <uid>" << endl;
    cout << "add zip <uid> <zipcode> ==> Add/change the zipcode for <uid>" << endl;
    cout << "add date_birth <uid> <ddmmyyyy> ==> Add/change the birthday for <uid>" << endl;
    cout << "add date_wedding <uid> <ddmmyyyy> ==> Add/change the wedding day for <uid>" << endl;
    cout << "add date_death <uid> <ddmmyyyy> =>> Add/change the date of death for <uid>" << endl;
    cout << "search <name> ==> searcher for name (First Last) and returns <uid>, if found" << endl;
    cout << "print all ==> prints a list of ALL of the names in the Address Book with their <uid>" << endl;
    cout << "print <uid> ==> Prints all of the fields for <uid>" << endl;
    cout << "ftree <uid> ==> Prints a Family Tree starting with the <uid> record" << endl;
    cout << "file ==> user is prompted for a filename that contains correctly formatted commands --- the file must be in CSV format with one full command per line" << endl;
    cout << "quit ==> processing complete" << endl;
}


//
//	Search for a Person in the list using names
//	Takes first and last names and returns a ptr to the person
//	If no match - returns NULL
//

Person* People :: search(string f_name, string l_name)
{
    if(p_cnt == 0)		// check if there are persons in the list
        return NULL;
    
    Person *now = top;		// iterator ptr
    
    string now_f_temp;		// temp strings to convert to lower case
    string now_l_temp;
    
    string new_f_temp=f_name;	// set temps to first and last names
    string new_l_temp=l_name;
    

	// convert first/last names to lower case
	// 
	// 	(Had problems with my first solution)
	//	(Creating my own seemed like a waste of time)
	//	http://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
	//
    
    transform(new_f_temp.begin(),new_f_temp.end(),new_f_temp.begin(), ::tolower);
    transform(new_l_temp.begin(),new_l_temp.end(),new_l_temp.begin(), ::tolower);

    
    while(now != NULL)
    {     
        
        now_f_temp=now->get_f_name();	// set temps to current iteration ptr's name
        now_l_temp=now->get_l_name();

		// lower temps
        
        transform(now_f_temp.begin(),now_f_temp.end(),now_f_temp.begin(), ::tolower);
        transform(now_l_temp.begin(),now_l_temp.end(),now_l_temp.begin(), ::tolower);

        
		// compare lower first/last names
		// If both match - return the ptr

        if((now_f_temp == new_f_temp) && (now_l_temp == new_l_temp))
            return now;
        else
            now = now->get_next();
    }
    return NULL;
}


//
//	Search for a person using ID
//	Takes an ID string and returns a pointer to the Person it matches
//	If no match - returns NULL
//


Person* People :: search_id(string id)
{
    if(p_cnt == 0)
        return NULL;
    
    Person *now = top;
    
    while(now != NULL)
    {
        if(now->get_ID() == id)		// compare given ID string to iteration's ID string
            return now;
        else
            now = now->get_next();
    }
    return NULL;
}


//
//	Prints all persons in the list
//


void People :: print_people()
{
    if(p_cnt == 0)
    {
        cout << "NO NAMES IN LIST" << endl;
        return;
    }
    
    Person *now = top;
    
    while(now != NULL)
    {
        cout << now->get_f_name() << " " << now->get_l_name() << " " << now->get_ID() << endl;
        
        now = now->get_next();
    }
}


//
//	Given a Person ID - prints that persons information
//
//


void People :: print_id(string id)
{
    Person *ptr;	// ptr to person with ID - if found
    
	// search for person by ID and set it to the ptr

    ptr = search_id(id);
    
    if(ptr == NULL)
    {
        cout << "ID not found" << endl;
        return;
    }
    else
    {
        cout << "         UID: " << ptr->get_ID() << endl;
        cout << "        NAME: " << ptr->get_f_name() << " " << ptr->get_l_name() << endl;
        cout << "    ADDRESS1: " << ptr->get_address1() << endl;
        cout << "        CITY: " << ptr->get_City() << endl;
        cout << "       STATE: " << ptr->get_State() << endl;
        cout << "  DATE_BIRTH: " << ptr->get_date_birth() << endl;
        cout << "  DATE_DEATH: " << ptr->get_date_death() << endl;
        cout << "DATE_WEDDING: " << ptr->get_date_wedding() << endl;

		// Checks if person has a spouse
		// If not - print blank next to spouse

        if(ptr->get_spouse() == NULL)
        {
            cout << "      SPOUSE: " << endl;
        }
        else
        {
            cout << "      SPOUSE: " << ptr->get_spouse()->get_f_name() << " " << ptr->get_spouse()->get_l_name() << endl;
        }

		// Prints all children of the person
		// Iterates through the children

        for(int i=0; i<ptr->get_child_cnt(); i++)
        {
            cout << "      CHILD" << i+1 << ": " << ptr->get_child(i)->get_f_name() << " " << ptr->get_child(i)->get_l_name() << endl;
        }
        cout << endl;
    }
}

//
//	Prints out the family tree
//	given a valid uid
//

void People :: print_tree(string id)
{

    Person *ptr;
    
    ptr = search_id(id);
    
    if(ptr == NULL)
    {
        cout << "ID not found" << endl;
        return;
    }
    else
    {
        string a[]={"","",""}, aa[]={"","",""}, ab[]={"","",""}, ac[]={"","",""};		// children / grandchildren
	string a_w[]={"","",""}, aa_w[]={"","",""}, ab_w[]={"","",""}, ac_w[]={"","",""};	//wives of children/grand children
        
        if(ptr->get_child_cnt() < 4)
        {
            for(int i=0;i<ptr->get_child_cnt();i++)
            {
	         if(ptr->get_child(i)->get_spouse() == NULL)
		  {
                    a[i] = ptr->get_child(i)->get_f_name() + " " + ptr->get_child(i)->get_l_name();
		  }
		  else
		  {
                    a[i] = ptr->get_child(i)->get_f_name() + " " + ptr->get_child(i)->get_l_name();
		    a_w[i] = ptr->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(i)->get_spouse()->get_l_name();
		  }
            }
	  
            if(ptr->get_child_cnt() == 3)
            {
                for(int i=0;i<ptr->get_child(0)->get_child_cnt();i++)
                {
		      if(ptr->get_child(0)->get_child(i)->get_spouse() == NULL)
		      {
		          aa[i] = ptr->get_child(0)->get_child(i)->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_l_name();
		      }
		      else
		      {
		          aa[i] = ptr->get_child(0)->get_child(i)->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_l_name();
			  aa_w[i] = ptr->get_child(0)->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_spouse()->get_l_name();
		      }
                }
                for(int i=0;i<ptr->get_child(1)->get_child_cnt();i++)
                {
		      if(ptr->get_child(1)->get_child(i)->get_spouse() == NULL)
		      {
		          ab[i] = ptr->get_child(1)->get_child(i)->get_f_name() + " " + ptr->get_child(1)->get_child(i)->get_l_name();
		      }
		      else
		      {
		          ab[i] = ptr->get_child(1)->get_child(i)->get_f_name() + " " + ptr->get_child(1)->get_child(i)->get_l_name();
			  ab_w[i] = ptr->get_child(1)->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(1)->get_child(i)->get_spouse()->get_l_name();
		      }

                }
                for(int i=0;i<ptr->get_child(2)->get_child_cnt();i++)
                {
		      if(ptr->get_child(2)->get_child(i)->get_spouse() == NULL)
		      {
		          ac[i] = ptr->get_child(2)->get_child(i)->get_f_name() + " " + ptr->get_child(2)->get_child(i)->get_l_name();
		      }
		      else
		      {
		          ac[i] = ptr->get_child(2)->get_child(i)->get_f_name() + " " + ptr->get_child(2)->get_child(i)->get_l_name();
			  ac_w[i] = ptr->get_child(2)->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(2)->get_child(i)->get_spouse()->get_l_name();
		      }
                }
               
            }
            if(ptr->get_child_cnt() == 2)
            {
                for(int i=0;i<ptr->get_child(0)->get_child_cnt();i++)
                {
		      if(ptr->get_child(0)->get_child(i)->get_spouse() == NULL)
		      {
		          aa[i] = ptr->get_child(0)->get_child(i)->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_l_name();
		      }
		      else
		      {
		          aa[i] = ptr->get_child(0)->get_child(i)->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_l_name();
			  aa_w[i] = ptr->get_child(0)->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_spouse()->get_l_name();
		      }
                }
                for(int i=0;i<ptr->get_child(1)->get_child_cnt();i++)
                {
		      if(ptr->get_child(1)->get_child(i)->get_spouse() == NULL)
		      {
		          ab[i] = ptr->get_child(1)->get_child(i)->get_f_name() + " " + ptr->get_child(1)->get_child(i)->get_l_name();
		      }
		      else
		      {
		          ab[i] = ptr->get_child(1)->get_child(i)->get_f_name() + " " + ptr->get_child(1)->get_child(i)->get_l_name();
			  ab_w[i] = ptr->get_child(1)->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(1)->get_child(i)->get_spouse()->get_l_name();
		      }
                }             
            }
            if(ptr->get_child_cnt() == 1)
            {
                for(int i=0;i<ptr->get_child(0)->get_child_cnt();i++)
                {
		      if(ptr->get_child(0)->get_child(i)->get_spouse() == NULL)
		      {
		          aa[i] = ptr->get_child(0)->get_child(i)->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_l_name();
		      }
		      else
		      {
		          aa[i] = ptr->get_child(0)->get_child(i)->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_l_name();
			  aa_w[i] = ptr->get_child(0)->get_child(i)->get_spouse()->get_f_name() + " " + ptr->get_child(0)->get_child(i)->get_spouse()->get_l_name();
		      }
                }
            }


	    cout << endl << setw(70) << setfill(' ') << "Family Tree for <uid>: " << ptr->get_ID() << endl << endl;

	    cout << " " << setw(124) << setfill('_') << "_" << endl ;

	    if(ptr->get_spouse() == NULL)
	    {
		  cout << "|" << setw(21) << setfill(' ') << ptr->get_f_name() << " " << ptr->get_l_name() << setw(58) << setfill(' ') << "|" << endl;
	    }
   	    else
	    {
            	  cout << "|" << setw(61) << setfill(' ') << ptr->get_f_name() << " " << ptr->get_l_name() << setw(58) << setfill(' ') << "|" << endl;
		  cout << "|" << setw(62) << setfill(' ') << "/" << setw(63) << setfill(' ') << "|" << endl;
		  cout << "|" << setw(61) << setfill(' ') << ptr->get_spouse()->get_f_name() << " " << ptr->get_spouse()->get_l_name() << setw(58) << setfill(' ') << "|" << endl;
	    }


	    cout << "|" << setw(62) << setfill(' ') << "|" << setw(63) << setfill(' ') << "|" << endl;
	    cout << "|" << setw(21) << setfill(' ') << "|" << setw(41) << setfill('-') << "|" << setw(41) << setfill('-') << "|" << setw(22) << setfill(' ') << "|" << endl;

	    cout << "|" << setw(26) << setfill(' ') << a[0] << setw(41) << setfill(' ') << a[1] << setw(41) << setfill(' ') << a[2] << setw(17) << setfill(' ') << "|" << endl;
	    cout << "|" << setw(21) << setfill(' ') << "/" << setw(41) << setfill(' ') << "/" << setw(41) << setfill(' ') << "/" << setw(22) << setfill(' ') << "|" << endl;
	    cout << "|" << setw(26) << setfill(' ') << a_w[0] << setw(41) << setfill(' ') << a_w[1] << setw(41) << setfill(' ') << a_w[2] << setw(17) << setfill(' ') << "|" << endl;

	    cout << "|" << setw(21) << setfill(' ') << "|" << setw(41) << setfill(' ') << "|" << setw(41) << setfill(' ') << "|" << setw(22) << setfill(' ') << "|" << endl;
	    cout << "|" << setw(7) << setfill(' ') << "-" << setw(28) << setfill('-') << "-";
	    cout << " " << setw(12) << setfill(' ') << "-" << setw(28) << setfill('-') << "-";
	    cout << " " << setw(12) << setfill(' ') << "-" << setw(28) << setfill('-') << "-" << setw(8) << setfill(' ') << "|" << endl;
            
	    cout << "|" << setw(7) << setfill(' ') << "|" << "  " << setw(12) << setfill(' ') << "|" << "  " << setw(12) << setfill(' ') << "|";
	    cout << " " << setw(12) << setfill(' ') << "|" << "  " << setw(12) << setfill(' ') << "|" << "  " << setw(12) << setfill(' ') << "|";
	    cout << " " << setw(12) << setfill(' ') << "|" << "  " << setw(12) << setfill(' ') << "|" << "  " << setw(12) << setfill(' ') << "|" << setw(8) << setfill(' ') << "|" << endl;

	    cout << "|" << setw(12) << setfill(' ') << aa[0] << "  " << setw(12) << setfill(' ') << aa[1] << "  " << setw(12) << setfill(' ') << aa[2];
	    cout << " " << setw(12) << setfill(' ') << ab[0] << "  " << setw(12) << setfill(' ') << ab[1] << "  " << setw(12) << setfill(' ') << ab[2];
	    cout << " " << setw(12) << setfill(' ') << ac[0] << "  " << setw(12) << setfill(' ') << ac[1] << "  " << setw(12) << setfill(' ') << ac[2] << setw(3) << setfill(' ') << "|" << endl;

	    cout << "|" << setw(7) << setfill(' ') << "/" << "  " << setw(12) << setfill(' ') << "/" << "  " << setw(12) << setfill(' ') << "/";
	    cout << " " << setw(12) << setfill(' ') << "/" << "  " << setw(12) << setfill(' ') << "/" << "  " << setw(12) << setfill(' ') << "/";
	    cout << " " << setw(12) << setfill(' ') << "/" << "  " << setw(12) << setfill(' ') << "/" << "  " << setw(12) << setfill(' ') << "/" << setw(8) << setfill(' ') << "|" << endl;

	    cout << "|" << setw(12) << setfill(' ') << aa_w[0] << "  " << setw(12) << setfill(' ') << aa_w[1] << "  " << setw(12) << setfill(' ') << aa_w[2];
	    cout << " " << setw(12) << setfill(' ') << ab_w[0] << "  " << setw(12) << setfill(' ') << ab_w[1] << "  " << setw(12) << setfill(' ') << ab_w[2];
	    cout << " " << setw(12) << setfill(' ') << ac_w[0] << "  " << setw(12) << setfill(' ') << ac_w[1] << "  " << setw(12) << setfill(' ') << ac_w[2] << setw(3) << setfill(' ') << "|" << endl;

	    cout << "|" << setw(125) << setfill(' ') << "|" << endl;
	    cout << "|" << setw(125) << setfill('_') << "|" << endl << endl ;

        }
        else
            cout << "more than 4 children" << endl;
    }
}



//
//	Adds a Person to the list
//	Takes parameters first and last name
//


void People :: add_person(string f_name, string l_name)
{
    stringstream ss;
    

	// Find person and get ptr to it

    Person *ptr;
    ptr = search(f_name, l_name);
    
    if(ptr != NULL)
    {
        cout << "DUPLICATE: " << f_name << " " << l_name << " UID: " << ptr->get_ID() << endl;
        return;
    }
    
    Person *temp_1;
    

	//	Merges int ID and string "ID" to form string: "IDxxx"
	//	where "xxx" is the incremented integer ID #
	//	Also fills the unused # with 0's
	//
	//	http://www.cplusplus.com/forum/beginner/8043/

    ss << "ID" << setfill('0') << setw(3) << ID;
    
	// creates a person and sets it to temp_1 with:
	// ID: SS
	// *next: NULL
	// *Spouse: NULL
	// f_name: given f_name
	// l_name: given l_name 

    temp_1 = new Person(ss.str(), NULL, NULL, f_name, l_name);
    
	// if list is empty

    if(p_cnt == 0)
    {
        top = bottom = temp_1;
        temp_1->set_next(NULL);
        p_cnt++;
        ID++;
        
        cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
        
    }
    else
    {

		// Same as function Search

        Person *now = top;
        
        string now_f_temp;
        string now_l_temp;
        
        string new_f_temp=f_name;
        string new_l_temp=l_name;
        
        string next_f_temp;
        string next_l_temp;
        
        
        transform(new_f_temp.begin(), new_f_temp.end(), new_f_temp.begin(), ::tolower);
        transform(new_l_temp.begin(), new_l_temp.end(), new_l_temp.begin(), ::tolower);
        

		// Checks where to add the new person in the list

        while(now != NULL)
        {
            
            now_l_temp = now->get_l_name();
            transform(now_l_temp.begin(), now_l_temp.end(), now_l_temp.begin(), ::tolower);
            
            if(now->get_next() != NULL)
            {
                
                next_l_temp = now->get_next()->get_l_name();
                transform(next_l_temp.begin(), next_l_temp.end(), next_l_temp.begin(), ::tolower);
            }
            

		// If last names are the same
		// Compare first names and place in list
            
            if(now_l_temp == new_l_temp)
            {
                while((now_l_temp == new_l_temp) && (now != NULL))
                {
                    
                    now_f_temp = now->get_f_name();
                    transform(now_f_temp.begin(), now_f_temp.end(), now_f_temp.begin(), ::tolower);
                    
                    if(now->get_next() != NULL)
                    {
                        
                        next_f_temp = now->get_next()->get_f_name();
                        transform(next_f_temp.begin(), next_f_temp.end(), next_f_temp.begin(), ::tolower);

                    }
                    
                    if(now == top)
                    {
				// Check to see if new f_name is first in list

                        if(now_f_temp > new_f_temp)
                        {
                            temp_1->set_next(now);
                            top = temp_1;
                            p_cnt++;
                            ID++;
                            
                            cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
                            return;
                        }
                    }
                    
                    if(now == bottom)
                    {

				// Check to see if new f_name is last in list

                        if(now_f_temp < new_f_temp)
                        {
                            now->set_next(temp_1);
                            temp_1->set_next(NULL);
                            bottom = temp_1;
                            p_cnt++;
                            ID++;
                            
                            cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
                            return;
                        }
                    }

			// Check to see if new f_name is before the next element in the list
                    
                    if(next_f_temp > new_f_temp)
                    {
                        temp_1->set_next(now->get_next());
                        now->set_next(temp_1);
                        p_cnt++;
                        ID++;
                        
                        cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
                        return;
                    }
                    now = now->get_next();
                }
            }
            
		// Same for last names as for first names

            if(now == top)
            {
                if(now_l_temp > new_l_temp)
                {
                    temp_1->set_next(now);
                    top = temp_1;
                    p_cnt++;
                    ID++;
                    
                    cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
                    return;
                }
            }
            
            if(now == bottom)
            {
                if(now_l_temp < new_l_temp)
                {
                    now->set_next(temp_1);
                    temp_1->set_next(NULL);
                    bottom = temp_1;
                    p_cnt++;
                    ID++;
                    
                    cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
                    return;
                }
            }
            
            if(next_l_temp > new_l_temp)
            {
                temp_1->set_next(now->get_next());
                now->set_next(temp_1);
                p_cnt++;
                ID++;
                
                cout << "ADDED: " << temp_1->get_f_name() << " " << temp_1->get_l_name() << " UID: " << temp_1->get_ID() << endl;
                return;
            }
            
            now = now->get_next();
            
        }
    }
}
