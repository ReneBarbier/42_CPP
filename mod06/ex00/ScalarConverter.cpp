#include "ScalarConverter.hpp"
#include <cctype>

void ScalarConverter::convert(const std::string &input) {
	int type;

	type = ScalarConverter::getType(input);
	if (type == 1)
		ScalarConverter::strToInt();
	else if (type == 2)
		ScalarConverter::strToChar();
	else if (type == 3)
		ScalarConverter::strToFloat();
	else if (type == 4)
		ScalarConverter::strToDouble();
}

int ScalarConverter::getType(std::string input)
{
	if (input.length() == 1 && std::isalpha(input[0])
		return (CHAR);
	if ()
}
