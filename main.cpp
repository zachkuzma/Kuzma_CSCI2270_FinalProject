/* Author: Zach Kuzma, Chuan 'Nelson' Khor
 * Final Project
 * Instructor: Hoenigman
 * References:
 * Description: Main.cpp File
 */

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <sstream>
 #include <stdlib.h> 
 #include <vector>
 #include "pdirectory.h"

 using namespace std;

 void displayMenu();

 int main(int argc, char*argv[])
 {
	//import of current contacts
	string line = argv[1];
	ifstream in;
	in.open(line);
	
	pdirectory *directory;
	
	//creation of directory
	while(getline(in, line))
	{
		stringstream iss(line);
		string first;
		getline(iss, first, ',');
		string second;
		getline(iss, second, ',');
		string third;
		getline(iss, third);
		string name = first;
		string number = second;
		string email = third;
		
		directory->insertContact(name, number, email);
	}
	
	//directory->insertContact("Zach Kuzma", "7192099009", "zach@yahoo.com");
	 
     // Initialize a variable for user's command
     int userInput;

     // Flag for existing menu
     bool quit = false;
     
     //Input variables
     string input1;
     string input2;
     string input3;

     while(quit != true)
     {
         // Show the menu for selecting option and take in user's command
         displayMenu();
         cin >> userInput;
         cin.clear();
         cin.ignore(10000,'\n');

         switch(userInput)
         {
            case 1: // Print the phone directory
				directory->printDirectory();
                break;
            case 2: // Find contact
				cout << "Enter Full Name of Contact: " << endl;
				getline(cin,input1);
				directory->findContact(input1);
                break;
            case 3: // New contact
				cout << "Enter Full Name of Contact: " << endl;
				getline(cin,input1);
				cout << "Enter Phone Number of Contact: " << endl;
				getline(cin,input2);
				cout << "Enter Email Address of Contact: " << endl;
				getline(cin,input3);
				directory->insertContact(input1,input2,input3);
                break;
            case 4: // Edit contact
				cout << "Enter Full Name of Contact: " << endl;
				getline(cin,input1);
				cout << "Enter Phone Number of Contact: " << endl;
				getline(cin,input2);
				cout << "Enter Email Address of Contact: " << endl;
				getline(cin,input3);
				directory->editContact(input1,input2,input3);
                break;
            case 5: // Delete contact
				cout << "Enter Full Name of Contact: " << endl;
				getline(cin,input1);
				directory->deleteContact(input1); 
                break;
            case 6: // Export current contact
				directory->exportDirectory();
                break;
            case 7: // Quit
                cout << " " << endl;
                cout << "Closing Directory. See you again!" << endl;
                quit = true;
                break;

            default:
                cout << "Invalid Input." << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
         }

     }
     return 0;
 }

 void displayMenu()
 {
     cout << " " << endl;
     cout << "********* Main Menu *********" << endl;
     cout << "Select one of the following option:" << endl;
     cout << " (1) Print current phone directory" << endl;
     cout << " (2) Find contact information" << endl;
     cout << " (3) Create a new contact" << endl;
     cout << " (4) Edit a current contact's information" << endl;
     cout << " (5) Delete a current contact" << endl;
     cout << " (6) Export a copy of the contact" << endl;
     cout << " (7) Quit the program" << endl;
     cout << "******************************" << endl;
     cout << " " << endl;
     cout << " Your command: " ;
     return;
 }
