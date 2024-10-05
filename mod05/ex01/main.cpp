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
<<<<<<< HEAD
=======
    std::cout << "---------------------" << std::endl;
    {
        Bureaucrat miquel("Miquel", 2);
        try
        {
            miquel.incrementGrade();
            std::cout << miquel << std::endl;
            miquel.incrementGrade();
            std::cout << miquel << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "---------------------" << std::endl;
    {
        Bureaucrat jordi("Jordi", 149);
        try
        {
            jordi.decrementGrade();
            std::cout << jordi << std::endl;
            jordi.decrementGrade();
            std::cout << jordi << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
>>>>>>> 67d0c77fea34c71609e657bbaf74b775e15c7f8e
}
