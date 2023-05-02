#pragma once

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	bool	add();
	void	search() const;

private:
	void	print() const;

	static const size_t	MAX_CONTACT_COUNT = 8;
	Contact	contacts[MAX_CONTACT_COUNT];

	size_t	next_contact_index;
	size_t	used_contact_count;
};
