#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name")
	, ScavTrap(_name)
	, FragTrap(_name)
	, name(_name)
{
	std::cout
	<< "Constructor of DiamondTrap "
	<< name
	<< " called."
	<< std::endl;

	hitpoints = FragTrap::base_hitpoints;
	energy_points = ScavTrap::base_energy_points;
	attack_damage = FragTrap::base_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
	: ClapTrap(src.name + "_clap_name")
	, ScavTrap(src.name)
	, FragTrap(src.name)
	, name(src.name)
{
	std::cout
	<< "Copy constructor of source DiamondTrap "
	<< src.name
	<< " called."
	<< std::endl;

	hitpoints = src.hitpoints;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout
	<< "Destructor of DiamondTrap "
	<< name
	<< " called."
	<< std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout
	<< "Copy assignment operator of source DiamondTrap "
	<< src.name
	<< " to destination DiamondTrap "
	<< name
	<< " called."
	<< std::endl;

	if (this == &src)
		return (*this);

	ClapTrap::name = src.name + "_clap_name";
	name = src.name;
	hitpoints = src.hitpoints;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;

	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout
	<< "I am DiamondTrap "
	<< name
	<< " with ClapTrap name "
	<< ClapTrap::name
	<< "."
	<< std::endl;
}

DiamondTrap::DiamondTrap()
{
	std::cout
	<< "Unimplemented default constructor of DiamondTrap called."
	<< std::endl;
}
