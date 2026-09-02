
---

### `README_Q2.md`
```markdown
# DAA Lab-5 — Q2
## Find Kth Smallest Element Without Sorting

### Problem Statement
Find the Kth smallest element in a given list of N numbers without sorting the list.

### Algorithm Used
Quickselect algorithm.

### Working
1. Select a pivot element.
2. Partition the array around the pivot.
3. Find the position of the pivot.
4. If the pivot is at position `K-1`, it is the Kth smallest element.
5. If the required position is smaller, search the left part.
6. If the required position is larger, search the right part.
7. Continue until the Kth smallest element is found.

### Example

Input:
```text
7 2 9 4 1
K = 3