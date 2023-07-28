#pragma once

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	virtual ~Array();
	Array &operator=(const Array &src);

	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;
	unsigned int size() const;

private:
	unsigned int _n;
	T *_data;
};

#include "Array.tpp"
