#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    protected:
        std::string const _name;
        bool _signed;
        int _gradeToSign;
        int _gradeToExecute;
    public:
        AForm(int _gradeToExecute);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &cpy);
        ~AForm();
        
        std::string getName();
        void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const & executor) const;
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
