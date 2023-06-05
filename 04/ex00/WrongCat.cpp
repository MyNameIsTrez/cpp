#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
{
	std::cout
	<< "Default constructor of WrongCat called."
	<< std::endl;

	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout
	<< "Copy constructor of WrongCat called."
	<< std::endl;

	type = src.type;
}

WrongCat::~WrongCat()
{
	std::cout
	<< "Destructor of WrongCat called."
	<< std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout
	<< "Copy assignment operator of WrongCat called."
	<< std::endl;

	if (this == &src)
		return (*this);

	type = src.type;

	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout
	<< "Meow!"
	<< std::endl;
}
