#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		Bureaucrat john("John", 5);
		RobotomyRequestForm a("user");

		try {
			john.signForm(a);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			john.executeForm(a);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
