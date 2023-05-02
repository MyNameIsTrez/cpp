#include <iostream>

void	check_leaks() {
	system("leaks -q hi");
}

int	main() {
	atexit(check_leaks);

	std::string	string = "HI THIS IS BRAIN";

	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "&string: " << &string << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	// WTF do they want? A reference is an alias, so it doesn't hold a memory address!
	std::cout << "&stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "string: " << string << std::endl;
	std::cout << "*stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return EXIT_SUCCESS;
}
