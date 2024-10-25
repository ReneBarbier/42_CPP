#include "Base.hpp"

Base *generate()
{
	int random = rand() % 3;
	if (random == 0)
		return (std::cout << "Obj of class A generated." << std::endl, new A);
	else if (random == 1)
		return (std::cout << "Obj of class B generated." << std::endl, new B);
	else
		return (std::cout << "Obj of class C generated." << std::endl, new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "identify(Base *p) -> \'A\'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identify(Base *p) -> \'B\'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identify(Base *p) -> \'C\'" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "identify(Base &p) -> \'A\'" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "identify(Base &p) -> \'B\'" << std::endl;
	}
	catch (std::bad_cast &e)
	{
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "identify(Base &p) -> \'C\'" << std::endl;
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
