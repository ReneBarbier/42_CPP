#include "easyfind.hpp"

int main(void)
{
	int arr[] = {1, 3, 2, 7, 8, 5, 4, 0, 6, 9}; 
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try {
		std::vector<int>::iterator it = easyfind(vec, 1);
		int position = std::distance(vec.begin(), it);
		std::cout << "Element found at position: " << position << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: Element not found"<< std::endl;
	}	
}
