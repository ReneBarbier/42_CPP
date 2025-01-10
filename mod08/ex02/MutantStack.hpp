#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<int> {
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {
			*this = src;
		};
		MutantStack &operator=(MutantStack const &src) {
			std::stack<T>::operator=(src);
			return *this;
		}
		~MutantStack() {};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}

};

#endif
