#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int _gradeToSign;
        int _gradeToExecute;
    public:
		Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &cpy);
        virtual ~Form();
       	
		//GETTERS
        std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToExecute() const;
		int			getGradeToSign() const;

        void		beSigned(Bureaucrat const &b);
		virtual void execute(Bureaucrat const &executor) const = 0;
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
