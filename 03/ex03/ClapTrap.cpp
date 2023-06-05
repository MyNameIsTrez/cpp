#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string _name)
	: name(_name)
	, hitpoints(base_hitpoints)
	, energy_points(base_energy_points)
	, attack_damage(base_attack_damage)
{
	std::cout
	<< "Constructor of ClapTrap "
	<< name
	<< " called."
	<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
	: name(src.name)
	, hitpoints(src.hitpoints)
	, energy_points(src.energy_points)
	, attack_damage(src.attack_damage)
{
	std::cout
	<< "Copy constructor of source ClapTrap "
	<< src.name
	<< " called."
	<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout
	<< "Destructor of ClapTrap "
	<< name
	<< " called."
	<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout
	<< "Copy assignment operator of source ClapTrap "
	<< src.name
	<< " to destination ClapTrap "
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

void ClapTrap::attack(const std::string& target)
{
	if (hitpoints <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " can't attack; it's dead!"
		<< std::endl;
	}
	else if (energy_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " doesn't have enough energy points left to attack!"
		<< std::endl;
	}
	else
	{
		std::cout
		<< "ClapTrap "
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoints <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " is already dead!"
		<< std::endl;
	}
	else
	{
		hitpoints -= amount;

		std::cout
		<< "ClapTrap "
		<< name
		<< " takes "
		<< amount
		<< " points of damage and now has "
		<< hitpoints
		<< " hitpoints left!";

		if (hitpoints <= 0)
		{
			std::cout
			<< " ClapTrap "
			<< name
			<< " dies!";
		}

		std::cout
		<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitpoints <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " can't be repaired; it's dead!"
		<< std::endl;
	}
	else if (hitpoints == base_hitpoints)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " can't be repaired; it's already at full health!"
		<< std::endl;
	}
	else if (energy_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " doesn't have enough energy points left to repair itself!"
		<< std::endl;
	}
	else
	{
		int old_hitpoints = hitpoints;

		hitpoints = hitpoints + amount;

		std::cout
		<< "ClapTrap "
		<< name
		<< " got repaired for "
		<< amount
		<< " hitpoints, from "
		<< old_hitpoints
		<< " to "
		<< hitpoints
		<< " hitpoints!"
		<< std::endl;

		energy_points--;
	}
}

ClapTrap::ClapTrap()
{
	std::cout
	<< "Unimplemented default constructor of ClapTrap called."
	<< std::endl;
}
