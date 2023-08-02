#include "Date.hpp"

#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>

Date::Date(const std::string &date_string)
{
	std::stringstream date(date_string);

	char c;

	date >> _year;
	if (date.fail()) { throw std::domain_error("Year was wrong."); }

	date >> c;
	if (c != '-') { throw std::domain_error("Expected '-'"); }

	date >> _month;
	if (date.fail()) { throw std::domain_error("Month was wrong."); }
	if (_month < 1 || _month > 12) { throw std::domain_error("Month has to be between 1 and 12."); }

	date >> c;
	if (c != '-') { throw std::domain_error("Expected '-'"); }

	date >> _day;
	if (date.fail()) { throw std::domain_error("Day was wrong."); }
	if (_day < 1) { throw std::domain_error("Day has to be at least 1."); }

	if (_month == 2) { // If February
		if (_year % 1000 == 0) {
			if (_day > 29) { throw std::domain_error("Day was wrong."); }
		} else if (_year % 100 == 0) {
			if (_day > 28) { throw std::domain_error("Day was wrong."); }
		} else if (_year % 4 == 0) {
			if (_day > 29) { throw std::domain_error("Day was wrong."); }
		} else {
			if (_day > 28) { throw std::domain_error("Day was wrong."); }
		}
	} else if (_month <= 7) { // If July or earlier
		if (_month % 2 == 0) {
			if (_day > 30) { throw std::domain_error("Day was wrong."); }
		} else {
			if (_day > 31) { throw std::domain_error("Day was wrong."); }
		}
	} else {
		if (_month % 2 == 0) {
			if (_day > 31) { throw std::domain_error("Day was wrong."); }
		} else {
			if (_day > 30) { throw std::domain_error("Day was wrong."); }
		}
	}

	if (!date.eof()) { throw std::domain_error("There was something after the date."); }
}

Date::Date(const Date &src)
{
	operator=(src);
}

Date::~Date()
{
}

Date &Date::operator=(const Date &src)
{
	if (this == &src)
	{
		return (*this);
	}

	_year = src._year;
	_month = src._month;
	_day = src._day;

	return (*this);
}

bool	Date::operator==(const Date &rhs) const
{
	return _year == rhs._year && _month == rhs._month && _day == rhs._day;
}

bool	Date::operator<(const Date &rhs) const
{
	if (_year != rhs._year) {
		return _year < rhs._year;
	}
	if (_month != rhs._month) {
		return _month < rhs._month;
	}
	return _day < rhs._day;
}

std::string Date::toString() const
{
	std::stringstream ss;

	ss
		<< _year
		<< "-"
		<< std::setfill('0') << std::setw(2) << _month
		<< "-"
		<< std::setw(2) << _day;
	return ss.str();
}

std::ostream &operator<<(std::ostream &ostream, const Date &date)
{
	return ostream << date.toString();
}
