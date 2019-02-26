//
//  G_00_P4_class_header.h
//  homework 4 - csce 2100
//
//  Created by Alexander Ortegren on 01/10/15.
//  Copyright (c) 2015 alex. All rights reserved.
//



#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;


void print_commands();


//
//	Person class
//	Stores information about a person
//	Stores pointers to link to other persons
//


class Person
{
private:
    
    string ID;		//I
    string f_name;		  //N
    string l_name;		    //F
				      //O
    string address1;		        //R
    string City;			   //M
    string State;    		     //A
    string Zip;			       //T
					         //I
    string date_birth;		           //O
    string date_death;			      //N
    string date_wedding;	//About the Person
    
    Person *next;			// Ptr to next Person in list
    Person *spouse;			// Ptr to the Persons spouse (NULL if no spouse)
    vector <Person*> children;		// vector of ptrs to persons that are this persons children
    int child_cnt;			// Counter of how many children this person has
    
public:

	// 	Person Constructor
	// Initialized values when creating a Person object
    
    Person(string id="", Person *ptr=NULL, Person *ptr2=NULL, string f_nm="", string l_nm="", string adrs1="", string city="", string state="", string zip="", string date_b="", string date_d="", string date_w="", int c_cnt=0)
    {ID=id; next=ptr; spouse=ptr2; f_name=f_nm; l_name=l_nm; address1=adrs1; City=city; State=state; Zip=zip; date_birth=date_b; date_death=date_d; date_wedding=date_w; child_cnt=c_cnt; };
    
    
	// Setters and getters

    Person *get_next(){return next;};
    Person *get_spouse(){return spouse;};
    Person *get_child(int i){return children[i];};
    
    string get_ID(){return ID;};
    string get_f_name(){return f_name;};
    string get_l_name(){return l_name;};
    string get_address1(){return address1;};
    string get_City(){return City;};
    string get_State(){return State;};
    
    string get_Zip(){return Zip;};
    string get_date_birth(){return date_birth;};
    string get_date_death(){return date_death;};
    string get_date_wedding(){return date_wedding;};
    int get_child_cnt(){return child_cnt;};

    
    void set_next(Person *ptr){next = ptr;};
    void set_spouse(Person *ptr){spouse = ptr;};
    void set_child(Person *ptr){children.push_back(ptr); child_cnt++;};
    
    void set_ID(string id){ID = id;};
    void set_f_name(string f_nm){f_name = f_nm;};
    void set_l_name(string l_nm){l_name = l_nm;};
    void set_address1(string adrs1){address1 = adrs1;};
    void set_City(string city){City = city;};
    void set_State(string state){State = state;};
    
    void set_Zip(string zip){Zip = zip;};
    void set_date_birth(string date_b){date_birth = date_b;};
    void set_date_death(string date_d){date_death = date_d;};
    void set_date_wedding(string date_w){date_wedding = date_w;};
    //void set_child_cnt(int c_cnt){child_cnt = c_cnt;};
    
};


//
// 	Collection class of Persons called People
// 
// 	Collects all Person objects and facilitates searching/sorting/linking
//



class People
{
private:
    int p_cnt;			// counter of the people in the list
    int ID;			// ID starting at 1 and incremented when adding
    Person *top;		// Ptr to first person in the list
    Person *bottom;		// Ptr to last  - || -
public:

	// People constructor

    People()
    {
        p_cnt = 0;
        ID = 1;
        top = bottom = NULL;
    }

	// People destructor

    ~People()
    {
        Person *now = top;
        while (now != NULL)
        {
            Person *next = now->get_next();
            delete now;
            now = next;
        }
    }

	// Class functions

    void add_person(string f_name, string l_name);
    //void del_person(string name);			// Not needed for this program
    Person* search(string f_name, string l_name);
    Person* search_id(string ID);
    void print_people();
    void print_id(string ID);
    void print_tree(string ID);
    void add_spouse(Person *ptr1, Person *ptr2);

};

