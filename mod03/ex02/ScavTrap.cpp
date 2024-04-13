#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called for " << name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &scav) : ClapTrap(scav)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scav;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scav)
{
    std::cout << "ScavTrap copy assignament operator called" << std::endl;
    this->_attackDamage = scav._attackDamage;
    this->_energyPoints = scav._energyPoints;
    this->_hitPoints = scav._hitPoints;
    this->_name = scav._name;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << this->_name << " have enterred in Gate keeper mode." << std::endl;
}