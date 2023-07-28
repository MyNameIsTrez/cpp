#include "whatever.hpp"

#include <iostream>

// c_printf

// namespace my {
// 	my_printf
// }

// using namespace my;

// ::printf // c_printf in global
// printf // my_printf in namespace

static void tests()
{
	{
		int a = 2;
		int b = 3;

		::swap(a, b);
		assert(a == 3);
		assert(b == 2);

		assert(::min(a, b) == 2);
		assert(::max(a, b) == 3);

		int &min_ref = ::min(a, b);
		min_ref--;
		assert(b == 1);
	}
	{
		const int a = 2;
		const int b = 3;

		// This doesn't (and shouldn't) compile:
		// ::swap(a, b);
		// assert(a == 3);
		// assert(b == 2);

		assert(::min(a, b) == 2);
		assert(::max(a, b) == 3);

		// This doesn't (and shouldn't) compile:
		// int &min_ref = ::min(a, b);
	}
	{
		std::string a = "chaine1";
		std::string b = "chaine2";

		::swap(a, b);
		assert(a == "chaine2");
		assert(b == "chaine1");

		assert(::min(a, b) == "chaine1");
		assert(::max(a, b) == "chaine2");

		std::string &min_ref = ::min(a, b);
		min_ref[0] = 'x';
		assert(b == "xhaine1");
	}
}

int	main()
{
	tests();

	system("leaks -q whatever");

	std::cout << "✓ All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
