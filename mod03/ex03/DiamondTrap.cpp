#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &Diamond)
{
    std::cout << "DiamondTrap copy assignament operator called" << std::endl;
    this->FragTrap::_attackDamage = Diamond.FragTrap::_attackDamage;
    this->ScavTrap::_energyPoints = Diamond.ScavTrap::_energyPoints;
    this->FragTrap::_hitPoints = Diamond.FragTrap::_hitPoints;
    this->_name = Diamond._name;
    return (*this);
}

void DiamondTrap::whoAmI() const
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}