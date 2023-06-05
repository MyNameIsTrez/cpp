#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"

#include <iostream>

Cure::Cure()
	: AMateria("cure")
{
}

Cure::Cure(const Cure &src)
	: AMateria(src)
{
	_type = "cure";
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const Cure &src)
{
	if (this == &src)
		return (*this);

	// There's nothing to be done

	return (*this);
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout
	<< "* heals "
	<< target.getName()
	<< "'s wounds *"
	<< std::endl;
}
