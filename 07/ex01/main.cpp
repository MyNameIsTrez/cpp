#include "iter.hpp"

#include <iostream>

struct Data
{
	int i;
};

void nextChar(char &element)
{
	element++;
}

void printChar(const char &element)
{
	std::cout << element << std::endl;
}

template<typename T>
void printData(const T &element)
{
	std::cout << element.i << std::endl;
}

static void tests()
{
	{
		char str[] = "abc";

		::iter(str, 3, nextChar);

		assert(strcmp(str, "bcd") == 0);
	}
	{
		const char str[] = "abc";

		::iter(str, 3, printChar);
	}
	{
		char str[] = "abc";

		::iter(str, 3, printChar);
	}
	{
		Data data[] = {{4}, {2}, {0}};

		::iter(data, 3, printData);
	}
}

int	main()
{
	tests();

	system("leaks -q iter");

	std::cout << "✓ All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
