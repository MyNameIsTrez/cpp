#pragma once

#include <list>
#include <vector>

namespace PmergeMe
{
	std::vector<unsigned int> parse_vector(char **input);
	std::list<unsigned int> parse_list(char **input);

	void sort(std::vector<unsigned int> &arr);
	void sort(std::list<unsigned int> &arr);

	struct Pair {
		unsigned int value;
		size_t index;
		size_t small_parent_index;
		size_t big_parent_index;
		size_t depth;
	};

	void merge_insertion_sort(std::vector<Pair> &X, std::vector<Pair> &S, std::vector<Pair> &pairs, size_t depth);
	void transfer_sorted(std::vector<Pair> &S, std::vector<unsigned int> &arr);
	bool subsequence_insertion_sort(std::vector<Pair> &S, size_t subsequence_length, Pair &pair);

	void merge_insertion_sort(std::list<Pair> &X, std::list<Pair> &S, std::list<Pair> &pairs, size_t depth);
	void transfer_sorted(std::list<Pair> &S, std::list<unsigned int> &arr);
	bool subsequence_insertion_sort(std::list<Pair> &S, size_t subsequence_length, Pair &pair);
};
