#include "Dog.hpp"

#include <iostream>

Dog::Dog()
{
	std::cout
	<< "Default constructor of Dog called."
	<< std::endl;

	type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout
	<< "Copy constructor of Dog called."
	<< std::endl;

	type = src.type;
}

Dog::~Dog()
{
	std::cout
	<< "Destructor of Dog called."
	<< std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout
	<< "Copy assignment operator of Dog called."
	<< std::endl;

	if (this == &src)
		return (*this);

	type = src.type;

	return (*this);
}

void Dog::makeSound() const
{
	std::cout
	<< "Woof!"
	<< std::endl;
}
