#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string secret;
        std::string phoneNumber;
};

class PhoneBook {
    public:
        Contact contacts[8];
        PhoneBook();
        ~PhoneBook();
		int num;
        void addContact(Contact c);
};

void adjustInputs(Contact *c);
void printTable(PhoneBook *pb);
int ADD(PhoneBook *pb);
int SEARCH(PhoneBook *pb);

#endif