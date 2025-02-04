#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <list>

double PmergeMeVec(std::vector<int> *vec);
double PmergeMeDeque(std::deque<int> *deq);
std::vector<int> getVector(char **input);
void printVec(std::vector<int> &vec);

struct element {
	std::string tag;
	std::vector<int> vec;
};

#endif
