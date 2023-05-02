#include "utils.hpp"

#include <iostream>

bool	utils::prompt(std::string const &p, std::string &output) {
	std::cout << p << std::endl;
	if (!std::getline(std::cin, output))
		return (false);
	return (true);
}

size_t	utils::min(size_t a, size_t b) {
	if (a < b) {
		return (a);
	}
	return (b);
}

std::string	utils::truncate(std::string sv) {
	if (sv.length() > 10) {
    	return std::string(sv.substr(0, 9)) + ".";
	}
    return sv.substr(0, sv.length());
}

utils::STR_TO_SIZE_ERROR	utils::str_to_size(size_t &i, char const *s)
{
    char *end;
    long  l;

    errno = 0;
    l = strtol(s, &end, 10);
    i = l;
    if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX) {
        return utils::OVERFLOW;
    }
    if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN) {
        return utils::UNDERFLOW;
    }
    if (*s == '\0' || *end != '\0') {
        return utils::INCONVERTIBLE;
    }
    return utils::SUCCESS;
}
