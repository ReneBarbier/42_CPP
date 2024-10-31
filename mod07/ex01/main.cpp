#include "iter.hpp"

void set_three(int &n)
{
	n = 3;	
}

void print(std::string &str)
{
	std::cout << str << std::endl;
}

void to_upper(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
}

void to_lower(char &c)
{
	c = std::tolower(c);
}

int main()
{
	{
		int nums[3];

		iter(nums, 3, &set_three);
		for (int i = 0; i < 3; i++)
			std::cout << nums[i] << std::endl;
	}
	{
		char str[] = "HELLO";
		iter(str, 5, &to_lower);
		std::cout << str << std::endl;
	}
	{
		std::string strs[3] = {"Hello", "World", "!"};

		iter(strs, 3, &to_upper);
		for (int i = 0; i < 3; i++)
			std::cout << strs[i] << " ";
		std::cout << std::endl;
	}
}
