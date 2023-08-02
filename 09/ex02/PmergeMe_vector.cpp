#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

std::vector<unsigned int> PmergeMe::parse_vector(char **input)
{
	std::vector<unsigned int> vec;

	for (size_t i = 0; input[i] != NULL; i++)
	{
		std::string str(input[i]);
		std::stringstream ss(str);
		unsigned int value;

		ss >> std::noskipws;
		ss >> value;

		if (ss.fail() || !ss.eof())
		{
			throw std::domain_error("Unexpected character.");
		}

		vec.push_back(value);
	}

	return vec;
}

// Implementation descriptions:
// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://youtu.be/wqibJMG42Ik?t=283
// https://www.tldraw.com/v/y9Y2Et7vl18fkPZT4UoEKTW?viewport=-475%2C-20%2C1920%2C2039&page=page%3AjEhR30akJPWN_ZhTL5KgI
//
// Example of the algorithm:
//
// 9 1 2 7 5 8 3 4
// 1 9 2 7 5 8 3 4 # swap
//   ^   ^   ^   ^
// 9 7 8 4
// 7 9 4 8 # swap
//   ^   ^
// 9 8
// 8 9 # swap
//   ^
//
// 9 # push the big element of the only pair when can't recurse any deeper
// 8 9 # insert at index 0 the small element that's paired with the first element of S
// return up
//
// 4 8 9 # insert at index 0 the small element that's paired with the first element of S
//
// 4 7 8 9 # insert small Y3=7 of big X3=9
// return up
//
// 3 4 7 8 9 # insert at index 0 the small element that's paired with the first element of S
//
// 3 4 5 7 8 9 # insert small Y4=5 of big X4=8
// 2 3 4 5 7 8 9 # insert small Y3=2 of big X3=7
// 1 2 3 4 5 7 8 9 # insert small Y5=1 of big X5=9
//
// Transfer S back into X
void PmergeMe::sort(std::vector<unsigned int> &arr)
{
	std::vector<Pair> X;
	std::vector<Pair> pairs;

	for (size_t i = 0; i < arr.size(); i++)
	{
		unsigned int value = arr[i];

		Pair pair = {
			.value = value,
			.index = pairs.size(),
			// SIZE_MAX is used here to indicate the value being uninitialized
			.small_parent_index = SIZE_MAX,
			.big_parent_index = SIZE_MAX,
			.depth = 0,
		};

		X.push_back(pair);
		pairs.push_back(pair);
	}

	std::vector<Pair> S;
	merge_insertion_sort(X, S, pairs, 1);

	transfer_sorted(S, arr);
}

void PmergeMe::merge_insertion_sort(std::vector<Pair> &X, std::vector<Pair> &S, std::vector<Pair> &pairs, size_t depth)
{
	if (X.size() == 1)
	{
		S.push_back(X[0]);
		return;
	}

	// Create child pairs
	std::vector<Pair> child_pairs;
	for (size_t i = 1; i < X.size(); i += 2)
	{
		Pair *small_parent;
		Pair *big_parent;

		if (X[i - 1].value > X[i].value)
		{
			small_parent = &X[i];
			big_parent = &X[i - 1];
		}
		else
		{
			small_parent = &X[i - 1];
			big_parent = &X[i];
		}

		unsigned int value = big_parent->value;

		Pair pair = {
			.value = value,
			.index = pairs.size(),
			.small_parent_index = small_parent->index,
			.big_parent_index = big_parent->index,
			.depth = depth,
		};

		child_pairs.push_back(pair);
		pairs.push_back(pair);
	}

	merge_insertion_sort(child_pairs, S, pairs, depth + 1);

	// Insert at the start of S the element that was paired with the first and smallest element of S
	S.insert(S.begin(), pairs[S[0].small_parent_index]);

	// Copy S, since we don't want X1, X2, X3, etc. to move around by stuff being inserted in S later
	std::vector<Pair> S_copy(S);

	// Insert S_copy Y values at indices 3 -> 2 -> 5 -> 4 -> 11 -> ...
	size_t prev_highest_index = 1;
	size_t power_of_two = 4;
	while (prev_highest_index + 1 < S_copy.size())
	{
		size_t would_be_highest_index = power_of_two - prev_highest_index;
		size_t highest_index = std::min(would_be_highest_index, S_copy.size() - 1);
		size_t index = highest_index;

		size_t missing_elements = would_be_highest_index - highest_index;
		size_t elements_placed_at_end = 0;

		// Insert S_copy Y values at indices 3 -> 2, or 5 -> 4
		while (index > prev_highest_index)
		{
			Pair *big_parent = &S_copy[index];
			while (big_parent->depth > depth)
			{
				big_parent = &pairs[big_parent->big_parent_index];
			}

			if (subsequence_insertion_sort(S, power_of_two - 1 - missing_elements - elements_placed_at_end, pairs[big_parent->small_parent_index]))
			{
				elements_placed_at_end++;
			}

			index--;
		}

		power_of_two <<= 1;
		prev_highest_index = highest_index;
	}

	// Insert straggler
	if (X.size() % 2 == 1)
	{
		subsequence_insertion_sort(S, S.size(), X.back());
	}
}

bool PmergeMe::subsequence_insertion_sort(std::vector<Pair> &S, size_t subsequence_length, Pair &pair)
{
	unsigned int value = pair.value;

	size_t start = 0;
	size_t end = subsequence_length;

	while (start < end)
	{
		size_t halfway_index = (start + end) / 2;
		Pair &halfway_pair = S[halfway_index];
		unsigned int halfway_value = halfway_pair.value;

		if (halfway_value < value)
		{
			start = halfway_index + 1;
		}
		else
		{
			end = halfway_index;
		}
	}

	S.insert(S.begin() + start, pair);

	// Return whether the value was placed at the end, so future subsequence lengths can be shorter
	return start == subsequence_length;
}

void PmergeMe::transfer_sorted(std::vector<Pair> &S, std::vector<unsigned int> &arr)
{
	for (size_t i = 0; i < S.size(); i++)
	{
		arr[i] = S[i].value;
	}
}
