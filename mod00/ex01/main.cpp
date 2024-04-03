#include <iostream>
#include "phonebook.hpp"
//issue when pressing Ctrl D when creating a new contact
//issue when typing in a non numerical character when asked to input an index
void ADD(PhoneBook *pb)
{
    Contact cont;
    std::cout << "Save a new contact" << std::endl;
    std::cout << "First name: ";
    std::cin >> cont.firstName;
    std::cout << "Last name: ";
    std::cin >> cont.lastName;
    std::cout << "Nickname: ";
    std::cin >> cont.nickname;
    std::cout << "Phone number: ";
    std::cin >> cont.phoneNumber;
    std::cout << "Darkest Secret: ";
    std::cin >> cont.secret;
    if (cont.firstName == "" || cont.lastName == "" || \
    cont.nickname == "" || cont.secret == "" || cont.phoneNumber == "")
    {
        std::cout << "Information invalid, contact not saved\n" << std::endl;
        return;
    }
    pb->addContact(cont);
    std::cout << "Contact saved.\n" << std::endl;
}

void SEARCH(PhoneBook *pb)
{
    int index;
    printTable(pb);
    std::cout << "Search for a contact" << std::endl;
    std::cout << "Input the index of the desired contact: ";
    std::cin >> index;
    if (index <= pb->num && index > 0)
    {
        std::cout << "\n[Information about contact index " << index << "]" << std::endl;
        std::cout << "First name: " << pb->contacts[index - 1].firstName << std::endl;
        std::cout << "Last name: " << pb->contacts[index - 1].lastName << std::endl;
        std::cout << "Nickname: " << pb->contacts[index - 1].nickname << std::endl;
        std::cout << "Phone number: " << pb->contacts[index - 1].phoneNumber << std::endl;
        std::cout << "Darkest secret: " << pb->contacts[index - 1].secret<<"\n"<< std::endl;
        return ;
    }
    std::cout << "Invalid index\n" << std::endl;
}

int main()
{
    PhoneBook pb;
    std::string command;
    pb.num = 0;

    while (1)
    {
        std::cout << "Please type in a command option" << std::endl;
        std::cout << "\'ADD\' a contact" << std::endl;
        std::cout << "\'SEARCH\' a contact" << std::endl;
        std::cout << "\'EXIT\' the program" << std::endl;
        std::cin >> command;
        if (command == "ADD" || command == "1")
        {
            ADD(&pb);
        }
        else if (command == "SEARCH" || command == "2")
        {
            if (pb.num == 0)
            {
                std::cout << "No contacts saved yet, use 'ADD'" << std::endl;
            }
            else
            {
                SEARCH(&pb);
            }
        }
        else if (command == "EXIT" || command == "3")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command\n" << std::endl;
        }
    }
}
