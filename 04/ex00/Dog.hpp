#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &src);
	virtual ~Dog();
	Dog &operator=(const Dog &src);

	void makeSound() const;
};
