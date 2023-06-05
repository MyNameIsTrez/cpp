#pragma once

#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &src);
	virtual ~Brain();
	Brain &operator=(const Brain &src);

	void add_idea(std::string idea);
	std::string &get_idea(size_t index);

private:
	static const int MAX_IDEA_COUNT = 100;

	std::string ideas[MAX_IDEA_COUNT];
	int current_idea_count;
};
