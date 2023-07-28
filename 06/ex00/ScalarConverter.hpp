#pragma once

#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &string);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	virtual ~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

	static void handle_int(int i);
	static void handle_float(float f);
	static void handle_double(double d);

	static bool is_whole(float f);
	static bool is_whole(double d);
};
