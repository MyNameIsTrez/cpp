#include <cassert>
#include <iostream>
#include <limits>
#include <sstream>

#include "ScalarConverter.hpp"

void char_tests(std::stringstream &buffer)
{
	ScalarConverter::convert("b");
	assert(buffer.str() == "char: b\nint: 98\nfloat: 98.0f\ndouble: 98.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("@");
	assert(buffer.str() == "char: @\nint: 64\nfloat: 64.0f\ndouble: 64.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert(" b");
	assert(buffer.str() == "char: b\nint: 98\nfloat: 98.0f\ndouble: 98.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("b ");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);
}

void int_tests(std::stringstream &buffer)
{
	// INT_MIN - 1
	ScalarConverter::convert("-2147483649");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: -2.14748e+09f\ndouble: -2.14748e+09\n");
	std::stringstream().swap(buffer);

	// INT_MIN
	ScalarConverter::convert("-2147483648");
	assert(buffer.str() == "char: impossible\nint: -2147483648\nfloat: -2.14748e+09f\ndouble: -2.14748e+09\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-42");
	assert(buffer.str() == "char: impossible\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("0");
	assert(buffer.str() == "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("42");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("+42");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	// INT_MAX
	ScalarConverter::convert("2147483647");
	assert(buffer.str() == "char: impossible\nint: 2147483647\nfloat: 2.14748e+09f\ndouble: 2.14748e+09\n");
	std::stringstream().swap(buffer);

	// INT_MAX + 1
	ScalarConverter::convert("2147483648");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: 2.14748e+09f\ndouble: 2.14748e+09\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert(" 42");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("42 ");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);
}

void float_tests(std::stringstream &buffer)
{
	ScalarConverter::convert("-9999999999999999999999999999999999999999999999999999.0f");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-42.0f");
	assert(buffer.str() == "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-0.3f");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: -0.3f\ndouble: -0.3\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-0f");
	assert(buffer.str() == "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("0f");
	assert(buffer.str() == "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("0.3f");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: 0.3f\ndouble: 0.3\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("42.0f");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("+42.0f");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("9999999999999999999999999999999999999999999999999999.0f");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-inff");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("+inff");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("nanf");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert(" 42.0f");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("42.0f ");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);
}

void double_tests(std::stringstream &buffer)
{
	ScalarConverter::convert("-9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: -inff\ndouble: -1e+100\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-42.0");
	assert(buffer.str() == "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-0.3");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: -0.3f\ndouble: -0.3\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-0.0");
	assert(buffer.str() == "char: Non displayable\nint: 0\nfloat: -0.0f\ndouble: -0.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("0.0");
	assert(buffer.str() == "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("0.3");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: 0.3f\ndouble: 0.3\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("42.0");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("+42.0");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: inff\ndouble: 1e+100\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("-inf");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("+inf");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("nan");
	assert(buffer.str() == "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert(" 42.0");
	assert(buffer.str() == "char: *\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("42.0 ");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);
}

void other_tests(std::stringstream &buffer)
{
	ScalarConverter::convert("");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	// Unprintable character
	ScalarConverter::convert("");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("\n");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("hello world");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("--1");
	assert(buffer.str() == "Error: The input wasn't a char/int/float/double\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("1.2e3f");
	assert(buffer.str() == "char: impossible\nint: 1200\nfloat: 1200.0f\ndouble: 1200.0\n");
	std::stringstream().swap(buffer);

	ScalarConverter::convert("1.2e3");
	assert(buffer.str() == "char: impossible\nint: 1200\nfloat: 1200.0f\ndouble: 1200.0\n");
	std::stringstream().swap(buffer);
}

int	main()
{
	// Redirect anything written to std::cout to this buffer
	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

	char_tests(buffer);
	int_tests(buffer);
	float_tests(buffer);
	double_tests(buffer);
	other_tests(buffer);

	// Redirect std::cout back to the real std::cout
	std::cout.rdbuf(old);

	system("leaks -q static");

	// \u2713 is a unicode checkmark character
	std::cout << "\u2713 All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
