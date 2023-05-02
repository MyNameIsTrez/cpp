#include "PhoneBook.hpp"

#include "utils.hpp"

#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
		: next_contact_index(0)
		, used_contact_count(0) {
}

bool	PhoneBook::add() {
	Contact	c;

	if (!c.prompt_fields()) {
		return false;
	}

	std::cout << "Succesfully added contact." << std::endl;

	contacts[next_contact_index] = c;

	next_contact_index = (next_contact_index + 1) % MAX_CONTACT_COUNT;

	used_contact_count = utils::min(used_contact_count + 1, MAX_CONTACT_COUNT);

	return true;
}

void	PhoneBook::search() const {
	if (used_contact_count == 0) {
		std::cout << "There are no contacts." << std::endl;
		return ;
	}

	print();

	std::cout << "Index of contact to show more info of:" << std::endl;

	std::string contact_str;
	std::getline(std::cin, contact_str);

	size_t	contact_index;
	if (utils::str_to_size(contact_index, contact_str.c_str()) != utils::SUCCESS || contact_index < 0 || contact_index >= used_contact_count) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	contacts[contact_index].display();
}

void	PhoneBook::print() const {
	std::cout
		<< std::setw(10) << "Index" << " | "
		<< std::setw(10) << "First name" << " | "
		<< std::setw(10) << "Last name" << " | "
		<< std::setw(10) << "Nickname" << std::endl;

	for (size_t contact_index = 0; contact_index < used_contact_count; contact_index++) {
		contacts[contact_index].display_table_row(contact_index);
	}
}
