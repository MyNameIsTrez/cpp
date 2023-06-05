#include "Brain.hpp"
#include "Cat.hpp"

#include <iostream>

Cat::Cat()
	: brain(new Brain())
{
	std::cout
	<< "Default constructor of Cat called."
	<< std::endl;

	type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout
	<< "Copy constructor of Cat called."
	<< std::endl;

	type = src.type;

	brain = new Brain(*src.brain);
}

Cat::~Cat()
{
	std::cout
	<< "Destructor of Cat called."
	<< std::endl;

	delete brain;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout
	<< "Copy assignment operator of Cat called."
	<< std::endl;

	if (this == &src)
		return (*this);

	type = src.type;

	*brain = *src.brain;

	return (*this);
}

void Cat::makeSound() const
{
	std::cout
	<< "Meow!"
	<< std::endl;
}

void Cat::add_idea(std::string idea)
{
	brain->add_idea(idea);
}

std::string &Cat::get_idea(size_t index)
{
	return brain->get_idea(index);
}
