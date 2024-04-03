#include "phonebook.hpp"

int ADD(PhoneBook *pb)
{
    Contact cont;
    std::cout << "Save a new contact" << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, cont.firstName);
	if (std::cin.eof())
		return 1;
	std::cout << "Last name: ";
	std::getline(std::cin, cont.lastName);
	if (std::cin.eof())
		return 1;
	std::cout << "Nickname: ";
	std::getline(std::cin, cont.nickname);
	if (std::cin.eof())
		return 1;
	std::cout << "Phone number: ";
	std::getline(std::cin, cont.phoneNumber);
	if (std::cin.eof())
		return 1;
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, cont.secret);
	if (std::cin.eof())
		return 1;
    if (cont.firstName == "" || cont.lastName == "" || \
    cont.nickname == "" || cont.secret == "" || cont.phoneNumber == "")
    {
        std::cout << "Information invalid, contact not saved\n" << std::endl;
        return 0;
    }
    pb->addContact(cont);
    std::cout << "\nContact saved.\n" << std::endl;
	return 0;
}

int SEARCH(PhoneBook *pb)
{
    int index;
	std::string input;
    printTable(pb);
    std::cout << "Search for a contact" << std::endl;
    std::cout << "Input the index of the desired contact: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return 1;
	index = atoi(input.c_str());
    if (index <= pb->num && index > 0)
    {
        std::cout << "\n[Information about contact index " << index << "]" << std::endl;
        std::cout << "First name: " << pb->contacts[index - 1].firstName << std::endl;
        std::cout << "Last name: " << pb->contacts[index - 1].lastName << std::endl;
        std::cout << "Nickname: " << pb->contacts[index - 1].nickname << std::endl;
        std::cout << "Phone number: " << pb->contacts[index - 1].phoneNumber << std::endl;
        std::cout << "Darkest secret: " << pb->contacts[index - 1].secret<<"\n"<< std::endl;
        return 0;
    }
    std::cout << "\nInvalid index\n" << std::endl;
	return 0;
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
        tmp[i].firstName = pb->contacts[i].firstName;
        tmp[i].lastName = pb->contacts[i].lastName; 
        tmp[i].nickname = pb->contacts[i].nickname; 
        tmp[i].phoneNumber = pb->contacts[i].phoneNumber;
        tmp[i].secret = pb->contacts[i].secret;
        adjustInputs(&tmp[i]);
        std::cout << "|"<<i+1<<"         |"<<tmp[i].firstName<<"|"<<tmp[i].lastName<<"|" \
        <<tmp[i].nickname<<"|"<< std::endl;
    }
    std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n" << std::endl;
}