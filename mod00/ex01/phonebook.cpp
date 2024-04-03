#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Welcome to the phonebook" << std::endl;
}
PhoneBook::~PhoneBook()
{
    std::cout << "Goodbye" << std::endl;
}

void PhoneBook::addContact(Contact c)
{
	for (int i = this->num -1; i >= 0; i--)
		contacts[i + 1] = contacts[i];
	contacts[0] = c;
	if (this->num < 8)
		this->num++;
}
