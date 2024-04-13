#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2("FR4G-TP");
    ClapTrap clap3("Cluck-Trap");
    
    clap1.attack("someone over there");
    clap3.attack("FR4G-TP");
    clap2.takeDamage(8);
    clap2.beRepaired(5);
    clap1.takeDamage(5);
    clap1.takeDamage(5);
    clap1.attack("someone over there");
    return (0);
}