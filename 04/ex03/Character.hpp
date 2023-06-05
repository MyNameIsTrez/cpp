#pragma once

#include "ICharacter.hpp"

#include <string>

class AMateria;

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character &src);
	virtual ~Character();
	Character &operator=(const Character &src);

	std::string const &getName() const;
	void equip(AMateria *materia);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	static const int inventory_size = 4;

	std::string _name;
	AMateria *_inventory[inventory_size];
};
