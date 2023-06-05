#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &src);
	virtual ~Ice();
	Ice &operator=(const Ice &src);

	AMateria *clone() const;
	void use(ICharacter &target);
};
