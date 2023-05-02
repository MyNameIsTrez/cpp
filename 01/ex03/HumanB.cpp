#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string name)
		: name(name) {
}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
