#pragma once

#include "Weapon.hpp"

#include <string>

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);

	void	attack();

private:
	std::string	name;
	Weapon		&weapon;
};
