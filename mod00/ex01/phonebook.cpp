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
	for (int i = 6; i >= 0; i--)
		contacts[i + 1] = contacts[i];
	contacts[0] = c;
	if (num < 8)
		num++;
}
