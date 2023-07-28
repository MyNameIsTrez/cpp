#pragma once

#include <vector>

class Span
{
public:
	Span(unsigned int n);

	template <class InputIterator>
	Span(InputIterator first, InputIterator last);

	Span(const Span &src);
	virtual ~Span();
	Span &operator=(const Span &src);

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

private:
	Span();

	unsigned int _n;
	std::vector<int> _data;
};

#include "Span.tpp"
