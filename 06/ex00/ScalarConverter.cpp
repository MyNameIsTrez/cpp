#include "ScalarConverter.hpp"

#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <sstream>

void ScalarConverter::convert(const std::string &string)
{
	std::istringstream ss(string);

	int i;
	ss >> i;
	bool is_int = !ss.fail() && ss.eof();
	std::istringstream(string).swap(ss);

	// This doesn't work, since it fails due to the trailing "f" in "12.3f"
	// float f;
	// ss >> f;
	// char f_c;
	// ss >> f_c;
	// bool is_float = !ss.fail() && ss.eof() && f_c == 'f';
	// std::istringstream(string).swap(ss);

	float f;
	char *f_endptr;
	errno = 0;
	f = strtof(string.c_str(), &f_endptr);
	bool is_float = *f_endptr != string[0] && f_endptr[0] == 'f' && f_endptr[1] == '\0' && errno == 0;

	double d;
	ss >> d;
	bool is_double = !ss.fail() && ss.eof();
	std::istringstream(string).swap(ss);

	char c;
	ss >> c;
	bool is_printable_char = !ss.fail() && ss.peek() == EOF && std::isprint(c);
	std::istringstream(string).swap(ss);

	if (is_int)
	{
		handle_int(i);
	}
	else if (is_float)
	{
		handle_float(f);
	}
	else if (is_double)
	{
		handle_double(d);
	}
	else if (is_printable_char)
	{
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
	{
		std::cout << "Error: The input wasn't a char/int/float/double" << std::endl;
	}
}

void ScalarConverter::handle_int(int i)
{
	std::cout << "char: ";
	if (i >= 0 && i <= 255 && std::isprint(i))
	{
		std::cout << static_cast<char>(i) << std::endl;
	}
	else if (i >= 0 && i <= 255 && !std::isprint(i))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "int: " << i << std::endl;

	{
		// TODO: Don't recreate ss all the time
		std::stringstream ss;
		float f = static_cast<float>(i);
		ss << f;
		if (isfinite(f) && is_whole(f) && ss.str().find("e") == std::string::npos)
		{
			ss << ".0";
		}
		std::cout << "float: " << ss.str() << "f" << std::endl;
	}
	{
		std::stringstream ss;
		double d = static_cast<double>(i);
		ss << d;
		if (isfinite(d) && is_whole(d) && ss.str().find("e") == std::string::npos)
		{
			ss << ".0";
		}
		std::cout << "double: " << ss.str() << std::endl;
	}
}

void ScalarConverter::handle_float(float f)
{
	std::cout << "char: ";
	if (f >= CHAR_MIN && f <= CHAR_MAX && is_whole(f) && std::isprint(f))
	{
		std::cout << static_cast<char>(f) << std::endl;
	}
	else if (f >= CHAR_MIN && f <= CHAR_MAX && is_whole(f) && !std::isprint(f))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "int: ";
	if (isfinite(f) && f >= INT_MIN && f <= INT_MAX && is_whole(f))
	{
		std::cout << static_cast<int>(f) << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}

	{
		std::stringstream ss;
		ss << f;
		if (isfinite(f) && is_whole(f) && ss.str().find("e") == std::string::npos)
		{
			ss << ".0";
		}
		std::cout << "float: " << ss.str() << "f" << std::endl;
	}
	{
		std::stringstream ss;
		double d = static_cast<double>(f);
		ss << d;
		if (isfinite(d) && is_whole(d) && ss.str().find("e") == std::string::npos)
		{
			ss << ".0";
		}
		std::cout << "double: " << ss.str() << std::endl;
	}
}

void ScalarConverter::handle_double(double d)
{
	std::cout << "char: ";
	if (d >= CHAR_MIN && d <= CHAR_MAX && is_whole(d) && std::isprint(d))
	{
		std::cout << static_cast<char>(d) << std::endl;
	}
	else if (d >= CHAR_MIN && d <= CHAR_MAX && is_whole(d) && !std::isprint(d))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "int: ";
	if (d >= INT_MIN && d <= INT_MAX && is_whole(d))
	{
		std::cout << static_cast<int>(d) << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}

	{
		std::cout << "float: ";

		// "If float supports infinity, no double is outside its range."
		// - Eric Postpischil in the comments of the question at https://stackoverflow.com/q/65610811
		float f = static_cast<float>(d);

		std::stringstream ss;
		ss << f;
		if (isfinite(f) && is_whole(f) && ss.str().find("e") == std::string::npos)
		{
			ss << ".0";
		}
		std::cout << ss.str() << "f" << std::endl;
	}

	{
		std::stringstream ss;
		ss << d;
		if (isfinite(d) && is_whole(d) && ss.str().find("e") == std::string::npos)
		{
			ss << ".0";
		}
		std::cout << "double: " << ss.str() << std::endl;
	}
}

bool ScalarConverter::is_whole(float f)
{
	return std::floor(f) == f;
}

bool ScalarConverter::is_whole(double d)
{
	return std::floor(d) == d;
}
