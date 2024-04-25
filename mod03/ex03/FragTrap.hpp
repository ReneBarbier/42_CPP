#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &frag);
        ~FragTrap(void);

        FragTrap & operator=(FragTrap const &frag);

        void highFivesGuys(void);
};

#endif