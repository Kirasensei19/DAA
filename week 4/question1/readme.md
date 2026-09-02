# Application of Sorting-I

## Problem Statement

Assume that we are given `n` pairs of items as input, where the first item is a number and the second item is one of the colours:

- Red
- Blue
- Yellow

The items are sorted according to their numerical value. Give an `O(n)` algorithm to sort the items by colour such that:

1. All red items appear first.
2. All blue items appear next.
3. All yellow items appear last.
4. The numerical order within each colour remains unchanged.

## Approach

Since there are only three colours, the input can be scanned once and the elements can be placed into separate groups for Red, Blue, and Yellow.

Finally, concatenate the three groups in the required order.

## Time Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`

## Files

- `solution.c` - C implementation
- `output1.png` - Program output
