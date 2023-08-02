#include "PmergeMe.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>

#ifdef TESTS
static void test_vector()
{
	{
		const char *input_[] = {
			"18",
			"2",
			"4",
			"14",
			"15",
			"16",
			"6",
			"8",
			NULL,
		};
		char **input = (char**)input_;

		std::vector<unsigned int> ints = PmergeMe::parse_vector(input);
		std::vector<unsigned int>::iterator it = ints.begin();
		assert(*(it++) == 18);
		assert(*(it++) == 2);
		assert(*(it++) == 4);
		assert(*(it++) == 14);
		assert(*(it++) == 15);
		assert(*(it++) == 16);
		assert(*(it++) == 6);
		assert(*(it++) == 8);

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		const char *input_[] = {
			"1",
			"2",
			"0",
			"3",
			"4",
			NULL,
		};
		char **input = (char**)input_;

		std::vector<unsigned int> ints = PmergeMe::parse_vector(input);
		std::vector<unsigned int>::iterator it = ints.begin();
		assert(*(it++) == 1);
		assert(*(it++) == 2);
		assert(*(it++) == 0);
		assert(*(it++) == 3);
		assert(*(it++) == 4);

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		const char *input_[] = {
			"9",
			"1",
			"2",
			"7",
			"5",
			"8",
			"3",
			"4",
			NULL,
		};
		char **input = (char**)input_;

		std::vector<unsigned int> ints = PmergeMe::parse_vector(input);
		std::vector<unsigned int>::iterator it = ints.begin();
		assert(*(it++) == 9);
		assert(*(it++) == 1);
		assert(*(it++) == 2);
		assert(*(it++) == 7);
		assert(*(it++) == 5);
		assert(*(it++) == 8);
		assert(*(it++) == 3);
		assert(*(it++) == 4);

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		std::list<unsigned int> ints;

		for (size_t i = 0; i < 3001; i++) {
			ints.push_back((rand() % 100000) + 1);
		}

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		for (size_t rounds = 0; rounds < 100; rounds++) {
			std::vector<unsigned int> ints;

			for (size_t i = 0; i < 3000; i++) {
				ints.push_back((rand() % 100000) + 1);
			}

			PmergeMe::sort(ints);
			assert(std::is_sorted(ints.begin(), ints.end()));
		}
	}
	{
		std::vector<unsigned int> ints;

		for (size_t i = 0; i < 47; i++) {
			ints.push_back((rand() % 1001));
		}

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		const char *input_[] = {
			"-1",
			"2",
			NULL,
		};
		char **input = (char**)input_;

		try { PmergeMe::parse_vector(input); assert(false); } catch (std::exception) {}
	}
	{
		const char *input_[] = {
			" 1",
			NULL,
		};
		char **input = (char**)input_;

		try { PmergeMe::parse_vector(input); assert(false); } catch (std::exception) {}
	}
	{
		const char *input_[] = {
			"1 ",
			NULL,
		};
		char **input = (char**)input_;

		try { PmergeMe::parse_vector(input); assert(false); } catch (std::exception) {}
	}
}

static void test_list()
{
	{
		const char *input_[] = {
			"1",
			"2",
			"0",
			"3",
			"4",
			NULL,
		};
		char **input = (char**)input_;

		std::list<unsigned int> ints = PmergeMe::parse_list(input);
		std::list<unsigned int>::iterator it = ints.begin();
		assert(*(it++) == 1);
		assert(*(it++) == 2);
		assert(*(it++) == 0);
		assert(*(it++) == 3);
		assert(*(it++) == 4);

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		const char *input_[] = {
			"9",
			"1",
			"2",
			"7",
			"5",
			"8",
			"3",
			"4",
			NULL,
		};
		char **input = (char**)input_;

		std::list<unsigned int> ints = PmergeMe::parse_list(input);
		std::list<unsigned int>::iterator it = ints.begin();
		assert(*(it++) == 9);
		assert(*(it++) == 1);
		assert(*(it++) == 2);
		assert(*(it++) == 7);
		assert(*(it++) == 5);
		assert(*(it++) == 8);
		assert(*(it++) == 3);
		assert(*(it++) == 4);

		PmergeMe::sort(ints);
		assert(std::is_sorted(ints.begin(), ints.end()));
	}
	{
		for (size_t rounds = 0; rounds < 100; rounds++) {
			std::vector<unsigned int> ints;

			for (size_t i = 0; i < 47; i++) {
				ints.push_back((rand() % 1001));
			}

			PmergeMe::sort(ints);
			assert(std::is_sorted(ints.begin(), ints.end()));
		}
	}
	{
		const char *input_[] = {
			"-1",
			"2",
			NULL,
		};
		char **input = (char**)input_;

		try { PmergeMe::parse_list(input); assert(false); } catch (std::exception) {}
	}
	{
		const char *input_[] = {
			" 1",
			NULL,
		};
		char **input = (char**)input_;

		try { PmergeMe::parse_list(input); assert(false); } catch (std::exception) {}
	}
	{
		const char *input_[] = {
			"1 ",
			NULL,
		};
		char **input = (char**)input_;

		try { PmergeMe::parse_list(input); assert(false); } catch (std::exception) {}
	}
}
#endif

int	main(int argc, char *argv[])
{
	try {
#ifdef TESTS
	(void)argv;

	if (argc > 1) {
		throw std::runtime_error("No argument expected, did you mean to run without TESTS=1?");
	}

	srand(time(NULL));

	test_vector();
	test_list();

	std::cout << "✓ All tests passed!" << std::endl << std::endl;
#else
	if (argc < 2) {
		throw std::runtime_error("Expected at least 1 positive number.");
	}


	timespec vec_start;
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &vec_start);

	std::vector<unsigned int> vec = PmergeMe::parse_vector(&argv[1]);

	PmergeMe::sort(vec);

	timespec vec_end;
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &vec_end);

	if (!std::is_sorted(vec.begin(), vec.end())) {
		throw std::runtime_error("Vector wasn't sorted.");
	}


	timespec list_start;
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &list_start);

	std::list<unsigned int> list = PmergeMe::parse_list(&argv[1]);

	PmergeMe::sort(list);

	timespec list_end;
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &list_end);

	if (!std::is_sorted(list.begin(), list.end())) {
		throw std::runtime_error("List wasn't sorted.");
	}


	std::vector<unsigned int> vec_original = PmergeMe::parse_vector(&argv[1]);
	std::cout << "Before : ";
	for (size_t i = 0; i < vec_original.size(); i++) {
		if (i > 0)
			std::cout << " ";
		std::cout << vec_original[i];
	}
	std::cout << std::endl;

	std::cout << "After  : ";
	for (size_t i = 0; i < vec.size(); i++) {
		if (i > 0)
			std::cout << " ";
		std::cout << vec[i];
	}
	std::cout << std::endl;

	// (vec_end.tv_sec * 1e9 + vec_end.tv_nsec) - (vec_start.tv_sec * 1e9 + vec_start.tv_nsec)
	// vec_end.tv_sec * 1e9 + vec_end.tv_nsec - vec_start.tv_sec * 1e9 - vec_start.tv_nsec
	// (vec_end.tv_sec * 1e9 - vec_start.tv_sec * 1e9) + (vec_end.tv_nsec - vec_start.tv_nsec)

	std::cout
		<< "Time to process a range of "
		<< vec.size()
		<< " elements with std::vector<int> : "
		<< (vec_end.tv_sec - vec_start.tv_sec) * 1e6 + (vec_end.tv_nsec - vec_start.tv_nsec) / 1000.0
		<< " μs" << std::endl;

	std::cout
		<< "Time to process a range of "
		<< list.size()
		<< " elements with std::list<int>   : "
		<< (list_end.tv_sec - list_start.tv_sec) * 1e6 + (list_end.tv_nsec - list_start.tv_nsec) / 1000.0
		<< " μs" << std::endl;
#endif
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
		system("leaks -q PmergeMe");
		return (EXIT_FAILURE);
	}

	system("leaks -q PmergeMe");

	return EXIT_SUCCESS;
}
