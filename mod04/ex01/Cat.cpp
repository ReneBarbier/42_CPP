#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.type;
}

Cat &Cat::operator=(Cat const &copy)
{
    std::cout << "Cat copy assigment operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "Meewwww!!" << std::endl;
}
