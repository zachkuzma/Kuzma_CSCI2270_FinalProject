/* Author: Zach Kuzma, Chuan 'Nelson' Khor
 * Final Project
 * Instructor: Hoenigman
 * References: HashTable.h
 * Description: Header File
 */

#ifndef PDIRECTORY_H
#define PDIRECTORY_H

struct Contact{
    std::string name;
    std::string phone;
    std::string email;

    Contact(){};

    Contact(std::string inName, std::string inPhone, std::string inEmail)
    {
        name = inName;
        phone = inPhone;
        email = inEmail;
    }
};


class pdirectory
{
    public:
        pdirectory();
        ~pdirectory();
        void insertContact(std::string inName, std::string inNum, std::string inEmail);
        void deleteContact(std::string inName);
        void editContact(std::string inName, std::string inNum, std::string inEmail, std::string newname);
        void findContact(std::string inName);
        void printDirectory();
        int hashFun(std::string inName, int hashSize); // Create a hash sum function for this project
        void exportDirectory();
        void clearScreen();
    private:
        int hashSize = 10;
        std::vector<Contact> *hashTable[10] = { NULL };

};

#endif // PDIRECTORY_H
