#pragma once

#include "Weapon.hpp"

#include <string>

class HumanB {
public:
	HumanB(std::string name);

	void	attack();
	void	setWeapon(Weapon &weapon);

private:
	std::string	name;
	Weapon		*weapon;
};
