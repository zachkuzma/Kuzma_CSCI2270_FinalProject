/* Author: Zach Kuzma, Chuan 'Nelson' Khor
    Final Project
 * Instructor: Hoenigman
 * References: TA and LAs
 * Description: Class File
 */

#include <iostream>
#include <string.h>
#include <vector>
#include "pdirectory.h"

using namespace std;

pdirectory::pdirectory(int)
{
	//initialization of the hash table as an array with vector buckets
	vector<Movie> *hashTable[10];
	for(int i = 0; i < 10; i++)
	{
		hashTable[i] = NULL;
	}
}


virtual pdirectory::~pdirectory()
{
	//destructor
	for(int i = 0; i < 10; i++)
	{
		delete &(hashTable[i]);
	}
}


void pdirectory::insertContact(string name, int num, string email)
{
	//insert contact function
	bool found = false;
	int index = hashFun(name, tableSize);

	//check if the hash table array index has a node in the bucket
	if(&hashTable[index] != NULL)
	{
		//find where to place the new node in a bucket that already has nodes
		for(int i = 0; i < hashTable[index]->size(); i++)
		{
			if(name.compare((hashTable[index])[i].title) < 0)
			{
				*(hashTable[index])[i].name.insert(i, name);
				*(hashTable[index])[i].phone.insert(i, num);
				*(hashTable[index])[i].email.insert(i, email);
				found = true;
			}
		}
		if(found == false)
		{
			hashTable[index].name.push_back(name);
			hashTable[index].phone.push_back(num);
			hashTable[index].email.push_back(email);
			hashTable[index].next = NULL;
		}
	}
	//if bucket empty add the new info
	else
	{
		hashTable[index].title.push_back(in_title);
		hashTable[index].year.push_back(in_year);
		hashTable[index].next = NULL;
	}
}


void pdirectory::deleteContact(std::string inName)
{

}


int pdirectory::editContact(std::string inName)
{

}


Contact* pdirectory::findContact(std::string inName, int *index)
{
	int index = hashFun(inName,tableSize);
	bool found = false;

	// If a node exist at this hash location.
	if (hashTable[index] != NULL)
	{
		// Go through every vector index at this hash location.
		for (int j = 0; j < hashTable[index]->size(); j++)
		{
			// If we find the contact in the vector, print it.
			if ((*hashTable[index])[j].title == name)
			{
                cout << "Name   : "(*hashTable[index])[j].name << endl;
                cout << "Cell   : "(*hashTable[index])[j].phone << endl;
                cout << "Email  : "(*hashTable[index])[j].email << endl;
				found = true;
				break;
			}
		}
	}
	if (found == false)
	{
		cout << "Contact could not be found." << endl;
	}
	return;
}

// Print all the contacts in the directory
void pdirectory::printDirectory()
{
    bool empty = true;
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i] != NULL)
        {
            for (int j = 0; j < hashTable[i]->size(); j++)
            {
                cout << "(" << i << ")" << endl;
                cout << "Name   : "(*hashTable[i])[j].name << endl;
                cout << "Cell   : "(*hashTable[i])[j].phone << endl;
                cout << "Email  : "(*hashTable[i])[j].email << endl;
                cout << " " << endl;
                empty = false;
            }
        }
    }
    if (empty == true)
		cout << "No contact found in the directory. << endl;
	return;
}


// Hash Sum function for the contact's name
int pdirectory::hashFun(std::string inName, int hashSize)
{
    int theSum = 0;
    for (int i = 1; i < inName.length(); i++)
    {
        // ASCII value for each of the char in the string
        theSum = theSum + inName[i];
    }
    theSum = theSum % hashSize;
    return theSum;
}
