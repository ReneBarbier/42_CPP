#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) 
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
    std::cout << "Constructor called. Name " << _name << " Grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) 
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Destructor called for " << _name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & rhs)
{
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}

std::string Bureaucrat::getName() const 
{ 
    return _name;
}

int Bureaucrat::getGrade() const 
{ 
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << "successfully" <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " can't sign the form: " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
    os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return os;
}
