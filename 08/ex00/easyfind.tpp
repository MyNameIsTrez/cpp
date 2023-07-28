#pragma once

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, int integer)
{
  	return std::find(container.begin(), container.end(), integer);
}

template <typename T>
typename T::iterator easyfind(T &container, int integer)
{
  	return std::find(container.begin(), container.end(), integer);
}
