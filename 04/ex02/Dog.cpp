#include "Brain.hpp"
#include "Dog.hpp"

#include <iostream>

Dog::Dog()
	: brain(new Brain())
{
	std::cout
	<< "Default constructor of Dog called."
	<< std::endl;

	type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout
	<< "Copy constructor of Dog called."
	<< std::endl;

	type = src.type;

	brain = new Brain(*src.brain);
}

Dog::~Dog()
{
	std::cout
	<< "Destructor of Dog called."
	<< std::endl;

	delete brain;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout
	<< "Copy assignment operator of Dog called."
	<< std::endl;

	if (this == &src)
		return (*this);

	type = src.type;

	*brain = *src.brain;

	return (*this);
}

void Dog::makeSound() const
{
	std::cout
	<< "Woof!"
	<< std::endl;
}

void Dog::add_idea(std::string idea)
{
	brain->add_idea(idea);
}

std::string &Dog::get_idea(size_t index)
{
	return brain->get_idea(index);
}
