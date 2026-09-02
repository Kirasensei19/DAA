# Application of Sorting-III

## Problem Statement

Given a set `S` of `n` integers and an integer `T`, determine whether `k` integers in `S` add up to `T`.

The required time complexity is:

O(n^(k-1) log n)

## Approach

1. Sort the array.
2. Select `k - 1` elements recursively.
3. Calculate the remaining value needed to reach `T`.
4. Use binary search to check whether the remaining value exists in the array.

## Time Complexity

- Sorting: `O(n log n)`
- Selecting `k - 1` elements: `O(n^(k-1))`
- Binary search for each selection: `O(log n)`

Overall complexity:

`O(n^(k-1) log n)`

## Files

- `solution.c` - C implementation
- `output3.png` - Program output
