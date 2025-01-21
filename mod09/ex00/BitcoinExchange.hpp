#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <map>
#include <fstream>

std::map<std::string, double> getExchangeRates(std::ifstream &inputFile);
void exchange(std::ifstream &inputFile, std::map<std::string, double> data_base);

#endif
