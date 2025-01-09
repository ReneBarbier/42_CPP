#include "Span.hpp"
#include <limits.h>

Span::Span(int N) : max_elements(N) {
}

Span::Span(const Span &src) {
	this->max_elements = src.get_maxElem();
}

Span &Span::operator=(const Span &src) {
	this->max_elements = src.get_maxElem();
	return *this;
}

Span::~Span() {
}

void Span::addNumber(int newNumber) {
	if (this->storage.size() >= this->max_elements)
		throw Span::StorageFullException();
	this->storage.push_back(newNumber);
}

int Span::shortestSpan() {
	if (this->storage.size() < 2)
		throw Span::NotEnoughElementsException();

	std::list<int> sorted = this->storage;
	std::list<int>::iterator it;
	int min = INT_MAX;
	sorted.sort();

	for (it = sorted.begin(); it != sorted.end(); it++) {
		std::list<int>::iterator next = it;
		next++;
		if (next != sorted.end() && *next - *it < min)
			min = *next - *it;
	}
	return min;
}

int Span::longestSpan() {
	if (this->storage.size() < 2)
		throw Span::NotEnoughElementsException();
	std::list<int> sorted = this->storage;
	sorted.sort();
	return sorted.back() - sorted.front();
}

unsigned int Span::get_maxElem() const {
	return this->max_elements;
}

const char* Span::StorageFullException::what() const throw() {
	return "Storage is full";
}

const char* Span::NotEnoughElementsException::what() const throw() {
	return "Not enough elements to calculate span";
}
