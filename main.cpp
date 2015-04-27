/* Author: Zach Kuzma, Chuan 'Nelson' Khor
    Final Project
 * Instructor: Hoenigman
 * References: TA and LAs
 * Description: Main.cpp File
 */

 #include <iostream>
 #include <fstream>
 #include <stdlin.h>
 #include <string>
 #include <vector>
 #include "pdirectory.h"

 using namespace std;

 void displayMenu();

 int main()
 {
     // Initialize a variable for user's command
     int userInput;

     // Flag for existing menu
     bool quit = false;

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
                break;
            case 2: // Find contact
                break;
            case 3: // New contact
                break;
            case 4: // Edit contact
                break;
            case 5: // Delete contact
                break
            case 6: // Export current contact
                break
            case 7: // Quit
                cout << "Closing Directory. See you again!" << endl;
                quit = true;
                break;

            default:
                cout << "Invalid Input." << endl;
                cin.clear()
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
     cout << " (3) Write a new contact" << endl;
     cout << " (4) Edit a current contact's information" << endl;
     cout << " (5) Delete a current contact" << endl;
     cout << " (6) Export a copy of the contact" << endl;
     cout << " (7) Quit the program" << endl;
     cout << " " << endl;
     cout << " Your command: " ;
     return;
 }
