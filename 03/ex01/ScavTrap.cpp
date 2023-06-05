#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(std::string _name)
	: ClapTrap(_name)
{
	std::cout
	<< "Constructor of ScavTrap "
	<< name
	<< " called."
	<< std::endl;

	hitpoints = base_hitpoints;
	energy_points = base_energy_points;
	attack_damage = base_attack_damage;
}

ScavTrap::ScavTrap(const ScavTrap &src)
	: ClapTrap(src.name)
{
	std::cout
	<< "Copy constructor of source ScavTrap "
	<< src.name
	<< " called."
	<< std::endl;

	hitpoints = src.hitpoints;
	energy_points = src.energy_points;
	attack_damage = src.attack_damage;
}

ScavTrap::~ScavTrap()
{
	std::cout
	<< "Destructor of ScavTrap "
	<< name
	<< " called."
	<< std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout
	<< "Copy assignment operator of source ScavTrap "
	<< src.name
	<< " to destination ScavTrap "
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

void ScavTrap::attack(const std::string& target)
{
	if (hitpoints <= 0)
	{
		std::cout
		<< "ScavTrap "
		<< name
		<< " can't attack; it's dead!"
		<< std::endl;
	}
	else if (energy_points <= 0)
	{
		std::cout
		<< "ScavTrap "
		<< name
		<< " doesn't have enough energy points left to attack!"
		<< std::endl;
	}
	else
	{
		std::cout
		<< "ScavTrap "
		<< name
		<< " attacks "
		<< target
		<< ", causing "
		<< attack_damage
		<< " points of damage!"
		<< std::endl;

		energy_points--;
	}
}

void ScavTrap::guardGate()
{
	std::cout
	<< "ScavTrap "
	<< name
	<< " is now in Gate keeper mode."
	<< std::endl;
}

ScavTrap::ScavTrap()
{
	std::cout
	<< "Unimplemented default constructor of ScavTrap called."
	<< std::endl;
}
