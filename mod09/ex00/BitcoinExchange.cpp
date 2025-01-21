#include "BitcoinExchange.hpp"

std::map<std::string, double> getExchangeRates(std::ifstream &inputFile)
{
    std::map<std::string, double> exchangeRates;
    std::string line;
    
    while (std::getline(inputFile, line)) {
        size_t commaPos = line.find(','); 
        if (commaPos != std::string::npos) {
            std::string key = line.substr(0, commaPos);
            std::string value = line.substr(commaPos + 1);
            exchangeRates.insert(std::make_pair(key, atof(value.c_str())));
        }
    }

    return exchangeRates;
}
bool isDateValid(const std::string &date) {
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

std::string getDate(const std::string &line)
{
	std::string date;
	int i = 0;

	while (line[i] && line[i] != '|' && line[i] != '\n')
		date += line[i++];
	if (i != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ')
		return (std::cout << "Error: bad input => " << date << "\n", "");
	for (int i = 0; i < 10; i++)
		if (!std::isdigit(date[i]) && i != 4 && i != 7)	
			return (std::cout << "Error: bad input => " << date << "\n", "");
	if (!isDateValid(date))
		return (std::cout << "Error: bad input => " << date << "\n", "");
	return date;
}

bool isZero(const std::string &str) {
    bool dotFound = false;

	if (str == "")
		return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (dotFound) 
                return false;
			if (i == 0 || i == str.length() - 1)
				return false;
            dotFound = true;
        } else if (str[i] != '0')
            return false;
    }
    return true;
}

float getAmount(const std::string &line)
{
	std::string amount = "";
	double number;
	int i = 13;

	if (!line[12] || line[12] != ' ')
		return (std::cout << "Error: bad input => " << line << "\n", -1);	
	while (line[i]) {
		if (!std::isdigit(line[i]) && line[i] != '.' && line[i] != '-')
			return (std::cout << line[i] << "m\n", -1);
		amount += line[i];
		i++;
	}
	number = atof(amount.c_str());	
	if (!std::isfinite(number) || number > 1000)
		return (std::cout << "Error: too large a number.\n", -1);
	if (number == 0 && !isZero(amount)) //checks if atof() failed
		return (std::cout << "Error: not a valid number.\n", -1);
	if (number < 0)
		return (std::cout << "Error: not a positive number.\n", -1);
	return number; 
}

void exchange(std::ifstream &inputFile, std::map<std::string, double> data_base)
{
	std::string line;
	std::string date;
	float amount;
	
	while (std::getline(inputFile, line)) {
		if ((date = getDate(line)) == "")
			continue ;
		if ((amount = getAmount(line)) < 0)
			continue ;
		std::map<std::string, double>::iterator m_it = data_base.find(date);
		if (m_it == data_base.end()) {
			m_it = data_base.upper_bound(date);
			m_it--;
		}
		std::cout << date << "=> " << amount << " = " << m_it->second * amount << "\n";
	}
}
