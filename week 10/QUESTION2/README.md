# Question 2: Dynamic Connected Components in a Grid (Number of Islands II)

## Problem Statement
Given an $R \times C$ grid initially completely filled with water, land cells are added one by one at positions $(r_1, c_1), (r_2, c_2), \dots, (r_k, c_k)$. After each operation, output the current number of 4-directionally connected land components (islands). By choosing the proper input representation, write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.

*[Hint: This is the Dynamic Connected Components in a Grid (commonly known as Number of Islands II), which can be solved using a Disjoint Set Union (DSU / Union-Find) data structure with coordinate flattening.]*

---

## Input Representation
- **$R, C$**: Dimensions of the grid ($R$ rows, $C$ columns).
- **$K$**: Number of land operations.
- Followed by $K$ lines, each containing row index $r$ and column index $c$ ($0 \le r < R, 0 \le c < C$).

---

## Approach & Algorithm
1. **Coordinate Flattening**:
   Map each 2D cell $(r, c)$ to a unique 1D index:
   $$\text{flat\_index} = r \times C + c$$
2. **DSU Initialization**:
   - Total elements: $R \times C$.
   - Maintain `is_land[flat_index] = false` initially.
   - Maintain `island_count = 0`.
3. **Dynamic Land Addition at $(r, c)$**:
   - If the cell is already land, skip (count remains unchanged).
   - Otherwise, set `is_land[idx] = true`, initialize `parent[idx] = idx`, `rank[idx] = 0`, and increment `island_count++`.
   - Inspect all 4 orthogonal neighbors: $(r-1, c), (r+1, c), (r, c-1), (r, c+1)$.
   - For every neighbor $(nr, nc)$ within grid boundaries that is already land:
     - Find roots `root_curr = find(idx)` and `root_nbr = find(n_idx)`.
     - If `root_curr != root_nbr`, perform `union(root_curr, root_nbr)` and decrement `island_count--`.
   - Output current `island_count`.

---

## Complexity Analysis
- **Time Complexity:**
  - Initialization of grid and DSU arrays: $\mathcal{O}(R \times C)$.
  - For each of the $K$ operations, at most 4 neighbor checks and at most 4 DSU find/union operations are performed.
  - Each DSU operation with path compression and union by rank runs in $\mathcal{O}(\alpha(R \times C))$ amortized time.
  - Total Time: $\mathcal{O}(R \times C + K \cdot \alpha(R \times C))$, which is linear and optimal.
- **Space Complexity:**
  - Arrays `parent`, `rank`, and `is_land` each have size $R \times C$.
  - Total Space: $\mathcal{O}(R \times C)$ auxiliary space.

---

## Sample Run
```text
Input:
3 3 5
0 0
0 1
1 2
2 2
1 1

Output:
Dynamic Connected Components in Grid (3 x 3):
Total Land Additions: 5

Operation  1: Add land at (0, 0) -> Islands Count = 1
Operation  2: Add land at (0, 1) -> Islands Count = 1
Operation  3: Add land at (1, 2) -> Islands Count = 2
Operation  4: Add land at (2, 2) -> Islands Count = 2
Operation  5: Add land at (1, 1) -> Islands Count = 1
```
