#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Constructor called for Intern. just an intern." << std::endl;
}

Intern::Intern(Intern const &cpy)
{
	(void)cpy;
}

Intern &Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Destructor called for Intern" << std::endl;
}

Form *shrubbery(std::string target)
{
	return new ShrubberyCreationForm(target); 
}

Form *robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form *presidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (*formClasses[])(std::string) = {shrubbery, robotomy, presidential};

	for (int i = 0;i < 3; i++)
	{
		if (name == formNames[i])
			return formClasses[i](target);
	}
	std::cout << "No form named \"" << name << "\"" << std::endl;
	return NULL;
}
