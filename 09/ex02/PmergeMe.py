import random, sys


def main():
    lst = [9, 1, 2, 7, 5, 8, 3, 4]
    pmergeme(lst)
    assert is_sorted(lst)

    lst = [1, 2, 0, 3, 4]
    pmergeme(lst)
    # lst[0] = 4
    assert is_sorted(lst)

    for _ in range(100):
        lst = [random.randrange(1, 100_000) for _ in range(3001)]
        pmergeme(lst)
        assert is_sorted(lst)

    for _ in range(100):
        lst = [random.randrange(1, 100_000) for _ in range(3000)]
        pmergeme(lst)
        assert is_sorted(lst)

    lst = [random.randrange(0, 1000) for _ in range(47)]
    pmergeme(lst)
    assert is_sorted(lst)


# Implementation descriptions:
# https://en.wikipedia.org/wiki/Merge-insertion_sort
# https://youtu.be/wqibJMG42Ik?t=283
# https://www.tldraw.com/v/y9Y2Et7vl18fkPZT4UoEKTW?viewport=-475%2C-20%2C1920%2C2039&page=page%3AjEhR30akJPWN_ZhTL5KgI
#
# Example of the algorithm:
#
# 9 1 2 7 5 8 3 4
# 1 9 2 7 5 8 3 4 # swap
#   ^   ^   ^   ^
# 9 7 8 4
# 7 9 4 8 # swap
#   ^   ^
# 9 8
# 8 9 # swap
#   ^
#
# 9 # push the big element of the only pair when can't recurse any deeper
# 8 9 # insert at index 0 the small element that's paired with the first element of S
# return up
#
# 4 8 9 # insert at index 0 the small element that's paired with the first element of S
#
# 4 7 8 9 # insert small Y3=7 of big X3=9
# return up
#
# 3 4 7 8 9 # insert at index 0 the small element that's paired with the first element of S
#
# 3 4 5 7 8 9 # insert small Y4=5 of big X4=8
# 2 3 4 5 7 8 9 # insert small Y3=2 of big X3=7
# 1 2 3 4 5 7 8 9 # insert small Y5=1 of big X5=9
#
# Transfer S back into X
def pmergeme(lst):
    X = []
    pairs = []

    for value in lst:
        pair = {
            "value": value,
            "index": len(pairs),
            # sys.maxsize is used here to indicate the value being uninitialized
            "small_parent_index": sys.maxsize,
            "big_parent_index": sys.maxsize,
            "depth": 0,
        }

        X.append(pair)
        pairs.append(pair)

    S = []
    merge_insertion_sort(X, S, pairs, 1)

    transfer_sorted(S, lst)


def merge_insertion_sort(X, S, pairs, depth):
    if len(X) == 1:
        S.append(X[0])
        return

    # Create child pairs
    child_pairs = []
    for i in range(1, len(X), 2):
        if X[i - 1]["value"] > X[i]["value"]:
            small_parent = X[i]
            big_parent = X[i - 1]
        else:
            small_parent = X[i - 1]
            big_parent = X[i]

        value = big_parent["value"]

        pair = {
            "value": value,
            "index": len(pairs),
            "small_parent_index": small_parent["index"],
            "big_parent_index": big_parent["index"],
            "depth": depth,
        }

        child_pairs.append(pair)
        pairs.append(pair)

    merge_insertion_sort(child_pairs, S, pairs, depth + 1)

    # Insert at the start of S the element that was paired with the first and smallest element of S
    S.insert(0, pairs[S[0]["small_parent_index"]])

    # Copy S, since we don't want X1, X2, X3, etc. to move around by stuff being inserted in S later
    S_copy = S[:]

    # Insert S_copy Y values at indices 3 -> 2 -> 5 -> 4 -> 11 -> ...
    prev_highest_index = 1
    power_of_two = 4
    while prev_highest_index + 1 < len(S_copy):
        would_be_highest_index = power_of_two - prev_highest_index
        highest_index = min(would_be_highest_index, len(S_copy) - 1)
        index = highest_index

        missing_elements = would_be_highest_index - highest_index
        elements_placed_at_end = 0

        # Insert S_copy Y values at indices 3 -> 2, or 5 -> 4
        while index > prev_highest_index:
            big_parent = S_copy[index]
            while big_parent["depth"] > depth:
                big_parent = pairs[big_parent["big_parent_index"]]

            if subsequence_insertion_sort(
                S,
                power_of_two - 1 - missing_elements - elements_placed_at_end,
                pairs[big_parent["small_parent_index"]],
            ):
                elements_placed_at_end += 1

            index -= 1

        power_of_two <<= 1
        prev_highest_index = highest_index

    # Insert straggler
    if len(X) % 2 == 1:
        subsequence_insertion_sort(S, len(S), X[-1])


# Inserts a pair using a limited binary search
def subsequence_insertion_sort(S, subsequence_len, pair):
    value = pair["value"]

    start = 0
    end = subsequence_len

    while start < end:
        halfway_index = (start + end) // 2
        halfway_pair = S[halfway_index]
        halfway_value = halfway_pair["value"]

        if halfway_value < value:
            start = halfway_index + 1
        else:
            end = halfway_index

    S.insert(start, pair)

    # Return whether the value was placed at the end, so future subsequence lengths can be shorter
    return start == subsequence_len


def transfer_sorted(S, lst):
    for i in range(len(S)):
        lst[i] = S[i]["value"]


def is_sorted(lst):
    for i in range(1, len(lst)):
        if lst[i - 1] > lst[i]:
            return False
    return True


if __name__ == "__main__":
    main()
