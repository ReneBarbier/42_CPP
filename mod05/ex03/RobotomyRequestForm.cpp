#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
{
	*this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	this->_target = cpy.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw Form::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	std::cout << "*drilling noises*" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy has failed (no aparent reason)." << std::endl;
}
