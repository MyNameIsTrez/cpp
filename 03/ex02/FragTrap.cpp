#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(std::string _name)
	: ClapTrap(_name)
{
	std::cout
	<< "Constructor of FragTrap "
	<< name
	<< " called."
	<< std::endl;

	hitpoints = base_hitpoints;
	energy_points = base_energy_points;
	attack_damage = base_attack_damage;
}

FragTrap::FragTrap(const FragTrap &src)
	: ClapTrap(src.name)
{
	std::cout
	<< "Copy constructor of source FragTrap "
	<< src.name
	<< " called."
	<< std::endl;

	hitpoints = src.hitpoints;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;
}

FragTrap::~FragTrap()
{
	std::cout
	<< "Destructor of FragTrap "
	<< name
	<< " called."
	<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout
	<< "Copy assignment operator of source FragTrap "
	<< src.name
	<< " to destination FragTrap "
	<< name
	<< " called."
	<< std::endl;

	if (this == &src)
		return (*this);

	name = src.name;
	hitpoints = src.hitpoints;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;

	return (*this);
}

void FragTrap::highFivesGuys()
{
	std::cout
	<< "FragTrap "
	<< name
	<< " requests to high five the guys."
	<< std::endl;
}

FragTrap::FragTrap()
{
	std::cout
	<< "Unimplemented default constructor of FragTrap called."
	<< std::endl;
}
