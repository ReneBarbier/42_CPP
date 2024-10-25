#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &cpy);
		Intern &operator=(Intern const &cpy);
		~Intern();

		Form *makeForm(std::string name, std::string target);
};

#endif
