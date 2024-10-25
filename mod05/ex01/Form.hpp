#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        const int _gradeToSign;
		const int _gradeToExecute;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &cpy);
		Form &operator=(Form const &cpy);
        ~Form();
        
        std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

        void beSigned(Bureaucrat const &b);
        
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

std::ostream &operator<<(std::ostream &os, Form const &src);

#endif
