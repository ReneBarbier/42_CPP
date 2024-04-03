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
        void addContact(Contact c)
        {
            for (int i = num -1; i >= 0; i--)
                contacts[i + 1] = contacts[i];
            contacts[0] = c;
            if (num < 7) // maybe 8?
                num++;
        }
        Contact searchContact(std::string name)
        {
            for (int i = 0; i < 8; i++)
            {
                if (contacts[i].firstName == name)
                    return contacts[i];
            }
            return Contact();
        }
};

void adjustInputs(Contact *c);
void printTable(PhoneBook *pb);

#endif