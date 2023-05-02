#include "Contact.hpp"

#include "utils.hpp"

#include <iomanip>
#include <iostream>

bool	Contact::prompt_fields() {
	return (Contact::prompt_field("First name:", first_name)
		&& Contact::prompt_field("Last name:", last_name)
		&& Contact::prompt_field("Nickname:", nickname)
		&& Contact::prompt_field("Phone number:", phone_number)
		&& Contact::prompt_field("Darkest secret:", darkest_secret));
}

void	Contact::display() const {
	std::cout
		<< "First name: " << first_name << std::endl
		<< "Last name: " << last_name << std::endl
		<< "Nickname: " << nickname << std::endl
		<< "Phone number: " << phone_number << std::endl
		<< "Darkest secret: " << darkest_secret << std::endl;
}

void	Contact::display_table_row(size_t contact_index) const {
	std::cout
		<< std::setw(10) << contact_index << " | "
		<< std::setw(10) << utils::truncate(first_name) << " | "
		<< std::setw(10) << utils::truncate(last_name) << " | "
		<< std::setw(10) << utils::truncate(nickname)
		<< std::endl;
}

bool	Contact::prompt_field(std::string const &p, std::string &output) {
	if (!utils::prompt(p, output))
		return (false);
	if (output.empty()) {
		std::cout << "No empty fields allowed." << std::endl;
		return (false);
	}
	return (true);
}
