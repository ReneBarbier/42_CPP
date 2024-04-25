#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &scav);
        ~ScavTrap(void);

        ScavTrap & operator=(ScavTrap const &scav);

        void guardGate(void);
		void attack(std::string const &target);
};

#endif