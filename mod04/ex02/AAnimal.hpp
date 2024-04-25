#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        AAnimal(AAnimal const &copy);
        AAnimal &operator=(AAnimal const &copy);
        virtual ~AAnimal();
        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
};

#endif