#include "easyfind.hpp"

#include <iostream>
#include <vector>

static void tests()
{
	{
		std::vector<int> arr;
		arr.push_back(42);
		arr.push_back(1337);

		assert(*easyfind(arr, 42) == 42);
		*easyfind(arr, 42) = 77;
		assert(*easyfind(arr, 77) == 77);

		assert(easyfind(arr, 4242) == arr.end());
	}
	{
		std::vector<char> arr;
		arr.push_back('a');
		arr.push_back('b');
		assert(*easyfind(arr, 'a') == 'a');
		assert(easyfind(arr, 'c') == arr.end());
	}
	{
		std::vector<int> arr;
		arr.push_back(42);
		arr.push_back(1337);

		const std::vector<int> const_arr(arr);

		assert(*easyfind(const_arr, 42) == 42);

		// Doesn't compile, as expected with it being const
		// *easyfind(const_arr, 42) = 77;
		// assert(*easyfind(const_arr, 77) == 77);

		assert(easyfind(const_arr, 4242) == const_arr.end());
	}
}

int	main()
{
	tests();

	system("leaks -q easyfind");

	std::cout << "✓ All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
