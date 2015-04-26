/* Author: Zach Kuzma
 * Date: April 19, 2015
 * Assignment #9
 * Instructor: Hoenigman
 * References: TA and LAs
 * Description: Class File
 */

#include <iostream>
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
	//insert movie function
	bool found = false;
	int index = hashSum(name, tableSize);
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
Contact* pdirectory::findContact(std::string in_title, int *index)
{
	
}
void pdirectory::printDirectory()
{
	
}
int pdirectory::hashFun(std::string inName)
{
	
}
