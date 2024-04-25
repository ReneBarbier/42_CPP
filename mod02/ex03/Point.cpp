#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point &Point::operator=(const Point &point)
{
}

Point::~Point()
{
}

float Point::getX(void) const
{
	return this->_x.toFloat();
}

float Point::getY(void) const
{
	return this->_y.toFloat();
}
