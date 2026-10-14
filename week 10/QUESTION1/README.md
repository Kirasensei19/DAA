# Question 1: Online Graph-Bipartiteness Testing

## Problem Statement
A graph is bipartite if and only if it contains no odd-length cycles. Given an undirected graph with $V$ vertices, edges arrive online one by one. Maintain whether the graph remains bipartite. If adding an edge $(u, v)$ does not introduce an odd cycle, add it; otherwise, report that it violates bipartiteness and skip it. By choosing the proper input representation, write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.

---

## Input Representation
- **$V$**: Number of vertices ($1 \dots V$)
- **$E$**: Number of arriving edges
- Followed by $E$ lines, each containing two integers $u$ and $v$ denoting an incoming edge $(u, v)$.

---

## Approach & Algorithm
We maintain a **Disjoint Set Union (DSU) with 2-Coloring Parity (Potential DSU)**:
1. For each vertex $v$, we maintain:
   - `parent[v]`: Parent pointer in the DSU tree.
   - `parity[v]`: Parity of the path distance (modulo 2) from vertex $v$ to `parent[v]`.
     - `0`: vertex has the same color / set as its parent.
     - `1`: vertex has the opposite color / set as its parent.
2. **Find with Path Compression**:
   When compressing paths, `parity[v]` is updated recursively:
   $$\text{parity}[v] \leftarrow \text{parity}[v] \oplus \text{parity}[\text{old\_parent}]$$
3. **Adding Edge $(u, v)$**:
   - Compute `root_u = find(u)` and `root_v = find(v)`.
   - **Case 1: $root_u == root_v$ (Same Component)**
     - If $\text{parity}[u] == \text{parity}[v]$, connecting $u$ and $v$ forms an **odd-length cycle**. Bipartiteness is violated $\implies$ **REJECT/SKIP edge**.
     - If $\text{parity}[u] \neq \text{parity}[v]$, an **even-length cycle** is formed, which preserves bipartiteness $\implies$ **ACCEPT edge**.
   - **Case 2: $root_u \neq root_v$ (Different Components)**
     - Connecting two previously disconnected components cannot create a cycle.
     - Union the two components using union by rank.
     - Set the relative parity of the merged root:
       $$\text{parity}[root_v] = \text{parity}[u] \oplus \text{parity}[v] \oplus 1$$
     - **ACCEPT edge**.

---

## Complexity Analysis
- **Time Complexity:**
  - Initializing DSU: $\mathcal{O}(V)$.
  - Each edge query and union operation uses path compression and union by rank, running in $\mathcal{O}(\alpha(V))$ amortized time, where $\alpha$ is the inverse Ackermann function ($\alpha(V) \le 4$ for all practical $V$).
  - Total Time for $E$ edges: $\mathcal{O}(V + E \cdot \alpha(V)) \approx \mathcal{O}(V + E)$ (nearly linear time).
- **Space Complexity:**
  - Arrays `parent`, `parity`, and `rank` each require size $V + 1$.
  - Total Space: $\mathcal{O}(V)$ auxiliary space.

---

## Sample Run
```text
Input:
5 6
1 2
2 3
3 4
4 5
1 5
1 4

Output:
Online Graph-Bipartiteness Testing:
Total Vertices: 5, Total Arriving Edges: 6

Edge 1: (1, 2) -> ADDED (Graph remains bipartite)
Edge 2: (2, 3) -> ADDED (Graph remains bipartite)
Edge 3: (3, 4) -> ADDED (Graph remains bipartite)
Edge 4: (4, 5) -> ADDED (Graph remains bipartite)
Edge 5: (1, 5) -> REJECTED (Violates bipartiteness: odd cycle detected)
Edge 6: (1, 4) -> ADDED (Graph remains bipartite)
```
