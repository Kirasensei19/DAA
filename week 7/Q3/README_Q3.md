# Q3 — Reve's Puzzle (4-peg Tower of Hanoi)

## Problem
8 disks, 4 pegs, standard Hanoi movement rules. Solve in 33 moves, and
generalize to n disks.

## Files
- `q3_reves_puzzle.c`

## Algorithm summary — Frame–Stewart
Pick a split point k (1≤k<n):
1. Move the top k disks to a spare peg using all 4 pegs (recursive).
2. Move the remaining n-k disks with the classical 3-peg algorithm
   (2^(n-k)-1 moves) — the 4th peg is occupied by the k parked disks.
3. Move the k disks back onto the destination using all 4 pegs (recursive).

```
T4(n) = min_{1≤k<n} [ 2·T4(k) + 2^(n-k) - 1 ],  T4(0) = 0
```
The DP tries every split k for every i to find the optimum.

## Complexity
DP for T4(1..n): O(n²) time, O(n) space.
Move generation/printing: O(T4(n)) — sub-exponential in practice,
far below the 2ⁿ-1 of the 3-peg case.

## Build & run
```bash
gcc -O2 -o q3_reves_puzzle q3_reves_puzzle.c
echo 8 | ./q3_reves_puzzle
```

## Sample output (n=8)
```
T4( 8) = 33

For n = 8, Reve's puzzle minimum moves = 33  (classic answer: 33, MATCH)

Generating and verifying the explicit move sequence for n = 8:
Total moves generated = 33  (expected T4(8) = 33) -> OK
```
For n≤6 the program also prints the full move-by-move sequence.
