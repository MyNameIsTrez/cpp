#include "Array.hpp"

#include <iostream>

static void tests()
{
	{
		Array<char> arr;
		assert(arr.size() == 0);
		try { (void)arr[0]; assert(false); } catch (std::exception) {};
	}
	{
		Array<char> arr(2);
		assert(arr[0] == '\0');
		assert(arr[1] == '\0');

		arr[0] = 'a';
		assert(arr[0] == 'a');

		try { (void)arr[2]; assert(false); } catch (std::exception) {};
	}
	{
		Array<char> arr(2);
		arr[0] = 'a';
		arr[1] = 'b';

		const Array<char> arr2(arr);
		assert(arr2[0] == 'a');
		assert(arr2[1] == 'b');

		try { (void)arr2[2]; assert(false); } catch (std::exception) {};
	}
	{
		Array<char> arr(2);
		arr[0] = 'a';
		arr[1] = 'b';
		arr = arr;

		Array<char> arr2;
		arr2 = arr;
		arr[0] = 'c';
		assert(arr2[0] == 'a');
		assert(arr2[1] == 'b');

		arr2[0] = 'd';
		assert(arr[0] == 'c');
	}
	{
		Array<char> arr(2);
		assert(arr.size() == 2);
	}
}

int	main()
{
	tests();

	system("leaks -q array");

	std::cout << "✓ All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
