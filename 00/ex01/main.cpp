#include "PhoneBook.hpp"

#include "utils.hpp"

#include <iostream>

int	main() {
	std::string	command;
	PhoneBook	phonebook;

	while (utils::prompt("Enter ADD/SEARCH/EXIT:", command)) {
		if (command == "ADD") {
			if (!phonebook.add()) {
				std::cout << "Failed to add contact." << std::endl;
			}
		} else if (command == "SEARCH") {
			phonebook.search();
		} else if (command == "EXIT") {
			break ;
		} else {
			std::cout << "Unknown command." << std::endl;
		}
	}

	return (EXIT_SUCCESS);
}
