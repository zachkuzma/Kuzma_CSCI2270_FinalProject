#ifndef PDIRECTORY_H
#define PDIRECTORY_H

struct Contact{
    std::string name;
    int phone;
    std::string email;
    Contact *next;
    Contact *prev;

    Contact(){};

    Contact(std::string inName, int inPhone, std::string inEmail)
    {
        name = inName;
        phone = inPhone;
        email = inEmail;
    }
};


class pdirectory
{
    public:
        pdirectory(int);
        virtual ~pdirectory();
        void insertContact(std::string inName);
        void deleteContact(std::string inName);
        int editContact(std::string inName);
        Contact* findContact(std::string inName, int *index);
        void printDirectory();

        int hashFun(std::string inName, int hashSize); // Create a hash function for this project

    protected:
    private:
        Contact *hashTable;
};

#endif // PDIRECTORY_H
