#pragma once

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(Point const &src);
	Point(float const x, float const y);
	virtual	~Point();
	Point&	operator=(Point const &src);

	float	get_x() const;
	float	get_y() const;

private:
	Fixed const	x;
	Fixed const	y;
};
