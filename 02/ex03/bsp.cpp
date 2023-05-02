#include "Point.hpp"

// Source: https://stackoverflow.com/a/2049593/13279557
float	sign(Point const &p1, Point const &p2, Point const &p3)
{
    return	(p1.get_x() - p3.get_x())
		*	(p2.get_y() - p3.get_y())
		-	(p2.get_x() - p3.get_x())
		*	(p1.get_y() - p3.get_y());
}

/*
Given this scenario:

C   D
|@
| @
|  @
A---B

D is on the opposite side of A, given the line BC.
When D is on an opposite side, d1, d2, or d3 will be positive.
Both has_neg and has_pos will be true, so the function will return false.


Given this scenario:

C
|@
| @
|D @
A---B

D is on the same side as A, given the line BC.
When D is on the same side, d1, d2, or d3 will be negative.
has_neg will be true and has_pos will be false, so the function will return true.
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
    float	d1;
	float	d2;
	float	d3;
    bool	has_neg;
	bool	has_pos;

    d1 = sign(point, a, b);
	if (d1 == 0) {
		return false;
	}
    d2 = sign(point, b, c);
	if (d2 == 0) {
		return false;
	}
    d3 = sign(point, c, a);
	if (d3 == 0) {
		return false;
	}

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
