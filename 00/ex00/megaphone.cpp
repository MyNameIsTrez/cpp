// make && ./megaphone "shhhhh... I think the students are asleep..." && ./megaphone Damnit " ! " "Sorry students, I thought this thing was off." && ./megaphone

#include <iostream>

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		argv++;

		while (*argv) {
			while (**argv) {
				std::cout << (char)toupper(**argv);
				(*argv)++;
			}
			argv++;
		}
	}

	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
