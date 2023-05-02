#include "Harl.hpp"

#include <iostream>

int	Harl::get_complaint_index(const std::string level) {
	std::string	names[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	for (size_t i = 0; i < names->length(); i++) {
		if (names[i] == level) {
			return i;
		}
	}

	return -1;
}

void	Harl::complain(std::string level) {
	switch (get_complaint_index(level)) {
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cerr << "Error: Invalid level string." << std::endl;
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
