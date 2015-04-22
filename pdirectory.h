#ifndef PDIRECTORY_H
#define PDIRECTORY_H

struct Contact{
    std::string name;
    int phone;
    std::string email;
    std::string address;
    Contact *next;
    Contact *prev;

    Contact(){};

    Contact(std::string name, int phone, std::string email, std::string address)
    {
        name = inName;
        phone = inPhone;
        email = inEmail;
        address = inAddress;
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
        Contact* findContact(std::string in_title, int *index);
        void printDirectory();

        int hashFun(std::string inName); // Create a hash function for this project

    protected:
    private:
        Contact *hashTable;
};

#endif // PDIRECTORY_H
