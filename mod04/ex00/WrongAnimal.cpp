#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "Default";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{   
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
    std::cout << "WrongAnimal copy assignament operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "* wrong animal noise *" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}