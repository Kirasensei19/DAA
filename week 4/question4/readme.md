# Application of Sorting-IV

## Problem Statement

A camera at the door tracks the entry time `ai` and exit time `bi` of each person attending a party.

Determine the time at which the maximum number of people are simultaneously present at the party.

The algorithm should run in:

`O(n log n)`

## Approach

1. Store all entry and exit events.
2. Sort the events according to time.
3. Traverse the sorted events.
4. Increase the count when a person enters.
5. Decrease the count when a person exits.
6. Keep track of the maximum number of people present simultaneously.

## Time Complexity

- Sorting events: `O(n log n)`
- Traversing events: `O(n)`

Overall:

`O(n log n)`

## Files

- `solution.c` - C implementation
- `output4.png` - Program output
