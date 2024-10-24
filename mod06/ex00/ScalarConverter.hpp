#pragma once

#include <iostream>
#include <cctype>
#include <cmath>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define ERROR 1

class ScalarConverter 
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &cpy);
		ScalarConverter &operator=(ScalarConverter &cpy);
		~ScalarConverter();
    public:
		static void convert(std::string input);
};
