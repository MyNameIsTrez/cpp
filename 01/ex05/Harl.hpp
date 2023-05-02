#pragma once

#include <string>

class Harl {
public:
	void	complain(std::string level);

private:
	void	debug();
	void	info();
	void	warning();
	void	error();
};

typedef void	(Harl::*t_comment_fn)();

struct comment_metadata {
	std::string		key;
	t_comment_fn	fn;
};
