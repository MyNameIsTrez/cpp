#pragma once

#include <sstream>

class Date
{
public:
	Date(const std::string &date_string);
	Date(const Date &src);
	virtual ~Date();
	Date &operator=(const Date &src);

	bool	operator==(const Date &rhs) const;
	bool	operator<(const Date &rhs) const;

	std::string toString() const;

private:
	Date();

	int _year;
	unsigned int _month;
	unsigned int _day;
};

std::ostream &operator<<(std::ostream &ostream, const Date &date);
