#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called for " << name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &frag) : ClapTrap(frag)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = frag;
}

FragTrap &FragTrap::operator=(FragTrap const &frag)
{
    std::cout << "FragTrap copy assignament operator called" << std::endl;
    this->_attackDamage = frag._attackDamage;
    this->_energyPoints = frag._energyPoints;
    this->_hitPoints = frag._hitPoints;
    this->_name = frag._name;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->_name << " says: Gimme five!" << std::endl;
}