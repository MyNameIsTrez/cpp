#include "Fixed.hpp"

#include <iostream>

void	check_leaks() {
	system("leaks -q operators");
}

int	main() {
	atexit(check_leaks);

	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;


	a = b;
	assert(a == 10.0938f);

	assert(a.getRawBits() == 2584);
	a.setRawBits(257);
	assert(a == 1.00391f);

	assert(a.toInt() == 1);

	a += 2;
	assert(a == 3.00390625f);
	a -= 2;
	assert(a == 1.00390625f);
	a *= 2;
	assert(a == 2.0078125f);
	a /= 2;
	assert(a == 1.00391f);

	assert(++a == 1.0078125f);
	assert(a++ == 1.0078125f);
	assert(a == 1.01171875f);

	assert(--a == 1.0078125f);
	assert(a-- == 1.0078125f);
	assert(a == 1.00390625f);

	assert(Fixed::min(Fixed(1), Fixed(2)) == 1);
	assert(Fixed::max(Fixed(1), Fixed(2)) == 2);

	assert((Fixed(1) == Fixed(2)) == false);
	assert((Fixed(1) == Fixed(1)) == true);

	assert((Fixed(1) != Fixed(2)) == true);
	assert((Fixed(1) != Fixed(1)) == false);

	assert((Fixed(1) < Fixed(2)) == true);
	assert((Fixed(1) < Fixed(1)) == false);
	assert((Fixed(2) < Fixed(1)) == false);

	assert((Fixed(1) > Fixed(2)) == false);
	assert((Fixed(1) > Fixed(1)) == false);
	assert((Fixed(2) > Fixed(1)) == true);

	Fixed const	foo(1);
	Fixed const	bar(2);

	assert((foo + bar) == 3.0f);

	// "If you ever do a division by 0, it is acceptable that the program crashes"
	// And so I let it crash :)
	// assert((Fixed(1) / Fixed(0)) == 0);

	return EXIT_SUCCESS;
}
