#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const Point &point);
		//Point &operator=(const Point &point);
		~Point();
		Point(const float x, const float y);
		float getX(void) const;
		float getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif