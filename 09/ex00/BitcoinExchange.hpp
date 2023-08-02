#pragma once

#include "Date.hpp"

#include <istream>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange(std::istream &data);
	BitcoinExchange(const BitcoinExchange &src);
	virtual ~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &src);

	void processInputFile(std::istream &input) const;

private:
	BitcoinExchange();

	void _processDataFile(std::istream &input);

	static std::pair<Date, double> _parseLine(std::string &str, const std::string &separator);

	std::map<Date, double> _data;
};
