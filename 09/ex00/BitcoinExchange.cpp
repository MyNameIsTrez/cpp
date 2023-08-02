#include "BitcoinExchange.hpp"
#include "Date.hpp"

#include <iostream>
#include <utility>

BitcoinExchange::BitcoinExchange(std::istream &data)
{
	_processDataFile(data);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
	: _data(src._data)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this == &src)
	{
		return (*this);
	}

	_data = src._data;

	return (*this);
}

void BitcoinExchange::processInputFile(std::istream &data) const
{
	std::string str;
	std::getline(data, str);
	if (str != "date | value") {
		throw std::runtime_error("Wrong header, expected 'date | value'.");
	}

	while (!data.eof()) {
		std::string str;
		std::getline(data, str);
		if (data.fail()) {
			if (str.empty() && data.eof()) {
				break;
			}
			throw std::runtime_error("Stream failure.");
		}

		try {
			std::pair<Date, double> input_pair = _parseLine(str, " | ");
			if (input_pair.second < 0) {
				throw std::runtime_error("Value was smaller than 0.");
			}
			if (input_pair.second > 1000) {
				throw std::runtime_error("Value was bigger than 1000.");
			}

			// upper_bound() returns >
			std::map<Date, double>::const_iterator upper_bound = _data.upper_bound(input_pair.first);

			if (upper_bound == _data.begin()) {
				throw std::runtime_error("Date was before the earliest known date.");
			} else {
				// Essentially inverts upper_bound to be <=
				upper_bound--;

				double result = input_pair.second * upper_bound->second;
				std::cout << input_pair.first << " => " << input_pair.second << " = " << result << std::endl;
			}
		} catch (std::runtime_error &err) {
			std::cerr <<  "Error: " << err.what() << std::endl;
			// Error: bad input => 2001-42-42
		}
	}
}

void BitcoinExchange::_processDataFile(std::istream &data)
{
	std::string str;
	std::getline(data, str);
	if (str != "date,exchange_rate") {
		throw std::runtime_error("Wrong header, expected 'date,exchange_rate'.");
	}

	while (!data.eof()) {
		std::string str;
		std::getline(data, str);
		if (data.fail()) {
			if (str.empty() && data.eof()) {
				break;
			}
			throw std::runtime_error("Stream failure.");
		}

		std::pair<Date, double> pair = _parseLine(str, ",");
		_data.insert(pair);
	}
}

std::pair<Date, double> BitcoinExchange::_parseLine(std::string &str, const std::string &separator)
{
	size_t end_index = str.find(separator);
	if (end_index == std::string::npos) {
		throw std::runtime_error("Line didn't contain the separator.");
	}

	std::string date_str = str.substr(0, end_index);
	Date date(date_str);

	str.erase(0, end_index + separator.length());

	std::stringstream ss(str);
	double exchange_rate;
	ss >> exchange_rate;
	bool is_double = !ss.fail() && ss.eof();

	if (!is_double) {
		throw std::runtime_error("Expected double.");
	}

	// std::cout << "'" << str << "'" << std::endl;

	return std::pair<Date, double>(date, exchange_rate);
}
