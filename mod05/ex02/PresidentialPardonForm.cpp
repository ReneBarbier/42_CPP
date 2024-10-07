#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presi please", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy)
{
	*this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	this->_target = cpy.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw PresidentialPardonForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << "president pardoned you" << std::endl;
}

