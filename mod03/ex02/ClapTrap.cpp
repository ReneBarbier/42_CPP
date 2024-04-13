#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    this->_name = name;
}

ClapTrap::ClapTrap(ClapTrap const &clap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = clap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clap)
{
    std::cout << "Copy assignament operator called" << std::endl;
    this->_attackDamage = clap._attackDamage;
    this->_energyPoints = clap._energyPoints;
    this->_hitPoints = clap._hitPoints;
    this->_name = clap._name;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    if (this->_hitPoints <= 0)
        std::cout << this->_name << " is dead..." << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << this->_name << " has no energy points..." << std::endl;
    else
    {
        std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " of damage!" << std::endl;
        this->_energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amout)
{
    this->_hitPoints -= amout;
    if (this->_hitPoints <= 0)
        std::cout << this->_name << " has been slain!" << std::endl;
    else
        std::cout << this->_name << " has taken " << amout << " of damage and has now " << this->_hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amout)
{
    if (this->_energyPoints == 0)
        std::cout << this->_name << " can't be repaired. (0 energy points)" << std::endl;
    else
    {
        this->_hitPoints += amout;
        this->_energyPoints--;
        std::cout << this->_name << " gets repaired and has now " << this->_hitPoints << " hit points!" << std::endl; 
        if (this->_energyPoints == 0)
            std::cout << this->_name << " has run out of energy points!" << std::endl;
    }
}



