#include "Span.hpp"

int main() {
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		sp.addManyRandom(4);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.printStorage();
		
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
