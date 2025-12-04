# 🕸️ Ultimate Graph Library

A standalone, modular C++ library for Graph Theory algorithms in Competitive Programming.

##  Modules
| File | Namespace | Description |
| :--- | :--- | :--- |
| [`dsu.hpp`](library/dsu.hpp) | `Graph::DSU` | **Disjoint Set Union** with Path Compression & Union by Size. |
| [`shortest_path.hpp`](library/shortest_path.hpp) | `Graph::ShortestPath` | **Dijkstra** (Sparse) and **Floyd-Warshall** (Dense). |
| [`mst.hpp`](library/mst.hpp) | `Graph::MST` | **Kruskal's Algorithm** for Minimum Spanning Tree. |
| [`traversal.hpp`](library/traversal.hpp) | `Graph::Traversal` | Bipartite Check (2-Coloring), Topological Sort. |
| [`tree.hpp`](library/tree.hpp) | `Graph::Tree` | Tree Diameter (Double BFS). |

## 🛠 Usage
All files are standalone. Copy the specific logic you need.

### Example: DSU
```cpp
Graph::DSU dsu(n);
if (dsu.unite(u, v)) {
    // Edge added successfully
}