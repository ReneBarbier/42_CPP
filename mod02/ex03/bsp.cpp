#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point d(b.getX() - a.getX(), b.getY() - a.getY());
	Point e(c.getX() - a.getX(), c.getY() - a.getY());
	
	Fixed w1 = (e.getX() * (a.getY() + point.getY()) + e.getY() * (point.getX() - a.getX())) / (d.getX() * e.getY() - d.getY() * e.getX());
	Fixed w2 = (point.getY() - a.getY() - w1 * d.getY()) / e.getY();
	
	std::cout << (point.getY() - a.getY() - w1 * d.getY()) << std::endl;
	std::cout << "A.x " << a.getX() << " " << "A.y " << a.getY() << std::endl;
	std::cout << "B.x " << b.getX() << " " << "B.y " << b.getY() << std::endl;
	std::cout << "C.x " << c.getX() << " " << "C.y " << c.getY() << std::endl;

	std::cout << "P.x " << point.getX() << " " << "P.y " << point.getY() << std::endl;

	std::cout << "E.x " << e.getX() << " " << "E.y " << e.getY() << std::endl;
	std::cout << "D.x " << d.getX() << " " << "D.y " << d.getY() << std::endl;
	std::cout << "W1 " << w1.toFloat() << " " << "W2 " << w2.toFloat() << std::endl;

	if (w1 >= 0 && w2 >= 0 && w1 + w2 <= 1)
		return true;
	return false;
}