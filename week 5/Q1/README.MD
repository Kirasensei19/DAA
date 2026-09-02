# DAA Lab-5 — Q1
## Find Median Without Sorting

### Problem Statement
Find the median of a list of N numbers without sorting the list.

### Algorithm Used
Quickselect algorithm.

Quickselect uses the partitioning technique of Quick Sort but searches only the required half instead of sorting the complete array.

### Working
1. Select a pivot.
2. Partition the array around the pivot.
3. Find the position of the pivot.
4. If it is the required middle position, return it.
5. Otherwise, recursively search only the required part.
6. For an even number of elements, find the two middle elements and take their average.

### Example

Input:
```text
7 2 9 4 1