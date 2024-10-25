#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &cpy)
{
	(void)cpy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &cpy) 
{
	(void)cpy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


int checkInput(std::string input)
{
	std::size_t pos = std::string::npos;
	
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (0);
	if (input.find_first_not_of("0123456789+-f.") != std::string::npos)
		return (ERROR);
	if (input.find("+") != std::string::npos && input.find("-") != std::string::npos)
		return (ERROR);
	if (input.find("+") != std::string::npos)
		pos = input.find_last_of("+");
	else if (input.find("-") != std::string::npos)
		pos = input.find_last_of("-");
	pos = input.find_first_of("f");
	if (pos != std::string::npos && pos != input.length() - 1)
		return (ERROR);
	if (input.find(".") != std::string::npos)
	{
		if (input.find_first_of(".") != input.find_last_of("."))
			return (ERROR);
		pos = input.find(".");
		if (pos == 0 || pos == input.length() - 1 || input[pos + 1] == 'f')
			return (ERROR);
	}
	return (0);
}

int checkForSpecialCases(std::string input)
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return (1);
	}
	if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return (1);
	}
	return (0);
}

int checkOverflow(std::string input)
{
	if (input.find(".") != std::string::npos && input.find(".") > 10)
		return (ERROR);
	if (input.find(".") == std::string::npos && input.length() > 10)
		return (ERROR);
	long tmp = atol(input.c_str());
	if (tmp > 2147483647 || tmp < -2147483648)
		return (ERROR);
	return (0);
}

void fromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void fromInt(int n)
{
	if (n >= 32 && n <= 126)
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl; 
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void fromFloat(float n)
{
	if (n >= 32 && n <= 126)
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (std::floor(n) == n)
		std::cout << "float: " << n << ".0f" << std::endl;
	else
		std::cout << "float: " << n << "f" << std::endl;
	if (std::floor(n) == n)
		std::cout << "double: " << n << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void fromDouble(double n)
{
	if (n >= 32 && n <= 126)
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	if (std::floor(n) == n)
		std::cout << "float: " << n << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	if (std::floor(n) == n)
		std::cout << "double: " << n << ".0" << std::endl;
	else
		std::cout << "double: " << n << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	if (checkForSpecialCases(input))
		return;

	if (checkInput(input))
		return (std::cout << "Error: Invalid input" << std::endl, void());

	if (checkOverflow(input))
		return (std::cout << "Error: Overflow" << std::endl, void());

	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		fromChar(input[0]);
	else if (input.find("f") != std::string::npos)
		fromFloat(atof(input.c_str()));
	else if (input.find(".") != std::string::npos)
		fromDouble(atof(input.c_str()));
	else
		fromInt(atoi(input.c_str()));
}
