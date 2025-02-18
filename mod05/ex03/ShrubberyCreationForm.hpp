#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target; 
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &cpy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &cpy);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const; 		
};

#endif
