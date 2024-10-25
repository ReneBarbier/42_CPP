#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &cpy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &cpy);
		~PresidentialPardonForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
