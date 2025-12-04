#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Graph::MST
 * @brief Kruskal's Algorithm.
 * @note STANDALONE: Includes internal DSU.
 */
namespace Graph {
    namespace MST {
        using ll = long long;

        struct Edge {
            int u, v;
            ll weight;
            bool operator<(const Edge& other) const {
                return weight < other.weight;
            }
        };

        // Internal DSU for Kruskal
        struct DSU {
            vector<int> parent;
            DSU(int n) {
                parent.resize(n + 1);
                iota(parent.begin(), parent.end(), 0);
            }
            int find(int x) {
                return (x == parent[x]) ? x : parent[x] = find(parent[x]);
            }
            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX != rootY) {
                    parent[rootY] = rootX;
                    return true;
                }
                return false;
            }
        };

        /**
         * @brief Kruskal's Algorithm (O(E log E)).
         * @return pair<Total Weight, List of Edges in MST>
         */
        pair<ll, vector<Edge>> kruskal(int n, vector<Edge>& edges) {
            sort(edges.begin(), edges.end());
            DSU dsu(n);
            ll mst_weight = 0;
            vector<Edge> mst_edges;

            for (const auto& edge : edges) {
                if (dsu.unite(edge.u, edge.v)) {
                    mst_weight += edge.weight;
                    mst_edges.push_back(edge);
                }
            }
            return {mst_weight, mst_edges};
        }
    }
}