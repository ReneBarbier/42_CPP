#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "New zombie created!" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " has been removed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}