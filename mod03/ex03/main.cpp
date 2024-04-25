#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap clap1("CL4P-TP");
    
    clap1.attack("someone over there");
    clap1.takeDamage(9);
	clap1.beRepaired(5);

	clap1.whoAmI();

    return (0);
}