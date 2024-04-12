#include "Point.hpp"

int main(void) 
{
	Point a(1, 1);
	Point b(3, 3);
	Point c(3, 1);

	Point p1(2, 1.5); //inside 
	Point p2(3, 3); //on a vertex
	Point p3(1, 2); //on the edge

	if (bsp(a, b, c, p1))
		std::cout << "p1 is inside the triangle" << std::endl;
	else
		std::cout << "p1 is outside the triangle" << std::endl;

	if (bsp(a, b, c, p2))
		std::cout << "p2 is inside the triangle" << std::endl;
	else
		std::cout << "p2 is outside the triangle" << std::endl;

	if (bsp(a, b, c, p3))
		std::cout << "p3 is inside the triangle" << std::endl;
	else
		std::cout << "p3 is outside the triangle" << std::endl;
	return 0;
}