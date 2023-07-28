#pragma once

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

private:
	// NOTE: I'm deliberately not implementing any of these,
	// since std::stack this is inheriting from is already OCF,
	// and this class doesn't have any member variables:

	// MutantStack();
	// MutantStack(const MutantStack &src);
	// virtual ~MutantStack();
	// MutantStack &operator=(const MutantStack &src);
};

#include "MutantStack.tpp"
