#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string _name);
	FragTrap(const FragTrap &src);
	virtual ~FragTrap();
	FragTrap& operator=(const FragTrap &src);

	void highFivesGuys();

protected:
	static const int base_hitpoints = 100;
	static const int base_energy_points = 100;
	static const int base_attack_damage = 30;

	FragTrap();
};
