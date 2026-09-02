# DAA Lab - Question 2
## 2D Square Matrix Operations and Their Complexities

### Problem
Given square matrices of size `n × n`, determine the worst-case complexity of:

1. Matrix Addition
2. Matrix Multiplication
3. Checking Zero Matrix
4. Checking Symmetric Matrix
5. Computing Determinant
6. In-place Transpose
7. Finding Eigenvalues and Eigenvectors

### Complexity

| Operation | Worst Case |
|---|---|
| Matrix Addition | O(n²) |
| Matrix Multiplication | O(n³) |
| Zero Matrix Check | O(n²) |
| Symmetric Matrix Check | O(n²) |
| Determinant | O(n!) |
| In-place Transpose | O(n²) |
| Eigenvalues and Eigenvectors | O(n³) |

### Approach

The matrices are represented using two-dimensional arrays.

Matrix addition requires visiting every element, giving `O(n²)` complexity. Matrix multiplication uses three nested loops, resulting in `O(n³)` complexity. Symmetry and zero-matrix checks require at most `O(n²)` comparisons.

The determinant is calculated using recursive cofactor expansion.

### Conclusion

The experiment demonstrates the computational complexity of common operations on square matrices.