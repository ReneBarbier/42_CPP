#include "PmergeMe.hpp"

std::vector<int> getVector(char **input)
{
	std::vector<int> vec;

	if (!input || !*input) {
		std::cerr << "Error\n";
		exit(1);
	}

	while (*input) {
		if (!isdigit(**input)) {
			std::cerr << "Error\n";
			exit(1);
		}
		vec.push_back(atoi(*input));
		input++;
	}

	return vec;
}

void printVec(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();

	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

bool safeIter(std::vector<int>::iterator *it, std::vector<int>::iterator end, int iterations)
{
	while (iterations > 0) {
		if (*it == end) {
			return false;
		}
		(*it)++;
		iterations--;
	}
	return true;
}

void pairSortRec(std::vector<int> *vec, unsigned rec_level)
{
	if (pow(2, rec_level) > vec->size() / 2)
		return;

	std::vector<int>::iterator it = rec_level ? vec->begin() + pow(2, rec_level) - 1 : vec->begin();
	std::vector<int>::iterator it2 = rec_level ? vec->begin() + pow(2, rec_level + 1) - 1: vec->begin() + 1;

	std::vector<int>::iterator decoy1;
	std::vector<int>::iterator decoy2;

	while (it2 != vec->end())
	{
		if (*it > *it2) {
			decoy1 = it;
			decoy2 = it2;
			while (decoy2 != it) {
				std::swap(*decoy1, *decoy2);
				decoy1--;
				decoy2--;
			}
		}

		if (!safeIter(&it2, vec->end(), pow(2, rec_level + 1)))
			break;
		it += pow(2, rec_level + 1); 
	}

	//debug
	std::cout << "Recursion level: " << rec_level + 1 << std::endl;
	printVec(*vec);

	pairSortRec(vec, ++rec_level);
}

int jacobsthal(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int a = 0, b = 1;
	for (int i = 2; i <= n; ++i) {
		int temp = b;
		b = b + 2 * a;  // J(i) = J(i-1) + 2 * J(i-2)
		a = temp;
	}
	return b;  // Return J(n)
}

std::list<element>::iterator jacobsthalInit(std::list<element> &pend, int rec_level)
{
	std::list<element>::iterator it = pend.begin();
	int insertions = jacobsthal(rec_level + 3) - jacobsthal(rec_level + 2);

	// if the number of insertions is greater than the number of elements in pend
	// it will return the last element. But then its the end of the recursion (no more elements to insert)
	std::advance(it, insertions);
	return it;
}

void insertion(std::vector<int> *vec, int rec_level)
{
	std::list<element> main;
	std::list<element> pend;

	initMain(&main, vec, rec_level);
	initPend(&pend, vec, rec_level);

	while (!pend.empty()) {
		std::list<element>::iterator insert = jacobsthalInit(pend, rec_level);
		std::list<element>::iterator slot = main.begin();

		
	}	

}
	
double PmergeMeVec(std::vector<int> *vec) {
	time_t start = time(NULL);

	pairSortRec(vec, 0);
	//insertion(vec);
	std::cout << "jacob: " << jacobsthal(17) << std::endl;

	time_t end = time(NULL);
	return difftime(end, start);
}
