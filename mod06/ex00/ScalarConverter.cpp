#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
	int type;

	if (ScalarConverter::checkInput(input))
		return (std::cout << "Error: Invalid input" << std::endl, void());

	type = ScalarConverter::getType(input);

	if (type == CHAR)
		ScalarConverter::fromChar();
	else if (type == INT)
		ScalarConverter::fromInt();
	else if (type == FLOAT)
		ScalarConverter::fromFloat();
	else if (type == DOUBLE)
		ScalarConverter::fromDouble();
}
int ScalarConverter::getType(std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (ScalarConverter::strToChar(input), CHAR);
	if (input.find("f") != std::string::npos)
		return (ScalarConverter::strToFloat(input), FLOAT);
	if (input.find(".") != std::string::npos)
		return (ScalarConverter::strToDouble(input), DOUBLE);
	return (ScalarConverter::strToInt(input), INT);
}

int ScalarConverter::checkInput(std::string input)
{
	std::size_t pos = std::string::npos;
	
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	if (input.find_first_not_of("0123456789+-f") != std::string::npos)
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
	if (input.find("."))
	{
		if (std::count(input.begin(), input.end(), '.') > 1)
			return (ERROR);
		pos = input.find(".");
		if (pos == 0 || pos == input.length() - 1)
			return (ERROR);
	}
	return (0);
}

void ScalarConverter::strToChar(std::string input)
{
	this->_char = input[0];
}

void ScalarConverter::strToInt(std::string input)
{
	this->_int = std::atoi(input.c_str());
}

void ScalarConverter::strToFloat(std::string input)
{
	this->_float = std::atof(input.c_str());
}

void ScalarConverter::strToDouble(std::string input)
{
	this->_double = std::atof(input.c_str());
}

void ScalarConverter::fromChar()
{
	std::cout << "char: '" << this->_char << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(this->_char) << std::endl;
	std::cout << "float: " << static_cast<float>(this->_char) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_char) << ".0" << std::endl;
}

void ScalarConverter::fromInt()
{
	if (std::isprint(this->_int))
		std::cout << "char: " << static_cast<char>(this->_int) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl; 
	std::cout << "int: " << this->_int << std::endl;
	std::cout << "float: " << static_cast<float>(this->_int) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_int) << ".0" << std::endl;
}

void ScalarConverter::fromFloat()
{
	if (std::isprint(this->_float))
		std::cout << "char: '" << static_cast<char>(this->_float) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(this->_float) << std::endl;
	std::cout << "float: " << this->_float << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_float) << std::endl;
}

void ScalarConverter::fromDouble()
{
	if (std::isprint(this->_double))
		std::cout << "char: '" << static_cast<char>(this->_double) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(this->_double) << std::endl;
	std::cout << "float: " << static_cast<float>(this->_double) << "f" << std::endl;
	std::cout << "double: " << this->_double << std::endl;
}
