#pragma once

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &src);

	void makeSound() const;

	const std::string &getType() const;

protected:
	std::string type;
};
