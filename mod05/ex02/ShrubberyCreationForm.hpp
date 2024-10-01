#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target; 
	public:
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm();

		
		
}
