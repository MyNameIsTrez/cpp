#include "Fixed.hpp"

#include <iostream>

void	check_leaks() {
	system("leaks -q fixed");
}

int	main() {
	atexit(check_leaks);

	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return EXIT_SUCCESS;
}
