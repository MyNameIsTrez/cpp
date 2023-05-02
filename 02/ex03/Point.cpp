#include "Point.hpp"

Point::Point()
		: x(0)
		, y(0) {
}

Point::Point(Point const &src) {
	*this = src;
}

Point::Point(float const x, float const y)
		: x(x)
		, y(y) {
}

Point::~Point() {
}

Point&	Point::operator=(Point const &src) {
	if (this == &src)
		return (*this);
	// WTF do they want from me, if x and y are const??
	// x = src.x;
	// y = src.y;
	throw std::logic_error("Can't use copy assignment operator overload.");
}

float	Point::get_x() const {
	return x.toFloat();
}

float	Point::get_y() const {
	return y.toFloat();
}
