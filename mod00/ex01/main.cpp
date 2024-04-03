#include "phonebook.hpp"

int main(void)
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
        std::getline(std::cin, command);
		if (std::cin.eof())
			return 0;
        if (command == "ADD" || command == "1")
		{
            if (ADD(&pb))
				return 0;
		}
		else if (command == "SEARCH" || command == "2")
        {
            if (pb.num == 0)
                std::cout << "No contacts saved yet, use 'ADD'\n" << std::endl;
            else if (SEARCH(&pb))
					return 0;
        }
        else if (command == "EXIT" || command == "3")
            break;
        else
            std::cout << "\nInvalid command\n" << std::endl;
    }
}
