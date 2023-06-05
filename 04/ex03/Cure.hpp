#pragma once

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &src);
	virtual ~Cure();
	Cure &operator=(const Cure &src);

	AMateria *clone() const;
	void use(ICharacter &target);
};
