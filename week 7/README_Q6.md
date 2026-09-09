# Q6 — The Best Time to Be Alive

## Problem
Given a list of (birth_year, death_year) pairs for prominent scientists,
find the year when the largest number of them were alive at once. If a
death and a birth happen in the same year, the death is considered to
occur first.

## Files
- `q6_best_time_alive.c`

## Algorithm summary
Sweep-line over 2n events: a `+1` event at each birth year, a `-1`
event at each death year. Sort by year, with **deaths sorted before
births on ties** (per the problem's stated convention). Sweep and track
the running count; its maximum (recorded right after a birth event) is
the answer, and the year it first occurs is "the best time to be alive".

## Complexity
O(n log n) time (dominated by sorting 2n events), O(n) space — optimal.

## Build & run
```bash
gcc -O2 -o q6_best_time_alive q6_best_time_alive.c
printf "3\n1900 1950\n1920 1980\n1960 2000\n" | ./q6_best_time_alive
```

## Sample output
```
Maximum number of scientists alive simultaneously = 2
This maximum is first attained in the year = 1920
```

## Tie-break check
```bash
printf "2\n1900 1950\n1950 2000\n" | ./q6_best_time_alive
```
gives max = 1 (not 2), confirming a death and birth in the same year
are correctly treated as non-overlapping.
