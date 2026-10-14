# Question 3: Maximum Weight Component with Size Constraints

## Problem Statement
Given a graph where each vertex $v$ has weight $w_v$, edges are added sequentially with weights. At any point, compute the maximum total vertex weight of any connected component whose size does not exceed a threshold $K$. By choosing the proper input representation, write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.

---

## Input Representation
- **$V, E, K$**: Number of vertices, number of edges added sequentially, and maximum component size threshold $K$.
- Next line: $V$ integers $w_1, w_2, \dots, w_V$ representing the vertex weights.
- Next $E$ lines: Three integers $u, v, wt$ representing the arriving undirected edge between $u$ and $v$ with weight $wt$.

---

## Approach & Algorithm
1. **Disjoint Set Union (DSU) with Component Attributes**:
   - Each component root $r$ tracks:
     - `size[r]`: Number of vertices in the component.
     - `comp_weight[r]`: Total sum of vertex weights in the component.
   - When merging two components with roots $r_1$ and $r_2$:
     - Size becomes $\text{size}[r_1] + \text{size}[r_2]$.
     - Weight becomes $\text{comp\_weight}[r_1] + \text{comp\_weight}[r_2]$.
2. **Max-Heap with Lazy Deletion**:
   - We maintain a binary max-heap of candidate pairs `(weight, root)`.
   - Initially, all vertices with $\text{size} \le K$ (which is all vertices if $K \ge 1$) are pushed to the heap.
   - When an edge merges two components:
     - The new merged root and its combined weight are pushed to the heap **if** the new size $\le K$.
   - **Querying Current Maximum**:
     - Repeatedly peek at the top of the max-heap.
     - Validate the top element:
       - Is `root` still an active component root (`find(root) == root`)?
       - Does `comp_weight[root]` still match the heap recorded weight?
       - Is `size[root] <= K`?
     - If all conditions hold, the top element is the exact current maximum weight!
     - If any condition fails, pop and discard the stale entry.
     - If the heap becomes empty, no connected component currently satisfies $\text{size} \le K$.

---

## Complexity Analysis
- **Time Complexity:**
  - Initial heap insertion: $\mathcal{O}(V \log V)$.
  - Each edge addition performs DSU union in $\mathcal{O}(\alpha(V))$ and at most one heap push in $\mathcal{O}(\log V)$.
  - Max-weight queries: Each pushed element is extracted at most once, taking amortized $\mathcal{O}(\log(V + E))$ time.
  - Total Time: $\mathcal{O}((V + E) \log(V + E))$, which scales effortlessly to large graphs.
- **Space Complexity:**
  - DSU arrays (`parent`, `size`, `comp_weight`): $\mathcal{O}(V)$.
  - Max-Heap buffer: $\mathcal{O}(V + E)$.
  - Total Space: $\mathcal{O}(V + E)$ auxiliary space.

---

## Sample Run
```text
Input:
5 4 3
10 20 30 40 50
1 2 5
2 3 7
4 5 3
3 4 8

Output:
Maximum Weight Component with Size Constraint (Threshold K = 3):
Initial State (0 edges): Max Weight (size <= 3) = 50
Step  1: Add Edge (1, 2, wt=5) -> Max Weight (size <= 3) = 50
Step  2: Add Edge (2, 3, wt=7) -> Max Weight (size <= 3) = 60
Step  3: Add Edge (4, 5, wt=3) -> Max Weight (size <= 3) = 90
Step  4: Add Edge (3, 4, wt=8) -> No component with size <= 3
```
