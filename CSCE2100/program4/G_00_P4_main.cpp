//
//  G_00_P4_main.cpp
//  homework 4 - csce 2100
//
//  Created by Alexander Ortegren on 01/10/15.
//  Copyright (c) 2015 alex. All rights reserved.
//

#include "G_00_P4_class_header.h"

int main(int argc, const char * argv[]) {
    
    People mypeople;			// initiate object of People
    
    string commands, temp_line;
    stringstream ss;
    
    vector<string> line;
    
    
    print_commands();
    
    
    cout << "cmd> ";

    
    // To store input in vector and separte them with delimiters
    // getline reference:
    // https://www.daniweb.com/programming/software-development/threads/53349/getline-with-multiple-delimiters
    
    while(getline(cin, commands))
    {

        ss << commands;
        
        while(getline(ss, temp_line, ' '))
        {
            line.push_back(temp_line);
        }
        
        if(line[0] == "commands")
        {
            system("clear");              //clear screen
            //cout << "\033[2J\033[1;1H";   //clear screen  http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
            
            
            print_commands();
	    cout << endl;
        }
        else if((line[0] == "add" ) || (line[0] == "ADD"))
        {
            /*if(line.size() > 2)
            {
                cout << "too many arguments for add command" << endl;

            }
            else*/
            if((line[1] == "name") || (line[1] == "NAME"))
            {
                mypeople.add_person(line[2], line[3]);
            }

			// Adds a spouse to a person

            else if((line[1] == "spouse") || (line[1] == "SPOUSE"))
            {
                Person *ptr1, *ptr2;			    // ptr2 = spouse
                ptr1 = mypeople.search_id(line[2]);         // ptr1 = Person to add a spouse to
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else if(ptr1->get_spouse() != NULL)
                {
                    cout << "Hey! " << ptr1->get_f_name() << " " << ptr1->get_l_name() << " is already married to " << ptr1->get_spouse()->get_f_name() << " " << ptr1->get_spouse()->get_l_name() << "..." << endl;
                }
                else
                {
			// check if person exists in list
			//
			// If no - add person first then link the spouses together
			// by pointing the spouse ptrs to each other
			//
			// If yes - just link the spouse ptrs
			//

                    ptr2 = mypeople.search(line[3], line[4]);
                    if(ptr2 == NULL)
                    {
                        mypeople.add_person(line[3], line[4]);
                        ptr2 = mypeople.search(line[3], line[4]);
                        ptr1->set_spouse(ptr2);
                        ptr2->set_spouse(ptr1);
                    }
                    else
                    {
                        ptr1->set_spouse(ptr2);
                        ptr2->set_spouse(ptr1);
                        
                        cout << "ALREADY IN LIST: " << line[3] << " " << line[4] << " UID: " << ptr2->get_ID() << endl;
                    }
                }
            }

			// Adds a child to person or person + spouse

            else if(line[1] == "child")
            {
                Person *ptr1, *ptr2;                //ptr1 = parent; ptr2 = child
                ptr1 = mypeople.search_id(line[2]);
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr2 = mypeople.search(line[3], line[4]);
                    if(ptr2 == NULL)
                    {
                        mypeople.add_person(line[3], line[4]);
                        
                        ptr2 = mypeople.search(line[3], line[4]);
                        
                        ptr1->set_child(ptr2);
                        if(ptr1->get_spouse() != NULL)
                        {
                            ptr1->get_spouse()->set_child(ptr2);
                        }
                    }
                    else
                    {
                        ptr1->set_child(ptr2);
                        if(ptr1->get_spouse() != NULL)
                        {
                            ptr1->get_spouse()->set_child(ptr2);
                        }
                        cout << "ALREADY IN LIST: " << line[3] << " " << line[4] << " UID: " << ptr2->get_ID() << endl;
                    }
                }

                
            }

			// Adds adress to a person

            else if(line[1] == "address1")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                
                string address1;
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {

			// stores all commands after the ID into 1 string

                    for(int i=3;i<line.size();i++)
                    {
                        address1 += line[i];
                        address1 += " ";
                    }

			// removes the \r for mac

                    //address1.erase(address1.size()-1);
                    
                    ptr1->set_address1(address1);
                    
                    cout << "ADDED ADDRESS1: " << ptr1->get_address1() << " " << ptr1->get_ID() << endl;
                }

                
            }
            else if(line[1] == "city")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr1->set_City(line[3]);
                    
                    cout << "ADDED CITY: " << ptr1->get_City() << " " << ptr1->get_ID() << endl;
                }

            }
            else if(line[1] == "state")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr1->set_State(line[3]);
                    
                    cout << "ADDED STATE: " << ptr1->get_State() << " " << ptr1->get_ID() << endl;
                }
                
            }
            else if(line[1] == "zip")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr1->set_Zip(line[3]);
                    
                    cout << "ADDED ZIP: " << ptr1->get_Zip() << " " << ptr1->get_ID() << endl;
                }
                
            }
            else if(line[1] == "date_birth")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr1->set_date_birth(line[3]);
                    
                    cout << "ADDED BIRTHDAY: " << ptr1->get_date_birth() << " " << ptr1->get_ID() << endl;
                }
            }
            else if(line[1] == "date_wedding")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr1->set_date_wedding(line[3]);
                    
                    cout << "ADDED WEDDING-DAY: " << ptr1->get_date_wedding() << " " << ptr1->get_ID() << endl;
                }
            }
            else if(line[1] == "date_death")
            {
                Person *ptr1;
                ptr1 = mypeople.search_id(line[2]);
                
                if(ptr1 == NULL)
                {
                    cout << "Home_uid does not exist" << endl;
                }
                else
                {
                    ptr1->set_date_death(line[3]);
                    
                    cout << "ADDED DATE of DEATH: " << ptr1->get_date_death() << " " << ptr1->get_ID() << endl;
                }
            }
	     else
                cout << "INVALID COMMAND" << endl;
            
        }
        /*else if((line[0] == "remove" ) || (line[0] == "REMOVE"))
        {
            //mypeople.del_person(line[1]);
        }*/
        else if((line[0] == "print" ) || (line[0] == "PRINT"))
        {
            if(line[1] == "all")
            {
                mypeople.print_people();
            }
            else if(line.size() > 1)
            {
                mypeople.print_id(line[1]);
            }
            else
                cout << "INVALID COMMAND" << endl;
        }
	 else if((line[0] == "ftree" ) || (line[0] == "FTREE"))
	 {
	     mypeople.print_tree(line[1]);
	 }
        else if((line[0] == "search" ) || (line[0] == "SEARCH"))
        {
            Person *ptr;
            
            ptr = mypeople.search(line[1], line[2]);
            
            if(ptr == NULL)
                cout << "NOT FOUND: " << line[1] << " " << line[2] << endl;
            else
                cout << "FOUND: " << ptr->get_f_name() << " " << ptr->get_l_name() << " " << ptr->get_ID() << endl;
        }
        else if(line[0] == "file")
        {
       
            
            ifstream file (line[1].c_str());
                        
            if(!file)
            {
                cout << "ERROR: CANNOT OPEN INPUT FILE" << endl;
            }

            else
            {
                string commands, temp_line, temp_line2;
                
                while(getline(file, commands))
                {
                    stringstream ss, ss2;
                    vector<string> line,line2;
                    
                    ss << commands;

                    while(getline(ss, temp_line, ','))
                    {
                        line.push_back(temp_line);
                    }
                    
                    
                    if((line[0] == "add" ) || (line[0] == "ADD"))
                    {
                        if(line[1] == "name")
                        {
                            ss2 << line[2];
                                                        
                            while(getline(ss2,temp_line2, ' '))
                            {
                                line2.push_back(temp_line2);
                            }
                            mypeople.add_person(line2[0], line2[1]);
                        }
                        if(line[1] == "spouse")
                        {
                            Person *ptr1, *ptr2;
                            ptr1 = mypeople.search_id(line[2]);         // ptr1 = Person to add a spouse to
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else if(ptr1->get_spouse() != NULL)
                            {
                                cout << "Hey! " << ptr1->get_f_name() << " " << ptr1->get_l_name() << " is already married to " << ptr1->get_spouse()->get_f_name() << " " << ptr1->get_spouse()->get_l_name() << "..." << endl;
                            }
                            else
                            {
                                ss2 << line[3];
                                
                                
                                
                                while(getline(ss2,temp_line2, ' '))
                                {
                                    line2.push_back(temp_line2);
                                }
                                
                                if(line2[1][line2[1].size()-1] == '\r')
                                {
                                    line2[1] = line2[1].erase(line2[1].size()-1);
                                }
                                //removing \r stuck from windows csv file..
                                
                                ptr2 = mypeople.search(line2[0], line2[1]);
                                if(ptr2 == NULL)
                                {
                                    mypeople.add_person(line2[0], line2[1]);
                                    ptr2 = mypeople.search(line2[0], line2[1]);
                                    ptr1->set_spouse(ptr2);
                                    ptr2->set_spouse(ptr1);
                                }
                                else
                                {
                                    ptr1->set_spouse(ptr2);
                                    ptr2->set_spouse(ptr1);
                                    
                                    cout << "ALREADY IN LIST: " << line[3] << " " << line[4] << " UID: " << ptr2->get_ID() << endl;
                                }
                            }
                        }
                        if(line[1] == "child")
                        {
                            Person *ptr1, *ptr2;                //ptr1 = parent; ptr2 = child
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
                                ss2 << line[3];
                                while(getline(ss2,temp_line, ' '))
                                {
                                    line2.push_back(temp_line);
                                }
                                
                                if(line2[1][line2[1].size()-1] == '\r')
                                {
                                    line2[1] = line2[1].erase(line2[1].size()-1);
                                }
                                
                                ptr2 = mypeople.search(line2[0], line2[1]);
                                
                                if(ptr2 == NULL)
                                {
                                    mypeople.add_person(line2[0], line2[1]);
                                    
                                    ptr2 = mypeople.search(line2[0], line2[1]);
                                    
                                    ptr1->set_child(ptr2);
                                    if(ptr1->get_spouse() != NULL)
                                    {
                                        ptr1->get_spouse()->set_child(ptr2);
                                    }
                                }
                                else
                                {
                                    ptr1->set_child(ptr2);
                                    if(ptr1->get_spouse() != NULL)
                                    {
                                        ptr1->get_spouse()->set_child(ptr2);
                                    }
                                    cout << "ALREADY IN LIST: " << line2[0] << " " << line2[1] << " UID: " << ptr2->get_ID() << endl;
                                }
                            }
                            
                            
                        }
                        if(line[1] == "address1")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_address1(line[3]);
                                
                                cout << "ADDED ADDRESS1: " << ptr1->get_address1() << " " << ptr1->get_ID() << endl;
                            }
                        }
                        if(line[1] == "city")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_City(line[3]);
                                
                                cout << "ADDED CITY: " << ptr1->get_City() << " " << ptr1->get_ID() << endl;
                            }

                        }
                        if(line[1] == "state")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_State(line[3]);
                                
                                cout << "ADDED STATE: " << ptr1->get_State() << " " << ptr1->get_ID() << endl;
                            }

                        }
                        if(line[1] == "zip")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_Zip(line[3]);
                                
                                cout << "ADDED ZIP: " << ptr1->get_Zip() << " " << ptr1->get_ID() << endl;
                            }

                        }
                        if(line[1] == "date_birth")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_date_birth(line[3]);
                                
                                cout << "ADDED BIRTHDAY: " << ptr1->get_date_birth() << " " << ptr1->get_ID() << endl;
                            }

                        }
                        if(line[1] == "date_wedding")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_date_wedding(line[3]);
                                
                                cout << "ADDED WEDDING-DAY: " << ptr1->get_date_wedding() << " " << ptr1->get_ID() << endl;
                            }

                        }
                        if(line[1] == "date_death")
                        {
                            Person *ptr1;
                            ptr1 = mypeople.search_id(line[2]);
                            
                            if(ptr1 == NULL)
                            {
                                cout << "Home_uid does not exist" << endl;
                            }
                            else
                            {
				if(line[3][line[3].size()-1] == '\r')
                                {
                                	line[3] = line[3].erase(line[3].size()-1);
                                }
                                
                                ptr1->set_date_death(line[3]);
                                
                                cout << "ADDED DATE of DEATH: " << ptr1->get_date_death() << " " << ptr1->get_ID() << endl;
                            }

                        }
                        
                    }
                    /*else if((line[0] == "remove" ) || (line[0] == "REMOVE"))
                    {
                       // mypeople.del_person(line[1]);
                    }*/
                    else if((line[0] == "print" ) || (line[0] == "PRINT"))
                    {
                        if(line[1] == "all")
                        {
                            mypeople.print_people();
                        }
                        else if(line.size() > 1)
                        {
                            mypeople.print_id(line[1]);
                        }
                        else
                            cout << "INVALID COMMAND" << endl;
                    }
		      else if((line[0] == "ftree" ) || (line[0] == "FTREE"))
		      {
			   mypeople.print_tree(line[1]);
		      }
                    else if((line[0] == "search" ) || (line[0] == "SEARCH"))
                    {
                        Person *ptr;
                        
                        ss2 << line[1];
                        while(getline(ss2,temp_line, ' '))
                        {
                            line2.push_back(temp_line);
                        }
                        
                        ptr = mypeople.search(line2[0], line2[1]);
                        
                        if(ptr == NULL)
                            cout << "NOT FOUND: " << line2[0] << " " << line2[1] << endl;
                        else
                            cout << "FOUND: " << ptr->get_f_name() << " " << ptr->get_l_name() << " " << ptr->get_ID() << endl;
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                    }
                    
                    
                    line.clear();
                    line2.clear();
                    
                    ss.clear();
                    ss2.clear();
                    
                }
                file.close();
            }
        }
        else if((line[0] == "quit" ) || (line[0] == "QUIT"))
        {
            cout << "Have a good day and a pleasant tomorrow! Good-bye." << endl;
            return 0;
        }
        else
        {
            cout << "invalid input" << endl;
        }
        
        line.clear();
        
        ss.clear();
        
        cout << endl;
        
        cout << "cmd> ";

    }

    
    
    return 0;
}