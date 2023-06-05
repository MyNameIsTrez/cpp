#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap &src);
	virtual ~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap &src);

	using ScavTrap::attack;
	void whoAmI();

private:
	DiamondTrap();

	std::string name;
};
