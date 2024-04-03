#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Welcome to the phonebook" << std::endl;
}
PhoneBook::~PhoneBook()
{
    std::cout << "Goodbye" << std::endl;
}

void adjustInputs(Contact *c)
{
    for (int i = 0; i < 9; i++)
    {
        if (c->firstName.size() < 10)
            c->firstName.append(" ");
        if (c->lastName.size() < 10)
            c->lastName.append(" ");
        if (c->nickname.size() < 10)
            c->nickname.append(" ");
        if (c->secret.size() < 10)
            c->secret.append(" ");
        if (c->phoneNumber.size() < 10)
            c->phoneNumber.append(" ");
    }
    if (c->firstName.size() > 10)
    {
        c->firstName[9] = '.';
        c->firstName.resize(10);
    }
    if (c->lastName.size() > 10)
    {
        c->lastName[9] = '.';
        c->lastName.resize(10);
    }
    if (c->nickname.size() > 10)
    {
        c->nickname[9] = '.';
        c->nickname.resize(10);
    }
    if (c->secret.size() > 10)
    {
        c->secret[9] = '.';
        c->secret.resize(10);
    }
    if (c->phoneNumber.size() > 10)
    {
        c->phoneNumber[9] = '.';
        c->phoneNumber.resize(10);
    }
}

void printTable(PhoneBook *pb)
{
    Contact tmp[8];
    std::cout << "_____________________________________________" << std::endl;
    std::cout << "|  index   |first name| last name| nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < pb->num; i++)
    {
        tmp[i].firstName = pb->contacts[i].firstName; //probably wrong
        tmp[i].lastName = pb->contacts[i].lastName; 
        tmp[i].nickname = pb->contacts[i].nickname; 
        tmp[i].phoneNumber = pb->contacts[i].phoneNumber;
        tmp[i].secret = pb->contacts[i].secret;
        adjustInputs(&tmp[i]);
        std::cout << "|"<<i+1<<"         |"<<tmp[i].firstName<<"|"<<tmp[i].lastName<<"|" \
        <<tmp->nickname<<"|"<< std::endl;
    }
    std::cout << "_____________________________________________" << std::endl;
}