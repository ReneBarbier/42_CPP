#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
    public:
        Dog();
        Dog(Dog const &copy);
        Dog &operator=(Dog const &copy);
        ~Dog();

        void makeSound() const;
};

#endif