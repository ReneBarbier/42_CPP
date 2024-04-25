#include "AMateria.hpp"

AMateria::AMateria(void)
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria &copy)
{
	this->_type = copy.getType();
}

AMateria &AMateria::operator=(AMateria &copy)
{
	this->_type = copy.getType();
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType(void) const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "default" << std::endl;
}