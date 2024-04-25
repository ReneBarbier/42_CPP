#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &copy);
        WrongCat &operator=(WrongCat const &copy);
        ~WrongCat();

        void makeSound() const;
};

#endif