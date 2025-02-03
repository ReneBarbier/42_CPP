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
	if (rec_level * 2 > vec->size() / 2)
		return;

	std::vector<int>::iterator it = rec_level ? vec->begin() + rec_level * 2 - 1 : vec->begin();
	std::vector<int>::iterator it2 = rec_level ? vec->begin() + rec_level * 4 - 1 : vec->begin() + 1;

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

		if (!safeIter(&it2, vec->end(), (rec_level + 1) * 2))
			break;
		it += (rec_level + 1) * 2;
	}
	//debug
	std::cout << "Recursion level: " << rec_level + 1 << std::endl;
	printVec(*vec);

	pairSortRec(vec, ++rec_level);
}
	
double PmergeMeVec(std::vector<int> *vec) {
	time_t start = time(NULL);

	pairSortRec(vec, 0);

	time_t end = time(NULL);
	return difftime(end, start);
}
