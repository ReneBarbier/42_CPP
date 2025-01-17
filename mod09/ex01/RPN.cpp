#include "RPN.hpp"
#include <list>

void printStack(std::stack<int> stack)
{
	std::stack<int> tmp = stack;
	std::list<int> list;
	while (!tmp.empty())
	{
		list.push_front(tmp.top());
		tmp.pop();
	}
	std::list<int>::iterator it = list.begin();
	std::cout << "Stack: ";
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int isOperator(char c)
{
	if (c == '-' || c == '+' || c == '*' || c == '/')
		return (1);
	return (0);
}

int operate(int a, int b, char _operator)
{
	if (_operator == '-')
		return b - a;
	if (_operator == '+')
		return b + a;
	if (_operator == '/') 
		return b / a;
	else
		return b * a;
}

int runRPN(char *input, bool visualizer) {
	std::stack<int> stack;	
	int a;
	int b;

	if (!input || !*input)
		return (std::cout << "(1): ", 1);
	while (*input)
	{
		if (*input == ' ') {
			input++;
			continue ;
		}
		if (!std::isdigit(*input) && !isOperator(*input))
			return (std::cout << "(2): ", 1);
		if (std::isdigit(*input)) {
			stack.push(*input - '0');
			if (visualizer)
				printStack(stack);
		}
		if (isOperator(*input)) {
			if (stack.empty())
				return (std::cout << "(3): ", 1);
			if (visualizer)
				std::cout << "Operator: " << *input << std::endl;
			a = stack.top();
			stack.pop();
			if (stack.empty())
				return (std::cout << "(4): ", 1);
			b = stack.top();
			stack.pop();
			if (*input == '/' && a == 0)
				return (std::cout << "(5): ", 1);
			stack.push(operate(a, b, *input));
			if (visualizer)
				printStack(stack); 
		}
		input++;
	}
	a = stack.top();
	stack.pop();
	if (!stack.empty())
		return (std::cout << "(6): ", 1);
	std::cout << a << std::endl;
	return (0);
}
