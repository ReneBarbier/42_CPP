#include "Base.hpp"

Base *generate()
{
	int random = rand() % 3;
	if (random == 0)
		return (std::cout << "its A" << std::endl, new A);
	else if (random == 1)
		return (std::cout << "its B" << std::endl, new B);
	else
		return (std::cout << "its C" << std::endl, new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
}

int main()
{
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}
