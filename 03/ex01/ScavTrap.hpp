#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap &src);
	virtual ~ScavTrap();
	ScavTrap& operator=(const ScavTrap &src);

	void attack(const std::string& target);

	void guardGate();

private:
	static const int base_hitpoints = 100;
	static const int base_energy_points = 50;
	static const int base_attack_damage = 20;

	ScavTrap();
};
