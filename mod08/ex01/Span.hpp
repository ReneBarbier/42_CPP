#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>

class Span
{
	private:
		unsigned int max_elements;
		std::list<int> storage;
	public:
		Span(int N);
		Span(Span const &src);
		Span &operator=(Span const &src);
		~Span();

		void addNumber(int newNumber);
		int shortestSpan();
		int longestSpan();

		unsigned int get_maxElem() const;
		
		class StorageFullException : public std::exception {
			public:
				const char* what() const throw();
		};
		class NotEnoughElementsException: public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
