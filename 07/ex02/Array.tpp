#pragma once

#include "Array.hpp"

#include <stdexcept>

template <typename T>
Array<T>::Array()
	: _n(0)
	, _data(nullptr)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _n(n)
	, _data(new T[n])
{
}

template <typename T>
Array<T>::Array(const Array &src)
	: _n(src.size())
	, _data(new T[src.size()])
{
	for (unsigned int i = 0; i < src.size(); i++)
	{
		_data[i] = src[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
	{
		return (*this);
	}

	delete[] _data;

	_n = src.size();

	_data = new T[src.size()];

	for (unsigned int i = 0; i < src.size(); i++)
	{
		_data[i] = src[i];
	}

	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _n)
	{
		throw std::out_of_range("Index out of bounds.");
	}

	return _data[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _n)
	{
		throw std::out_of_range("Index out of bounds.");
	}

	return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _n;
}
