
---

### `README_Q3.md`
```markdown
# DAA Lab-5 — Q3
## Quick Sort of N Random Elements Stored in a File

### Problem Statement
Implement Quick Sort to sort N randomly generated elements stored in a file.

### Algorithm Used
Quick Sort.

### Working
1. Read the number of elements `N`.
2. Generate N random integers.
3. Store the random integers in `numbers.txt`.
4. Read the elements from the file.
5. Select a pivot element.
6. Partition the array around the pivot.
7. Recursively apply Quick Sort to the left and right parts.
8. Display the sorted elements.

### Example Output

```text
Enter number of elements: 6

Random elements:
43 12 87 25 6 51

Sorted elements:
6 12 25 43 51 87