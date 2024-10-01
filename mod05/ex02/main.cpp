#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
        Form a("A", 120, 40);
        Bureaucrat john("John", 110);

        john.signForm(a);
    }
    std::cout << "---------------------" << std::endl;
    {
       Form b("B", 90, 30);
	   Bureaucrat mark("Mark", 100);

	   mark.signForm(b);
    }
}
