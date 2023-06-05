#pragma once

#include <string>

class Animal
{
public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();
	Animal &operator=(const Animal &src);

	virtual void makeSound() const;

	const std::string &getType() const;

protected:
	std::string type;
};
