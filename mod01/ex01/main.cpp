#include "Zombie.hpp"

int main(void)
{
    int n = 5;

    Zombie *horde = zombieHorde(n, "fizz");
    for (int i = 0; i < n; i++)
    {
        horde[i].announce();
    }
    delete [] horde;
}