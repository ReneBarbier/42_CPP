#include "Array.hpp"

int main()
{
	{
		Array<int> numbers(10);

		for (int i = 0; i < 10; i++)
			numbers[i] = i;

		numbers.printArray("numbers");
		
		Array<int> oddNumbers(numbers);

		for (int i = 0; i < 10; i++)
			if (oddNumbers[i] % 2 == 0)
				oddNumbers[i]++;

		oddNumbers.printArray("oddNumbers");
		numbers.printArray("numbers");
	}
	{
		Array<char> sayHi(12);

	}
}
