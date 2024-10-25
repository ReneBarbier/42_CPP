#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeToSign(100), _gradeToExecute(50) 
{
    _signed = false;
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    _gradeToSign = gradeToSign;
    _gradeToExecute = gradeToExecute;
    _signed = false;
	std::cout << "Constructor called for " << _name << std::endl;
}

Form::Form(Form const &cpy) : _name(cpy._name), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
     _signed = cpy._signed;
    std::cout << "Copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called for " << _name << std::endl;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() >= _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (this->_signed == true)
	{
		if (executor.getGrade() > this->_gradeToExecute)
			throw Form::GradeTooLowException(); 
		if (executor.getGrade() < 1)
			throw Form::GradeTooHighException();
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *Form::FormNotSigned::what() const throw()
{
	return "Form not signed";
}
