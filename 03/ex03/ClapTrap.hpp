#pragma once

#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap &src);
	virtual ~ClapTrap();
	ClapTrap& operator=(const ClapTrap &src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	static const int base_hitpoints = 10;
	static const int base_energy_points = 10;
	static const int base_attack_damage = 0;

	ClapTrap();

	std::string name;
	int hitpoints;
	int energy_points;
	int attack_damage;
};
