#include "BitcoinExchange.hpp"

void printFile(std::ifstream& file) {
	std::cout << "File content:" << std::endl;
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
}

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "ERROR: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
	std::ifstream input_file(argv[1]); // whatchout for nulls and thigs
	std::ifstream data_base("data.csv");
	if (!input_file.is_open() || !data_base.is_open()) {
		std::cerr << "ERROR: Unable to open file " << argv[1] << std::endl;
		return 1;
	}	
	std::map<std::string, double> exchangeRates = getExchangeRates(data_base);	
	exchange(input_file, exchangeRates);
	
	return 0;
}
