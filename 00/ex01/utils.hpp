#pragma once

#include <istream>
#include <string>

namespace utils {

bool	prompt(std::string const &p, std::string &output);

size_t	min(size_t a, size_t b);

std::string	truncate(std::string sv);

enum STR_TO_SIZE_ERROR { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };
STR_TO_SIZE_ERROR	str_to_size(size_t &i, char const *s);

}
