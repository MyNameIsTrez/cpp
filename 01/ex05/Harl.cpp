#include "Harl.hpp"

#include <iostream>

void	Harl::complain(std::string level) {
	comment_metadata	fns[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
		{"", nullptr},
	};

	size_t	i = 0;
	while (fns[i].key != "") {
		if (fns[i].key == level) {
			(this->*fns[i].fn)();
		}
		i++;
	}
}

void	Harl::debug() {
	std::cout << "DEBUG" << std::endl;
}

void	Harl::info() {
	std::cout << "INFO" << std::endl;
}

void	Harl::warning() {
	std::cout << "WARNING" << std::endl;
}

void	Harl::error() {
	std::cout << "ERROR" << std::endl;
}
