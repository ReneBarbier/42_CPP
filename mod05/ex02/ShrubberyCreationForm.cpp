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

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();	
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException(); 
	std::ofstream file(this->getTarget().append("_shrubbery").c_str());
	file << "         ccee88oo\n";
	file << "      C8O8O8Q8PoOb o8oo\n";
    file << "    dOB69QO8PdUOpugoO9bD\n";
	file << "   CgggbU8OU qOp qOdoUOdcb\n";
	file << "       6OuU  /p u gcoUodpP\n";
	file << "         \\\\\\//  /douUP\n";
	file << "           \\\\\\////\n";
	file << "            |||/\\\n";
	file << "            |||\\/\n";
	file << "            ||||||\n";
	file << "            ||||||\n";
	file << "            ||||||\n";
	file << "          __||||||__\n";
	file.close();
}
