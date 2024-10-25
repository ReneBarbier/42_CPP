#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &cpy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &cpy);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

#endif
