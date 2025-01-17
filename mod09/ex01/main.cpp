#include "RPN.hpp"

int main(int argc, char** argv) {
	bool visualizer = false;
	if (argc == 3 && argv[2][0] == 'v')
		visualizer = true;
	else if (argc != 2)
		return (std::cout << "Err: wrong number of arguments.\n", 1);
	if (runRPN(argv[1], visualizer))
		return (std::cout << "Err: invalid input.\n", 1);
	return 0;
}
