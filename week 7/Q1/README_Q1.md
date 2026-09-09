# Q1 — Invert the Coin-Triangle

## Problem
Given an equilateral triangle of side N formed by closely packed coins
(N rows, N(N+1)/2 coins total, coin centres on a triangular lattice),
find the minimum number of single-coin slides needed to flip the
triangle upside down, and give a compact formula.

## Files
- `q1_coin_triangle.c` — main deliverable: computes the formula for a
  given N and prints the actual set of coins that must move.
- `q1_verify.c` — independent brute-force checker: for N = 1..12 it
  searches over *every* placement of the inverted triangle on the
  lattice to find the true maximum overlap, and compares the brute
  force answer against the closed-form formula.

## Algorithm summary
Coins are represented in cube coordinates `(x,y,z)`, `x+y+z=N-1`,
`x,y,z≥0`. A 180° rotation is `(x,y,z)→(-x,-y,-z)`; we may translate
the rotated triangle to maximize overlap with the original. This
reduces to: choose caps `x≤a, y≤b, z≤c` (`a+b+c=2(N-1)`) to minimize
excluded coins `C(N-a,2)+C(N-b,2)+C(N-c,2)`, minimized when the caps
are as equal as possible.

**Formula:** `S=N+2`, `q=⌊S/3⌋`, `r=S mod 3`:
- r=0: `M(N)=3q(q-1)/2`
- r=1: `M(N)=q(3q-1)/2`
- r=2: `M(N)=q(3q+1)/2`

## Complexity
Formula: O(1). Listing moved coins: O(N²) (output size is Θ(N²)).

## Build & run
```bash
gcc -O2 -o q1_coin_triangle q1_coin_triangle.c
echo 4 | ./q1_coin_triangle
```

## Sample output (N=4)
```
Minimum number of coin slides to invert an N=4 triangle: 3
...
Total coins that must move = 3
```
This matches the famous "3 moves to flip a 10-coin triangle" result.

## Validating the formula
```bash
gcc -O2 -o q1_verify q1_verify.c
./q1_verify
```
prints a table comparing brute force vs. formula for N=1..12 — all rows show `OK`.
