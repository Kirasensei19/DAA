# Application of Sorting-VI

## Problem Statement

Given a set `S` of `n` intervals on a line, where each interval is represented by its left and right endpoints `(li, ri)`, identify a point `p` that belongs to the maximum number of intervals.

An endpoint is considered part of its interval.

Example:

S = {(10,40), (20,60), (50,90), (15,70)}

A valid point is:

`p = 50`

because it belongs to three intervals.

## Approach

A sweep line algorithm is used.

1. Create two events for every interval:
   - Start point: `+1`
   - End point: `-1`
2. Sort all events according to their position.
3. If multiple events occur at the same point, process starting events before ending events because endpoints are included.
4. Traverse the events while maintaining the number of active intervals.
5. Store the point where the maximum overlap occurs.

## Time Complexity

- Sorting events: `O(n log n)`
- Traversing events: `O(n)`

Overall:

`O(n log n)`

## Files

- `solution.c` - C implementation
- `output6.png` - Program output
