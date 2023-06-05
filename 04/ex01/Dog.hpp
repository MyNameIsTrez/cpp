#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &src);
	virtual ~Dog();
	Dog &operator=(const Dog &src);

	void makeSound() const;

	void add_idea(std::string idea);
	std::string &get_idea(size_t index);

private:
	Brain *brain;
};
