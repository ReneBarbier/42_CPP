#include "Fixed.hpp"

//==================== CONSTRUCTORS / DESTRUCTORS ====================//
Fixed::Fixed() 
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}
Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}
Fixed &Fixed::operator=(const Fixed &fixed)
{
	//std::cout << "Copy assignament operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int n)
{
	this->_value = n << this->_fractionalBits;
}
Fixed::Fixed(const float n)
{
	this->_value = roundf(n * (1 << this->_fractionalBits));
}

//==================== COMPARASION OPERATORS ====================//
bool Fixed::operator>(const Fixed &fixed) const
{
	return this->_value > fixed.getRawBits();
}
bool Fixed::operator<(const Fixed &fixed) const
{
	return this->_value < fixed.getRawBits();
}
bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->_value >= fixed.getRawBits();
}
bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->_value <= fixed.getRawBits();
}
bool Fixed::operator==(const Fixed &fixed) const
{
	return this->_value == fixed.getRawBits();
}
bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->_value != fixed.getRawBits();
}

//==================== ARITHMETIC OPERATORS ====================//
float Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}
float Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}
float Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}
float Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

//==================== INCREMENT / DECREMENT OPERATORS ====================//
Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}
Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

//==================== MEMBER FUNCTIONS ====================//
int Fixed::getRawBits(void) const
{
	return _value;
}
void Fixed::setRawBits(int const raw)
{
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

//==================== STATIC FUNCTIONS ====================//
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
