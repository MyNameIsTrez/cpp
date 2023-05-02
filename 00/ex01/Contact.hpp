#pragma once

#include <string>

class Contact {
public:
	bool	prompt_fields();
	void	display() const;
	void	display_table_row(size_t contact_index) const;

private:
	static bool	prompt_field(std::string const &p, std::string &output);

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};
