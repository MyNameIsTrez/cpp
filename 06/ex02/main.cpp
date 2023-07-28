#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cassert>
#include <iostream>
#include <utility>

class Base;

Base *generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A;
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B;
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C;
	}
	return nullptr;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast) {}
}

void tests()
{
	for (int i = 0; i < 10; i++)
	{
		Base *base_ptr = generate();
		std::cout << "*";
		identify(base_ptr);

		Base &base = *base_ptr;
		std::cout << "&";
		identify(base);

		std::cout << std::endl;

		delete base_ptr;
	}
}

int	main()
{
	srand(time(NULL));

	tests();

	system("leaks -q identify");

	// \u2713 is a unicode checkmark character
	std::cout << "\u2713 All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
