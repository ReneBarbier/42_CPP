#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon &weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon &type);
        ~HumanA(void);
        void attack(void);
        //void setWeapon(Weapon type);
};

#endif
