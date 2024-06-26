#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;
    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &copy);
        DiamondTrap &operator=(DiamondTrap const &copy);
        ~DiamondTrap();

        void whoAmI() const;
};

#endif