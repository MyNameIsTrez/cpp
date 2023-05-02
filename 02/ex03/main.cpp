#include "Point.hpp"

#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	check_leaks() {
	system("leaks -q bsp");
}

int	main() {
	atexit(check_leaks);


	/* Line, edge
	AB-D-C
	*/
	// HARD
	assert(bsp(Point(0, 0), Point(0, 0), Point(1, 0), Point(0.5, 0)) == false);

	/* All at (0, 0) */
	// HARD
	assert(bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)) == false);


	/* Clockwise, inside
	B
	|\
	| \
	|D \
	A---C
	*/
	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.1, 0.1)) == true);

	/* Clockwise, right of BC
	B   D
	|\
	| \
	|  \
	A---C
	*/
	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1)) == false);

	/* Clockwise, left of AB
	  B
	  |\
	D | \
	  |  \
	  A---C
	*/
	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(-0.1, 0.5)) == false);

	/* Clockwise, below AC
	B
	|\
	| \
	|  \
	A---C
	  D
	*/
	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, -0.1)) == false);

	/* Clockwise, edge AC
	B
	|\
	| \
	|  \
	A-D-C
	*/
	// HARD
	assert(bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.5, 0)) == false);


	/* Counterclockwise, inside
	C
	|\
	| \
	|D \
	A---B
	*/
	assert(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.1, 0.1)) == true);

	/* Counterclockwise, right of BC
	C   D
	|\
	| \
	|  \
	A---B
	*/
	assert(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1)) == false);

	/* Counterclockwise, left of AC
	  C
	  |\
	D | \
	  |  \
	  A---B
	*/
	assert(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(-0.1, 0.5)) == false);

	/* Counterclockwise, below AB
	C
	|\
	| \
	|  \
	A---B
	  D
	*/
	assert(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.5, -0.1)) == false);

	/* Counterclockwise, edge AB
	C
	|\
	| \
	|  \
	A-D-B
	*/
	// HARD
	assert(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.5, 0)) == false);


	// Point p(2.3, 3.5);
	// Point p2(4.3, 3.5);
	// p = p2;


	return EXIT_SUCCESS;
}
