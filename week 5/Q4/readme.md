
---

### `README_Q4.md`
```markdown
# DAA Lab-5 — Q4
## Heap Sort of N Randomly Generated Elements Stored in a File

### Problem Statement
Implement Heap Sort to sort N randomly generated elements stored in a file and analyze the complexity.

### Algorithm Used
Heap Sort using a Max Heap.

### Working
1. Read the number of elements `N`.
2. Generate N random integers.
3. Store the elements in `numbers.txt`.
4. Read the elements from the file.
5. Build a Max Heap.
6. The largest element is present at the root.
7. Swap the root with the last element.
8. Reduce the heap size.
9. Apply heapify to restore the Max Heap.
10. Repeat until the array is sorted.

### Example Output

```text
Enter number of elements: 6

Random elements:
72 15 91 34 8 56

Sorted elements:
8 15 34 56 72 91