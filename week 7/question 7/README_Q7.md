# Q7 — Matrix Chain Multiplication (MCM)

## Problem
Given n matrices A1..An described by dimensions p[0..n] (Ai is
p[i-1]×p[i]), find the minimum number of scalar multiplications needed
to compute the product, and the optimal parenthesisation.

## Files
- `q7_matrix_chain.c`

## Algorithm summary
Classical bottom-up DP:
```
m[i][i] = 0
m[i][j] = min_{i≤k<j} m[i][k] + m[k+1][j] + p[i-1]·p[k]·p[j]
```
`s[i][j]` records the optimal split point k, used to reconstruct the
parenthesisation recursively.

## Complexity
O(n³) time, O(n²) space — the standard, optimal complexity for this DP
formulation.

## Build & run
```bash
gcc -O2 -o q7_matrix_chain q7_matrix_chain.c
printf "6\n30 35 15 5 10 20 25\n" | ./q7_matrix_chain
```

## Sample output
```
Minimum number of scalar multiplications = 15125
Optimal parenthesisation: ((A1(A2A3))((A4A5)A6))
```
This matches the standard CLRS textbook example.
