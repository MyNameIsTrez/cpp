#include "Harl.hpp"

#include <iostream>

void	check_leaks() {
	system("leaks -q harl");
}

int	main() {
	atexit(check_leaks);

	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	harl.complain("UNKNOWN");
	harl.complain("");

	return EXIT_SUCCESS;
}
