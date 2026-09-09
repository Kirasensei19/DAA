# Q2 — Super Egg Testing Experiment

## Problem
Given E identical eggs and an F-storey building, find the minimum
number of droppings guaranteed to determine the highest safe floor in
all cases. Generalize for any E, F (not just E=2, F=100).

## Files
- `q2_egg_drop.c`

## Algorithm summary
DP on the **dual** quantity `f[t][k]` = maximum number of floors
resolvable using `t` trials and `k` eggs:
```
f[t][k] = f[t-1][k-1] + f[t-1][k] + 1,   f[0][k] = 0
```
The answer is the smallest `t` such that `f[t][E] ≥ F`. This is much
more efficient than the textbook O(E·F²) `dp[eggs][floors]` DP.

## Complexity
O(E·T*) time and space, where T* is the answer (grows like F^(1/E)).

## Build & run
```bash
gcc -O2 -o q2_egg_drop q2_egg_drop.c
echo "2 100" | ./q2_egg_drop
```

## Sample output
```
Enter number of eggs E and number of floors F:
Minimum number of droppings guaranteed to find the critical
floor with 2 egg(s) and 100 floor(s): 14
(Matches the well-known textbook answer: 14.)
```

Also verified: E=1,F=100 → 100 (must go floor by floor); E=3,F=1000 → 19.
