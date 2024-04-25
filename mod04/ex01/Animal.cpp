#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "Default";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{   
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = copy.type;
}

Animal &Animal::operator=(Animal const &copy)
{
    std::cout << "Animal copy assignament operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "..." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}