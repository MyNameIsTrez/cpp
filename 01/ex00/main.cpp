#include "Zombie.hpp"

#include <iostream>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

void	check_leaks() {
	system("leaks -q zombie");
}

int	main() {
	atexit(check_leaks);

	// This is a stupid exercise, since the heap is most
	// useful when you need an unknown number of zombies.
	Zombie	*zombie_ptr = newZombie("heap zombie");
	zombie_ptr->announce();
	delete zombie_ptr;

	randomChump("stack zombie");

	return EXIT_SUCCESS;
}
