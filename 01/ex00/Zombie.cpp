#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name)
	: name(name) {
}

Zombie::~Zombie() {
	std::cout << "(destructor) Zombie name: " << name << std::endl;
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
