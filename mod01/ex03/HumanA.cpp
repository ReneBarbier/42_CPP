#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type): weapon(type)
{
    this->name = name;
    //this->weapon = type;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType();
    std::cout << std::endl;
}
