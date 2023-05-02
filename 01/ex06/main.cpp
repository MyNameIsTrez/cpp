#include "Harl.hpp"

#include <iostream>

void	check_leaks() {
	system("leaks -q harlFilter");
}

/* TESTS:
Explanation: The 'I' character matches "INFO", but it isn't equal to "INFO".
./filter "I"
*/
int	main(int argc, char *argv[]) {
	atexit(check_leaks);

	if (argc != 2) {
		std::cerr << "Error: Didn't receive exactly 1 argument." << std::endl;
		return EXIT_FAILURE;
	}

	Harl	harl;
	harl.complain(argv[1]);

	return EXIT_SUCCESS;
}
