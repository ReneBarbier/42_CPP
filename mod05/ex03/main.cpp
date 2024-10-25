#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat kevin("Kevin", 30);
		Intern allan;
		Form *a;

		a = allan.makeForm("gym membership form", "joe");
		a = allan.makeForm("robotomy request", "clawn");

		try {
			kevin.signForm(*a);
			kevin.executeForm(*a);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
