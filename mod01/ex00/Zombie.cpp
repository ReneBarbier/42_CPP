#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie " << name << " has emerged from it's grave!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "'" << name << "' has died, wait..." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}