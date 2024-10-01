#pragma once

#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define ERROR 1

class ScalarConverter 
{
	private:
		char	_char;
		int		_int;
		float	_float;
		double	_double;

		void fromChar();
		void fromInt();
		void fromFloat();
		void fromDouble();

		void strToChar(std::string input);
		void strToInt(std::string input);
		void strToFloat(std::string input);
		void strToDouble(std::string input);
		
		int getType(std::string input);
		int checkInput(std::string input);
		int checkForSpecialCases(std::string input);
		int checkOverflow(std::string input);
    public:
		void convert(std::string input);
		//virtual ~ScalarConverter() = 0;
};
