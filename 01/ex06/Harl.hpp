#pragma once

#include <string>

class Harl {
public:
	void	complain(std::string level);

private:
	int	get_complaint_index(const std::string level);

	void	debug();
	void	info();
	void	warning();
	void	error();
};
