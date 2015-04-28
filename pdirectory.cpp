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

/*
Function prototype:
void pdirectory::insertContact(string name, string num, string email)

Function description:
This functions adds a node to the hashtable. If there are no contacts in
a certain index of the hashtable, then this function will create a vector
to store the new contact information. However, if there is already information
in the index, then the function will insert the new information alphabetically
into the vector.

Example:
pdirectory *directory;
directory->insertContact("Zach Kuzma", "(123)456-7890", "zach@yahoo.com");

Pre-condition: The inputs include the name, phone number, and email to
find the correct location to store the contact based on the name from 
calculated hash value. The hashtable vector contains NULL locations 
for every index to begin.

Post-condition: The hashtable vector contains the contacts imported
and/or added to the hashtable.
*/
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

/*
Function prototype:
void pdirectory::deleteContact(std::string inName)

Function description:
This functions deletes a contact from the directory. It calculates the 
hash code and finds the desired contact by the name of the contact.
Then, procedes to delete the contact from the list. If the contact is the 
only contact in the index, then there is a condition to reinitialize the
index to NULL.

Example:
pdirectory *directory;
directory->deleteContant("Zach Kuzma");

Pre-condition: The unused locations in the hashtable vector are filled 
with NULL to begin. Contacts are stored by a calculated hash code from
the name of the contact. The only input is a name in order to find the 
desired contact to delete.

Post-condition: Contact deleted from the vector and memory is freed.
*/
void pdirectory::deleteContact(std::string inName)
{
	int index = hashFun(inName,hashSize);
	bool found = false;

	// If a node exist at this hash location.
	if (hashTable[index] != NULL)
	{
		// Go through every vector index at this hash location.
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			// If we find the contact in the vector, delete it.
			if ((*hashTable[index])[i].name == inName)
			{
				hashTable[index]->erase(hashTable[index]->begin() + i);
                found = true;
			}
		}
		// If this was the last element in this chain, delete the vector. 
		if (hashTable[index]->size() == 0)
		{
			delete hashTable[index];
			hashTable[index] = NULL;
		}
	}
	// If the contact could not be found
	if (found == false)
	{
		cout << "Contact could not be found." << endl;
	}
}

void pdirectory::editContact(string name, string num, string email)
{
	deleteContact(name);
	insertContact(name, num, email);
}

void pdirectory::findContact(string inName)
{
	int index = hashFun(inName,hashSize);
	bool found = false;

	// If a node exist at this hash location.
	if (hashTable[index] != NULL)
	{
		// Go through every vector index at this hash location.
		for (int i = 0; i < hashTable[index]->size(); i++)
		{
			// If we find the contact in the vector, print it.
			if ((*hashTable[index])[i].name == inName)
			{
                cout << "Name   : "<< (*hashTable[index])[i].name << endl;
                cout << "Phone  : "<< (*hashTable[index])[i].phone << endl;
                cout << "Email  : "<< (*hashTable[index])[i].email << endl;
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


int pdirectory::hashFun(std::string inName, int hashSize)
{
	// Hash Sum function for the contact's name
    int theSum = 0;
    for (int i = 0; i < inName.length(); i++)
    {
        // ASCII value for each of the char in the string
        theSum = theSum + inName[i];
    }
    theSum = theSum % hashSize;
    return theSum;
}

void pdirectory::exportDirectory()
{
	//function to create a new text file with the updated directory
	//code to be added later
}

