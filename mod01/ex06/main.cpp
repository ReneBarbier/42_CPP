#include "harl.hpp"

int main(int argv, char **argc)
{
    Harl harl;
    int filter = -1;
    if (argv != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 0;
    }
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
        if (argc[1] == level[i])
            filter = i;
    switch (filter)
    {
        case 0:
            harl.complain("debug");
        case 1:
            harl.complain("info");
        case 2:
            harl.complain("warning");
        case 3:
            harl.complain("error");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }   
}
