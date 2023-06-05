#pragma once

#include <string>

class AAnimal
{
public:
	AAnimal &operator=(const AAnimal &src);

	virtual void makeSound() const = 0;

	const std::string &getType() const;

protected:
	AAnimal();
	AAnimal(const AAnimal &src);
	virtual ~AAnimal();

	std::string type;
};
