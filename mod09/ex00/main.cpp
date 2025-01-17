#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

std::map<std::string, float> getExchangeRates(std::ifstream inputFile)
{
	std::map<std::string, float> map;
	char c;
	char *key;
	char *value;
	bool key_value = true;

	while (inputFile) {
		c = inputFile.get();
		if (c == ',')
			key_value = !key_value;
		if (c == '\n') {
			key_value = !key_value;
			map.insert({key, std::atof(value.c_str())});
		}
		if (key_value)
			key += c;
		else
			value += c;
	}
	return map;
}

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "ERROR: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]); // whatchout for nulls and thigs
	if (!inputFile.is_open()) {
		std::cerr << "ERROR: Unable to open file " << argv[1] << std::endl;
		return 1;
	}	
	std::map<std::string, float> exchangeRates = getExchangeRates(inputFile);	
	return 0;
}
