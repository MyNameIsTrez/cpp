#include "DiamondTrap.hpp"

#include <iostream>

void	check_leaks() {
	system("leaks -q diamondtrap");
}

int	main() {
	atexit(check_leaks);

	DiamondTrap foo("foo");
	DiamondTrap bar("bar");
	DiamondTrap bar_copy(bar);

	foo.beRepaired(1);
	foo.attack("bar");
	foo.takeDamage(3);
	foo.beRepaired(1);
	foo.beRepaired(3);
	foo.takeDamage(11);
	foo.takeDamage(1);
	foo.attack("bar");
	foo.beRepaired(5);

	bar.takeDamage(1);
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.attack("bar");
	bar.beRepaired(5);
	bar.takeDamage(8);

	foo = bar;
	foo.takeDamage(3);

	bar_copy.attack("bar");
	bar_copy.guardGate();
	bar_copy.guardGate();
	bar_copy.highFivesGuys();
	bar_copy.highFivesGuys();
	bar_copy.whoAmI();
	bar_copy.whoAmI();

	return EXIT_SUCCESS;
}
