# Question 4: Reverse Time-Step DSU Application (Sequential Vertex Deletion)

## Problem Statement
Given a vertex-weighted undirected graph, vertices are sequentially deleted one by one in an order $P = [p_1, p_2, \dots, p_V]$. After each vertex deletion, compute the maximum sum of vertex values among all remaining connected components. Note that deleting a vertex in a graph means removing that specific vertex and all edges connected (incident) to it from the graph structure. By choosing the proper input representation, write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.

---

## Input Representation
- **$V, E$**: Number of vertices and number of edges.
- Next line: $V$ integers $w_1, w_2, \dots, w_V$ representing vertex weights.
- Next $E$ lines: Two integers $u$ and $v$ denoting undirected edges in the initial graph.
- Final line: $V$ integers $p_1, p_2, \dots, p_V$ denoting the sequential deletion order.

---

## Approach & Algorithm
1. **Reverse-Time DSU Strategy**:
   - DSU supports merging sets efficiently, but does not support splitting sets when a vertex is deleted.
   - Deleting vertices in forward sequence $p_1, p_2, \dots, p_V$ is mathematically equivalent to **adding vertices in reverse order**:
     $$p_V, p_{V-1}, \dots, p_1$$
   - Starting with an empty graph:
     - At step $i$ ($i = V$ down to 1):
       - Before activating $p_i$, the graph state corresponds exactly to the state **after** deleting $p_i$.
       - Hence, $\text{ans}[i] = \text{current\_max}$ (for $i = V$, $\text{ans}[V] = 0$).
       - Now activate vertex $u = p_i$:
         - Set `active[u] = true`.
         - Initialize `parent[u] = u`, `comp_weight[u] = w[u]`.
         - Update $\text{current\_max} = \max(\text{current\_max}, w[u])$.
       - Traverse all incident edges $(u, v)$ from the graph's adjacency list:
         - If neighbor $v$ is already active (`active[v] == true`):
           - Union components of $u$ and $v$ in DSU.
           - Add component weights: $\text{comp\_weight}[root_u] += \text{comp\_weight}[root_v]$.
           - Update $\text{current\_max} = \max(\text{current\_max}, \text{comp\_weight}[root_u])$.
2. **Output**:
   - Output the recorded answers in forward chronological order: $\text{ans}[1], \text{ans}[2], \dots, \text{ans}[V]$.

---

## Complexity Analysis
- **Time Complexity:**
  - Building adjacency list: $\mathcal{O}(V + E)$.
  - Reverse addition: Each vertex is activated once ($\mathcal{O}(V)$).
  - Each undirected edge is inspected at most twice (once from each endpoint).
  - Total DSU operations: at most $2E$ find/union calls, each running in $\mathcal{O}(\alpha(V))$.
  - Total Time: $\mathcal{O}((V + E) \cdot \alpha(V)) \approx \mathcal{O}(V + E)$ (strictly linear time).
- **Space Complexity:**
  - Adjacency list: $2E$ nodes $\implies \mathcal{O}(V + E)$.
  - DSU arrays (`parent`, `rank`, `comp_weight`, `active`): $\mathcal{O}(V)$.
  - Answer array `ans`: $\mathcal{O}(V)$.
  - Total Space: $\mathcal{O}(V + E)$ auxiliary space.

---

## Sample Run
```text
Input:
5 6
1 2 3 4 5
1 2
2 3
3 1
3 4
4 5
5 3
3 5 4 1 2

Output:
Reverse Time-Step DSU: Sequential Vertex Deletion
Total Vertices: 5, Total Edges: 6

After deleting vertex 3: Max Component Sum = 9
After deleting vertex 5: Max Component Sum = 4
After deleting vertex 4: Max Component Sum = 3
After deleting vertex 1: Max Component Sum = 2
After deleting vertex 2: Max Component Sum = 0
```
