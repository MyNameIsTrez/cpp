#include <cassert>
#include <iostream>

#include "Serializer.hpp"

struct Data
{
	int a;
};

void tests()
{
	Data d = {.a=42};

	uintptr_t d_uintptr = Serializer::serialize(&d);

	Data *d_ptr = Serializer::deserialize(d_uintptr);

	assert(&d == d_ptr);
	assert(d_ptr->a == 42);
}

int	main()
{
	tests();

	system("leaks -q serialize");

	// \u2713 is a unicode checkmark character
	std::cout << "\u2713 All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
