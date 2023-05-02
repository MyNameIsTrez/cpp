#pragma once

#include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie();

	void	announce();

private:
	std::string	name;
};
