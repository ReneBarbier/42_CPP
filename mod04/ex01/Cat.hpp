#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
    public:
        Cat();
        Cat(Cat const &copy);
        Cat &operator=(Cat const &copy);
        ~Cat();

        void makeSound() const;
};

#endif