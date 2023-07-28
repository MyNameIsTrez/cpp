#pragma once

#include <iostream>

template <class InputIterator>
Span::Span(InputIterator first, InputIterator last)
	: _n(last - first)
	, _data(first, last)
{
}
