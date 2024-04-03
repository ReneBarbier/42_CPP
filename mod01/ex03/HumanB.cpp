#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->hasWeapon = 0;
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void)
{
    if (this->hasWeapon)
    {
        std::cout << this->name << " attacks with their " << this->weapon->getType();
        std::cout << std::endl;
    }
    else
        std::cout << this->name << "has no weapon!" << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
    this->weapon = &type;
    this->hasWeapon = 1;
}
