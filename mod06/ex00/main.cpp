#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error: Invalid number of arguments" << std::endl, 1);
	ScalarConverter convert;
	convert.convert(argv[1]);
	return (0);
}
