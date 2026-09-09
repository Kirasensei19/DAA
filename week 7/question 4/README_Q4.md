# Q4 — Security Switches

## Problem
n switches, all initially ON. Rightmost switch toggles freely; switch i
(i<n) can only be toggled if switch i+1 is ON and all switches to the
right of i+1 are OFF. Turn all switches OFF in the minimum number of moves.

## Files
- `q4_security_switches.c`

## Algorithm summary
This is structurally the classical **Chinese-Rings / Baguenaudier
puzzle** — the naive guess of "2ⁿ-1 like Hanoi" is WRONG. Let `R(k)` be
the cost to move a k-switch suffix between all-off and
(front-on, rest-off) (same in both directions by symmetry of the
enabling rule): `R(k) = 2R(k-1)+1 = 2^k - 1`. Then, for turning a whole
suffix off from all-on:
```
D(k) = D(k-2) + 1 + R(k-1) = D(k-2) + 2^(k-1),   D(0)=0, D(1)=1
```
Closed form:
```
n even: D(n) = (2^(n+1) - 2) / 3
n odd:  D(n) = (2^(n+1) - 1) / 3
```
giving 1, 2, 5, 10, 21, 42, 85, 170, 341, 682, ... for n=1,2,3,...

The program also implements a matching recursive move generator
(`D_off`, `set_on_front`, `clear_from_front`) and checks every move's
legality live against the puzzle's rule (ii).

## Complexity
D(n) = Θ(2ⁿ) moves, necessary and sufficient. Generating/validating
the sequence: O(2ⁿ) time, O(n) recursion depth.

## Build & run
```bash
gcc -O2 -o q4_security_switches q4_security_switches.c
echo 10 | ./q4_security_switches
```

## Sample output (n=10)
```
All switches off: yes
Moves used = 682, closed-form formula = 682 -> OK
```
Verified for n = 1..20, all moves confirmed legal.
