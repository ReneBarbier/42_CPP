#include "Zombie.hpp"

int main(void)
{
    Zombie *tmp = newZombie("Colon");
    tmp->announce();
    randomChump("Marcelo");
    delete tmp;
}