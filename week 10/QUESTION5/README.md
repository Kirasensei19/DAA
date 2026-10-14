# Question 5: Lexicographically Smallest Connected Component Permutation

## Problem Statement
Given a permutation $A$ of numbers $1 \dots n$, and a list of allowable pairwise swaps $(u, v)$ forming edges in an undirected graph, find the lexicographically smallest permutation achievable through any number of valid swaps. By choosing the proper input representation, write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.

---

## Input Representation
- **$n, m$**: Length of permutation $A$ and number of allowable pairwise swaps.
- Next line: $n$ integers representing permutation $A = [A_1, A_2, \dots, A_n]$.
- Next $m$ lines: Two integers $u$ and $v$ denoting an allowable swap between index $u$ and index $v$ ($1$-indexed).

---

## Approach & Algorithm
1. **Mathematical Property**:
   - The swap operation satisfies the equivalence relation (reflexive, symmetric, and transitive).
   - If index $u$ can be swapped with index $v$, and index $v$ can be swapped with index $w$, then any permutation of the elements located at positions $\{u, v, w\}$ can be reached.
   - Thus, the set of indices partitions into disjoint **connected components** under the swap graph.
2. **Greedy Component Rearrangement**:
   - For each connected component:
     - Collect all index positions belonging to that component: $idx_1 < idx_2 < \dots < idx_k$.
     - Collect the values currently residing at those positions: $val_1, val_2, \dots, val_k$.
     - Sort the values in ascending order: $v_1 \le v_2 \le \dots \le v_k$.
     - Assign the sorted values to the sorted positions:
       $$A[idx_j] = v_j \quad \text{for } j = 1, \dots, k$$
   - Since smaller numbers are placed at earlier index positions throughout every connected component, the resulting overall permutation is strictly the **lexicographically smallest** achievable.

---

## Complexity Analysis
- **Time Complexity:**
  - Initializing DSU: $\mathcal{O}(n)$.
  - Processing $m$ allowable swap pairs: $\mathcal{O}(m \cdot \alpha(n))$.
  - Grouping indices by component root: $\mathcal{O}(n)$.
  - Sorting values within each component: If component sizes are $k_1, k_2, \dots$, then $\sum k_i \log k_i \le \mathcal{O}(n \log n)$.
  - Total Time: $\mathcal{O}(m \cdot \alpha(n) + n \log n)$, which runs in mere milliseconds even for $n = 10^5$.
- **Space Complexity:**
  - DSU arrays (`parent`, `rank`): $\mathcal{O}(n)$.
  - Component linked-list buckets and buffers: $\mathcal{O}(n)$.
  - Total Space: $\mathcal{O}(n + m)$ auxiliary space.

---

## Sample Run
```text
Input:
5 3
4 2 1 5 3
1 3
3 5
2 4

Output:
Lexicographically Smallest Permutation:
1 2 3 5 4
```
