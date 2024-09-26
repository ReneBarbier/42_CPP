#pragma once

#include <iostream>

class ScalarConverter 
{
	private:
		int getType();
		std::string getInput();
    public:
		static void convert(std::string input);
		virtual ~ScalarConverter() = 0;
};
