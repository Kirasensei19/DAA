# Application of Sorting-V

## Problem Statement

Given a list of `n` intervals represented as `(xi, yi)`, merge all overlapping intervals.

Example:

Input:

{(1,3), (2,6), (8,10), (7,18)}

Output:

{(1,6), (7,18)}

The algorithm should run in:

`O(n log n)`

## Approach

1. Sort all intervals according to their starting point.
2. Start with the first interval.
3. Compare each interval with the previous merged interval.
4. If they overlap, merge them.
5. Otherwise, add the interval to the result.

## Time Complexity

- Sorting: `O(n log n)`
- Merging: `O(n)`

Overall:

`O(n log n)`

## Files

- `solution.c` - C implementation
- `output5.png` - Program output
