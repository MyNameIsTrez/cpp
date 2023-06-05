#include "Brain.hpp"

#include <iostream>

Brain::Brain()
	: current_idea_count(0)
{
	std::cout
	<< "Default constructor of Brain called."
	<< std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout
	<< "Copy constructor of Brain called."
	<< std::endl;

	current_idea_count = src.current_idea_count;

	for (int i = 0; i < current_idea_count; i++)
	{
		ideas[i] = src.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout
	<< "Destructor of Brain called."
	<< std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout
	<< "Copy assignment operator of Brain called."
	<< std::endl;

	if (this == &src)
		return (*this);

	current_idea_count = src.current_idea_count;

	for (int i = 0; i < current_idea_count; i++)
	{
		ideas[i] = src.ideas[i];
	}

	return (*this);
}

void Brain::add_idea(std::string idea)
{
	ideas[current_idea_count] = idea;
	current_idea_count++;
}

std::string &Brain::get_idea(size_t index)
{
	return ideas[index];
}
