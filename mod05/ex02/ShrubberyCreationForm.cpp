#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy)
{
	*this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy)
{
	this->_target = cpy._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();	
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException(); 
	std::cout << "...\n";
	//create a file <target>_shrubbery in the working directory and writes ASCII trees inside it
}
