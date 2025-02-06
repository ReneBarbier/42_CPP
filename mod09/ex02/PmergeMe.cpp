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

// print the vector
void printVec(std::vector<int> &vec)
{
	std::vector<int>::iterator it = vec.begin();

	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void printList(std::list<element> &list)
{
	std::list<element>::iterator it = list.begin();

	while (it != list.end()) {
		std::cout << it->type << it->tag << " ";
		printVec(it->vec);
		it++;
	}
}

// advance the it2 iterator by 2^rec_level iteratively
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

// first face of the algorithm
void pairSortRec(std::vector<int> *vec, unsigned int *rec_level)
{
	if (pow(2, *rec_level) > vec->size() / 2)
		return;

	std::vector<int>::iterator it = vec->begin() + pow(2, *rec_level) - 1;
	std::vector<int>::iterator it2 = vec->begin() + pow(2, *rec_level + 1) - 1;

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

		if (!safeIter(&it2, vec->end(), pow(2, *rec_level + 1)))
			break;
		it += pow(2, *rec_level + 1); 
	}

	//debug
	std::cout << "Recursion level: " << *rec_level + 1 << std::endl;
	printVec(*vec);

	(*rec_level)++;
	pairSortRec(vec, rec_level);
}

// return the Nth element of the Jacobsthal sequence
int jacobsthal(int n)
{
	int a = 1, b = 1;
	for (int i = 0; i < n; ++i) {
		int temp = b;
		b = b + a*2;  // J(i) = J(i-1) + 2 * J(i-2)
		a = temp;
	}
	return b;  // Return J(n)
}

// initialize the main list
void initMain(std::list<element> *main, std::vector<int> *vec, int rec_level)
{
	element elem;
	std::vector<int> sub_vec(1 << rec_level);
	std::vector<int>::iterator it = vec->begin() + (1 << rec_level);
	int tag_assign = 1;

	while (it != vec->end()) {
		std::copy(it, it + (1 << rec_level), sub_vec.begin());
		elem.vec = sub_vec;
		elem.type = 'a';
		elem.tag = tag_assign++;
		main->push_back(elem);
		if ((1 << rec_level) + (1 << (rec_level + 1)) > std::distance(it, vec->end()))
			break;
		it += 1 << (rec_level + 1);
	}
}

// initialize the pend list
element initPend(std::list<element> *pend, std::vector<int> *vec, int rec_level)
{
	element elem;
	std::vector<int> sub_vec(1 << rec_level);
	std::vector<int>::iterator it = vec->begin();
	int tag_assign = 1;

	while (it != vec->end()) {
		std::copy(it, it + (1 << rec_level), sub_vec.begin());
		elem.vec = sub_vec;
		elem.type = 'b';
		elem.tag = tag_assign++;
		pend->push_back(elem);
		if ((1 << (rec_level + 2)) > std::distance(it, vec->end()))
			break;
		it += 1 << (rec_level + 1);
	}
	if ((1 << rec_level) + (1 << (rec_level + 1)) <= std::distance(it, vec->end())) {
		it += 1 << (rec_level + 1);
		std::copy(it, it + (1 << rec_level), sub_vec.begin());
		elem.vec = sub_vec;
		elem.type = 'b';
		elem.tag = tag_assign++;
		return elem;
	}
	elem.tag = 0;
	return elem;
}

// binary search to find the right slot
std::list<element>::iterator binarySearch(std::list<element> &main, int elem, std::list<element>::iterator boundary)
{
	std::list<element>::iterator it = main.begin();
	std::list<element>::iterator mid;

	while (it != boundary) {
		mid = it;
		std::cout << "Boundary: " << boundary->type << boundary->tag << std::endl;
		std::cout << "Distance: " << std::distance(it, boundary) / 2 << std::endl;
		std::advance(mid, std::distance(it, boundary) / 2);
		std::cout << "Mid: " << mid->type << mid->tag << " " << mid->vec.back() << std::endl;
		if (elem < mid->vec.back())
			boundary = mid;
		else {
			it = mid;
			if (std::distance(it, boundary) == 1)
				return ++it;
		}
	}
	return it;
}

// second face of the algorithm
void insertion(std::vector<int> *vec, int rec_level)
{
	int jacob_iteration = 1;
	std::list<element> main;
	std::list<element> pend;
	element odd;

	std::cout << "Recursion level: " << rec_level << std::endl;
	initMain(&main, vec, rec_level);
	printList(main);
	odd = initPend(&pend, vec, rec_level);
	printList(pend);
	std::cout << "Odd: " << odd.type << odd.tag << " ";
	printVec(odd.vec);

	std::list<element>::iterator tmp_it;

	main.insert(main.begin(), pend.front());
	pend.pop_front();

	while (!pend.empty()) {
		std::cout << "Iteration: " << jacob_iteration << std::endl;
		std::list<element>::iterator insert = pend.begin();
		size_t insertions = jacobsthal(jacob_iteration) - jacobsthal(jacob_iteration - 1);
		if (insertions > pend.size())
			insertions = pend.size();
		std::advance(insert, insertions - 1);
		for (; insertions > 0; insertions--) {
			std::list<element>::iterator boundary = main.begin();
			while (boundary->tag != insert->tag)
				boundary++;
			std::cout << "Insert: " << insert->type << insert->tag << " ";
			std::cout << "Boundary: " << boundary->type << boundary->tag << std::endl;
	
			std::list<element>::iterator slot = binarySearch(main, insert->vec.back(), boundary);
			main.insert(slot, *insert);
			tmp_it = insert;
			tmp_it--;
			pend.erase(insert);
			insert = tmp_it;
			std::cout << "Main:\n";
			printList(main);
			std::cout << "Pend:\n";
			printList(pend);
			//exit(1);
		}
		jacob_iteration++;
	}


	if (odd.tag != 0) {
		std::list<element>::iterator slot = binarySearch(main, odd.vec.back(), main.end());
		main.insert(slot, odd);
		std::cout << "Main (AFTER ODD):\n";
		printList(main);
	}


	std::vector<int> new_vec;
	std::list<element>::iterator it = main.begin();
	while (it != main.end()) {
		std::copy(it->vec.begin(), it->vec.end(), std::back_inserter(new_vec));
		it++;
	}
	std::copy(vec->end() - (vec->size() % (1 << rec_level)), vec->end(), std::back_inserter(new_vec));
	*vec = new_vec;

	if (rec_level == 0)
		return;
	insertion(vec, rec_level - 1);
}

// Algorithm with vector
double PmergeMeVec(std::vector<int> *vec) {
	unsigned int rec_level = 0;
	time_t start = time(NULL);

	pairSortRec(vec, &rec_level);
	insertion(vec, rec_level - 1);

	time_t end = time(NULL);
	return difftime(end, start);
}
