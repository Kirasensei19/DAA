# Q5 — Hitting a Moving Target

## Problem
n hiding spots on a line. An invisible target moves to an adjacent spot
between every two consecutive (blind) shots. Design a shot sequence
that is guaranteed to eventually hit it, or prove none exists.

## Files
- `q5_moving_target.c`

## Algorithm summary
Shoot the sweep sequence:
```
2, 3, 4, ..., n-1, n,  n, n-1, ..., 3, 2      (length 2(n-1))
```
This works because the target's position-parity flips every turn: the
up-sweep tests one parity class, the down-sweep tests the other, so
every possible (start position, movement strategy) pair is covered.

**Verification technique (also useful in general):** track the *set of
positions the target could still occupy*, starting from `{1..n}`.
After each shot, remove that spot, then expand the remaining set by one
step of adjacency. If the set becomes empty, a hit was guaranteed
somewhere in the shots fired so far. The program runs this simulation
and confirms the set always empties out.

## Complexity
Play: O(n) shots, O(1) memory per shot.
Verification simulation: O(n²) time, O(n) space.

## Build & run
```bash
gcc -O2 -o q5_moving_target q5_moving_target.c
echo 10 | ./q5_moving_target
```

## Sample output (n=10)
```
Shot sequence (18 shots): 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2

Result: guaranteed hit proven within 18 shots (out of 18 fired), for n=10.
```
Verified for n = 2..20.
