#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <list>
#include <string>

double PmergeMeVec(std::vector<int> *vec);
double PmergeMeDeque(std::deque<int> *deq);

struct elementVec {
	char type;
	int tag;
	std::vector<int> vec;
};

struct elementDeq {
	char type;
	int tag;
	std::deque<int> deq;
};

#endif
