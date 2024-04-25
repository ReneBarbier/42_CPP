#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = copy.type;
}

Dog &Dog::operator=(Dog const &copy)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "Guuaauu!!" << std::endl;
}
