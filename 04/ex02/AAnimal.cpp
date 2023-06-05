#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal()
	: type("AAnimal")
{
	std::cout
	<< "Default constructor of AAnimal called."
	<< std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
	: type(src.type)
{
	std::cout
	<< "Copy constructor of AAnimal called."
	<< std::endl;
}

AAnimal::~AAnimal()
{
	std::cout
	<< "Destructor of AAnimal called."
	<< std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout
	<< "Copy assignment operator of AAnimal called."
	<< std::endl;

	if (this == &src)
		return (*this);

	type = src.type;

	return (*this);
}

const std::string &AAnimal::getType() const
{
	return type;
}
