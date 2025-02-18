#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP


#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target; 
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &cpy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &cpy);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const; 		
};

#endif
