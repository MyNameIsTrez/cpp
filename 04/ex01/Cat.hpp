#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &src);
	virtual ~Cat();
	Cat &operator=(const Cat &src);

	void makeSound() const;

	void add_idea(std::string idea);
	std::string &get_idea(size_t index);

private:
	Brain *brain;
};
