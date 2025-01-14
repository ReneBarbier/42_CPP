#include "Array.hpp"

int main()
{
	{
		Array<int> numbers(10);

		for (int i = 0; i < 10; i++)
			numbers[i] = i;

		numbers.printArray("numbers");
		
		Array<int> oddNumbers(numbers);

		oddNumbers.printArray("oddNumbers");

		for (int i = 0; i < 10; i++)
			if (oddNumbers[i] % 2 == 0)
				oddNumbers[i]++;

		oddNumbers.printArray("oddNumbers");
		numbers.printArray("numbers");

		numbers = oddNumbers;
		numbers.printArray("numbers");
		
		try {
			numbers[10] = 5;
		}
		catch (Array<int>::InvalidIndexException &e) {	
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
}
