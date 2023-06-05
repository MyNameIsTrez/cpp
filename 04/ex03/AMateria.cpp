#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this == &src)
		return (*this);

	// From the subject PDF:
	// "While assigning a Materia to another, copying the type doesn’t make sense."
	// The fuck kind of logic is that??
	// _type = src._type;

	return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	// Deliberately unreachable
	(void)target;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::AMateria()
{
	// Deliberately unreachable
}
