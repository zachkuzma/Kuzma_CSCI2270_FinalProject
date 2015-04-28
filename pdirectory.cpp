/* Author: Zach Kuzma, Chuan 'Nelson' Khor
 * Final Project
 * Instructor: Hoenigman
 * References:
 * Description: Class File
 */

#include <iostream>
#include <string.h>
#include <vector>
#include "pdirectory.h"

using namespace std;

pdirectory::pdirectory()
{
	
}


pdirectory::~pdirectory()
{
	//destructor
	for(int i = 0; i < hashSize; i++)
	{
		if (hashTable[i] != NULL)
		{
			delete hashTable[i];
		}
	}
}


void pdirectory::insertContact(string name, string num, string email)
{
	//insert contact function
	int index = hashFun(name, hashSize);
	
	//check to see if there is something in the bucket 
	if (hashTable[index] == NULL)
	{
		hashTable[index] = new vector<Contact>;
		hashTable[index]->push_back(Contact(name,num,email));
	}
	//add to an existing bucket with vectors 
	else
	{
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			if ((*hashTable[index])[i].name == name)
			{
				cout << "duplicate" << endl;
				return;
			}
			
			if(name.compare((*hashTable[index])[i].name) < 0)
			{
				(hashTable[index])[i].insert(hashTable[index]->begin() + i, Contact(name,num,email));
			}
		}
		hashTable[index]->push_back(Contact(name,num,email));
	}
	
}


void pdirectory::deleteContact(std::string inName)
{

}

void pdirectory::editContact(std::string inName)
{

}

void pdirectory::findContact(string inName)
{
	int i = hashFun(inName,hashSize);
	bool found = false;

	// If a node exist at this hash location.
	if (hashTable[i] != NULL)
	{
		// Go through every vector index at this hash location.
		for (int j = 0; j < hashTable[i]->size(); j++)
		{
			// If we find the contact in the vector, print it.
			if ((*hashTable[i])[j].name == inName)
			{
                cout << "Name   : "<< (*hashTable[i])[j].name << endl;
                cout << "Phone  : "<< (*hashTable[i])[j].phone << endl;
                cout << "Email  : "<< (*hashTable[i])[j].email << endl;
				found = true;
			}
		}
	}
	if (found == false)
	{
		cout << "Contact could not be found." << endl;
	}
}


void pdirectory::printDirectory()
{
	// Print all the contacts in the directory
    bool empty = true;
    int k = 1;
    for (int i = 0; i < hashSize; i++)
    {
        if (hashTable[i] != NULL)
        {
            for (int j = 0; j < hashTable[i]->size(); j++)
            {
                cout << "(" << k << ")" << endl;
                cout << "Name   : " << (*hashTable[i])[j].name << endl;
                cout << "Phone  : " << (*hashTable[i])[j].phone << endl;
                cout << "Email  : " << (*hashTable[i])[j].email << endl;
                cout << " " << endl;
                empty = false;
                k++;
            }
        }
    }
    if (empty == true)
		cout << "No contact found in the directory." << endl;
}

// Hash Sum function for the contact's name
int pdirectory::hashFun(std::string inName, int hashSize)
{
    int theSum = 0;
    for (int i = 0; i < inName.length(); i++)
    {
        // ASCII value for each of the char in the string
        theSum = theSum + inName[i];
    }
    theSum = theSum % hashSize;
    return theSum;
}

