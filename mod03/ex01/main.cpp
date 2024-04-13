#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clap1("CL4P-TP");
    ScavTrap clap2("SC4V-TP");
    
    clap2.guardGate();
    clap1.attack("someone over there");
    clap2.takeDamage(8);
    clap2.beRepaired(5);
    clap1.takeDamage(9);
    clap1.attack("someone over there");
    return (0);
}