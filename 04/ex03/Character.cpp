#include "AMateria.hpp"
#include "Character.hpp"

#include <iostream>
#include <string>

Character::Character()
	: _name("No name")
	, _inventory()
{
}

Character::Character(std::string name)
	: _name(name)
	, _inventory()
{
}

Character::Character(const Character &src)
	: _inventory()
{
	*this = src;
}

Character::~Character()
{
	// Delete AMateria from _inventory
	for (int i = 0; i < inventory_size; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);

	_name = src._name;

	// Delete currently held AMateria
	for (int i = 0; i < inventory_size; i++)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}

	// Copy src's _inventory
	for (int i = 0; i < inventory_size; i++)
	{
		if (src._inventory[i] != NULL)
		{
			_inventory[i] = src._inventory[i]->clone();
		}
	}

	return (*this);
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *materia)
{
	// Don't allow storing the same AMateria twice
	for (int i = 0; i < inventory_size; i++)
	{
		if (_inventory[i] == materia)
		{
			return;
		}
	}

	for (int i = 0; i < inventory_size; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = materia;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= inventory_size)
		return;

	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	AMateria *materia;

	if (idx < 0 || idx >= inventory_size)
		return;

	materia = _inventory[idx];
	if (materia == NULL)
		return;

	materia->use(target);
}
