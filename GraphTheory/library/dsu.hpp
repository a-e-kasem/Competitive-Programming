#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Graph::DSU
 * @brief Disjoint Set Union (Union-Find) with Path Compression & Union by Size.
 * @note STANDALONE. Time Complexity: O(alpha(N)) ~ O(1).
 */
namespace Graph {
    struct DSU {
        vector<int> parent;
        vector<int> size;
        int components;

        DSU(int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.assign(n + 1, 1);
            components = n;
        }

        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]); // Path Compression
        }

        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                // Union by Size (connect smaller to larger)
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }
            return false;
        }

        bool same(int x, int y) {
            return find(x) == find(y);
        }

        int getSize(int x) {
            return size[find(x)];
        }
    };
}