#include "Fixed.hpp"

Fixed::Fixed() 
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignament operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float n)
{
	this->_value = roundf(n * (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl; // debug message
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl; // debug message
	_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
