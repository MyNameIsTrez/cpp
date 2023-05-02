#include <iostream>
#include <fstream>

std::string	replace(const std::string &old_line, const std::string &s1, const std::string &s2) {
	std::string	new_line;

	size_t old_line_index = 0;
	size_t	new_old_line_index;
	while (old_line_index < old_line.length()) {
		new_old_line_index = old_line.find(s1, old_line_index);

		new_line += old_line.substr(old_line_index, new_old_line_index - old_line_index);

		if (new_old_line_index == std::string::npos) {
			break;
		}

		new_line += s2;

		old_line_index = new_old_line_index + s1.length();
	}

	return new_line;
}

void	check_leaks() {
	system("leaks -q losers");
}

/* TESTS:
Explanation: aab -> ab
./losers tests/ab.txt aa a

Explanation: empty -> empty
./losers tests/empty.txt a a

Explanation: hello world -> hella warld
./losers tests/hella_warld.txt o a

Explanation: aaaab -> xxb
./losers tests/xxb.txt aa x
*/
int	main(int argc, char *argv[]) {
	atexit(check_leaks);

	if (argc != 4) {
		std::cerr << "Error: Didn't receive exactly 3 arguments." << std::endl;
		return EXIT_FAILURE;
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream	input_file(filename);
	if (!input_file.is_open()) {
		std::cerr << "Error: Unable to open input file." << std::endl;
		return EXIT_FAILURE;
	}

	std::ofstream	output_file(filename + ".replace");
	if (!output_file.is_open()) {
		std::cerr << "Error: Unable to open output file." << std::endl;
		return EXIT_FAILURE;
	}

	std::string		line;
	while (std::getline(input_file, line)) {
		output_file << replace(line, s1, s2) << std::endl;
	}

	return EXIT_SUCCESS;
}
