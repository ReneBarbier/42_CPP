#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string _name;
	public:
		Ice(std::string name);
		~Ice();

		void use(ICharacter& target);
};