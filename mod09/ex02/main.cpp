#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error\n";
		return 1;
	}

	std::vector<int> vec = getVector(++argv);
	std::deque<int> deq(vec.begin(), vec.end());

	std::cout << "Before: ";
	printVec(vec);

	double timeVec = PmergeMeVec(&vec);
	//double timeDeq = PmergeMeDeque(&deq);

	std::cout << "After: ";
	printVec(vec);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << timeVec << " us\n";
	// std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << timeDeq << " us\n";

	return 0;
}
