#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <vector>

static void tests()
{
	{
		std::cout << "PDF example" << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		assert(mstack.top() == 17);

		mstack.pop();

		assert(mstack.size() == 1);

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl << "PDF example using std::list" << std::endl;

		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		assert(mstack.back() == 17);

		mstack.pop_back();

		assert(mstack.size() == 1);

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::list<int> s(mstack);
	}
	{
		std::cout << std::endl << "const_iterator" << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		const MutantStack<int> const_mstack(mstack);

		MutantStack<int>::const_iterator it = const_mstack.begin();
		MutantStack<int>::const_iterator ite = const_mstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(const_mstack);
	}
	{
		std::cout << std::endl << "std::stack is OCF for us" << std::endl;

		MutantStack<int> *mstack = new MutantStack<int>();

		mstack->push(5);
		assert(mstack->top() == 5);

		MutantStack<int> mstack2(*mstack);
		assert(mstack2.top() == 5);

		MutantStack<int> mstack3;
		mstack3 = *mstack;
		assert(mstack3.top() == 5);

		delete mstack;
	}
}

int	main()
{
	tests();

	std::cout << std::endl;

	system("leaks -q mutant");

	std::cout << "✓ All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
