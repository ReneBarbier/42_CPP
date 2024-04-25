#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal default constructor called" << std::endl;
    this->type = "Default";
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{   
    std::cout << "AAnimal copy constructor called" << std::endl;
    this->type = copy.type;
}

AAnimal &AAnimal::operator=(AAnimal const &copy)
{
    std::cout << "AAnimal copy assignament operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}