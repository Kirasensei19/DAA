# Application of Sorting-II

## Problem Statement

Given two sets `S1` and `S2`, each containing `n` elements, and a number `x`, determine whether there exists a pair of elements, one from `S1` and one from `S2`, such that:

S1[i] + S2[j] = x

The algorithm should run in `O(n log n)` time.

## Approach

1. Sort one of the sets.
2. For every element in the other set, calculate the required value:

   required = x - current_element

3. Use binary search to check whether the required value exists in the sorted set.

## Time Complexity

- Sorting: `O(n log n)`
- Binary searches: `O(n log n)`
- Overall: `O(n log n)`

## Files

- `solution.c` - C implementation
- `output2.png` - Program output
