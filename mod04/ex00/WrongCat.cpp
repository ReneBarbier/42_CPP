#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = copy.type;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
    std::cout << "WrongCat copy assigment operator called" << std::endl;
    this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "wwwweeM!!" << std::endl;
}
