#include "Bureaucrat.hpp"

int main(void)
{
	{
        try
        {
            Bureaucrat miquel("Miquel", -2);
            std::cout << miquel << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "---------------------" << std::endl;
    {
        try
        {
            Bureaucrat jordi("Jordi", 151);
            std::cout << jordi << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
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
        try {
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
}
