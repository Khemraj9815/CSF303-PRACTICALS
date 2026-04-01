# PRACTICAL-04
---

## 1. Floyd Warshall Algorithm

### Overview
Floyd Warshall is an **All-Pairs Shortest Path algorithm** that finds the shortest distance between every pair of vertices in a weighted graph.

### Algorithm Steps:
1. Initialize distance matrix with direct edge weights
2. Distance from a vertex to itself = 0
3. For each intermediate vertex k:
   - For each pair of vertices (i, j):
     - Update: dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

### Time & Space Complexity:
- **Time**: O(V³) - Three nested loops
- **Space**: O(V²) - Distance matrix

### Advantages:
- Simple to understand and implement
- Can detect negative cycles
- Good for dense graphs
- Works with negative weights (if no negative cycles)

### Disadvantages:
- Very slow for large graphs (cubic complexity)
- Uses O(V²) space
- Not practical for graphs with thousands of vertices

### When to Use:
- Small graphs (V < 500)
- Need all-pairs shortest paths
- Graph has negative weights but no negative cycles
- Dense graphs where precomputation is okay

---

## 2. Johnson's Algorithm

### Overview
Johnson's Algorithm solves the **All-Pairs Shortest Path problem** more efficiently than Floyd Warshall for sparse graphs. It cleverly handles negative weights using graph reweighting.

### Algorithm Steps:
1. **Add a virtual source vertex** connected to all vertices with 0 weight edge
2. **Run Bellman-Ford** from virtual source to compute h values (for reweighting)
3. **Reweight edges** using formula: w'(u,v) = w(u,v) + h(u) - h(v)
4. **Run Dijkstra** from each vertex on reweighted graph
5. **Convert back** to original weights

### Time & Space Complexity:
- **Time**: O(V*E*log V) with binary heap Dijkstra, O(V*E) with Fibonacci heap
- **Space**: O(V + E)

### Advantages:
- Much faster than Floyd Warshall for sparse graphs
- Handles negative weights (no negative cycles)
- Better for sparse graphs where E << V²
- Asymptotically better than Floyd Warshall

### Disadvantages:
- More complex to implement
- Constant factors are larger
- Slower than Floyd Warshall for very dense graphs
- Still doesn't handle negative cycles

### When to Use:
- Large sparse graphs
- Need all-pairs shortest paths with negative weights
- E is much smaller than V²
- Real-world networks and road networks


---

## 3. Boruvka's Algorithm

### Overview
Boruvka's Algorithm finds the **Minimum Spanning Tree (MST)** of a weighted undirected graph. It's useful for graphs that might be disconnected.

### Algorithm Steps:
1. Start with each vertex as a separate component
2. **Repeat until one component remains:**
   - For each component, find the minimum weight edge going to another component
   - Add all these edges to the MST (union the components)

### Time & Space Complexity:
- **Time**: O(E*log²V) or O(E*log V) with optimizations
- **Space**: O(V + E)

### Advantages:
- Works with disconnected graphs (finds MST for each component)
- Naturally parallelizable (can process components independently)
- Good for distributed systems
- Works with both directed and undirected graphs (with modifications)
- Faster than Kruskal's for certain graph types

### Disadvantages:
- More complex than Kruskal's or Prim's
- Requires Union-Find data structure
- Not as commonly used as Kruskal's/Prim's
- Similar time complexity to Kruskal's in practice

### When to Use:
- Distributed computing environments (parallel processing)
- Graphs with many components
- Need to process graph in layers/phases
- Dense graphs where Kruskal's might be slower

---
## Learning Outcomes

1. **Algorithm Design Patterns:**
   - **Dynamic Programming**: Floyd Warshall uses DP by building up solutions through intermediate vertices
   - **Graph Reweighting**: Johnson's algorithm teaches how to transform problems (negative weights → positive)
   - **Greedy Approach**: Boruvka's uses greedy strategy to build MST incrementally

2. **Data Structures:**
   - Adjacency lists for sparse graphs
   - Distance/Cost matrices
   - Union-Find data structure for efficient component tracking
   - Priority queues for Dijkstra's algorithm
   - Hash maps for tracking minimum edges per component

3. **Trade-offs in Computing:**
   - **Time vs Space**: Floyd Warshall trades space (O(V²)) for simplicity
   - **Complexity vs Practicality**: Johnson's is theoretically better but Floyd Warshall is simpler for small graphs
   - **Generality vs Efficiency**: Algorithms choosing different approaches based on graph properties

4. **Handling Edge Cases:**
   - Negative cycles detection in Floyd Warshall
   - Graph reweighting without changing shortest paths in Johnson's
   - Disconnected components in Boruvka's (counts and handles separately)
   - Multiple edges between same vertices (handled with min function)
