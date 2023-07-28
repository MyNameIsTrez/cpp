#include "Span.hpp"

#include <algorithm>
#include <iostream>

Span::Span(unsigned int n)
	 : _n(n)
{
}

Span::Span(const Span &src)
	 : _n(src._n)
	 , _data(src._data)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
	{
		return (*this);
	}

	_n = src._n;

	_data = src._data;

	return (*this);
}

void Span::addNumber(int number)
{
	if (_data.size() >= _n)
	{
		throw std::length_error("This Span is full.");
	}

	_data.push_back(number);
}

int Span::shortestSpan()
{
	if (_data.size() <= 1)
	{
		throw std::length_error("This Span doesn't contain at least two numbers.");
	}

	std::sort(_data.begin(), _data.end());

	unsigned int shortest_span = UINT_MAX;

	for (size_t i = 0; i < _n - 1; i++)
	{
		unsigned int span = _data[i + 1] - _data[i];

		if (span < shortest_span)
		{
			shortest_span = span;
		}
	}

	return (shortest_span);
}

int Span::longestSpan()
{
	if (_data.size() <= 1)
	{
		throw std::length_error("This Span doesn't contain at least two numbers.");
	}

	std::sort(_data.begin(), _data.end());

	return (_data[_data.size() - 1] - _data[0]);
}
