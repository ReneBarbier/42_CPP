#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _gradeToSign(100), _gradeToExecute(50) 
{
    _signed = false;
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    _gradeToSign = gradeToSign;
    _gradeToExecute = gradeToExecute;
    _signed = false;
	std::cout << "Constructor called for " << _name << std::endl;
}

AForm::AForm(AForm const &cpy) : _name(cpy._name), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
     _signed = cpy._signed;
    std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Destructor called for " << _name << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() >= _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == true)
	{
		if (executor.getGrade() > this->_gradeToExecute)
			throw AForm::GradeTooLowException(); 
		if (executor.getGrade() < 1)
			throw AForm::GradeTooHighException();
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "Form not signed";
}
