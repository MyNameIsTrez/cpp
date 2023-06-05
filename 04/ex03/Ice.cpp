#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

#include <iostream>

Ice::Ice()
	: AMateria("ice")
{
}

Ice::Ice(const Ice &src)
	: AMateria(src)
{
	_type = "ice";
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const Ice &src)
{
	if (this == &src)
		return (*this);

	// There's nothing to be done

	return (*this);
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout
	<< "* shoots an ice bolt at "
	<< target.getName()
	<< " *"
	<< std::endl;
}
