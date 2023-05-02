#include "Zombie.hpp"

#include <iostream>

Zombie	*zombieHorde(int N, std::string name);

void	check_leaks() {
	system("leaks -q zombie_horde");
}

int	main() {
	Zombie	*zombies;

	atexit(check_leaks);

	zombies = zombieHorde(0, "a");
	delete[] zombies;

	zombies = zombieHorde(1, "b");
	zombies[0].announce();
	delete[] zombies;

	zombies = zombieHorde(2, "c");
	zombies[0].announce();
	zombies[1].announce();
	delete[] zombies;

	return EXIT_SUCCESS;
}
