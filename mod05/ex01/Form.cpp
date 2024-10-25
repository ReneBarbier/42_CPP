#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _gradeToSign(100), _gradeToExecute(50) 
{
    _signed = false;
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    _signed = false;
	std::cout << "Form parametric constructor called" << std::endl;
}

Form::Form(Form const &cpy) : _name(cpy._name + "_copy"), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
     _signed = cpy._signed;
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &cpy)
{
	_signed = cpy._signed;
	std::cout << "Form assignation operator called" << std::endl;
	return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() >= _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Form const &src)
{
	os << "Form name: " << src.getName() << std::endl;
	os << "Form signed: " << src.getSigned() << std::endl;
	os << "Form grade to sign: " << src.getGradeToSign() << std::endl;
	os << "Form grade to execute: " << src.getGradeToExecute() << std::endl;
	return os;
}
