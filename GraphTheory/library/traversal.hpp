#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Graph::Traversal
 * @brief Bipartite Check, Cycle Detection, Topological Sort.
 * @note STANDALONE.
 */
namespace Graph {
    namespace Traversal {
        
        /**
         * @brief Checks if a graph is Bipartite (2-Colorable).
         * @return true if bipartite, false otherwise.
         */
        bool isBipartite(int n, const vector<vector<int>>& adj) {
            vector<int> color(n + 1, -1);
            for (int i = 1; i <= n; i++) {
                if (color[i] != -1) continue;
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        /**
         * @brief Topological Sort (Kahn's Algorithm).
         * @return Vector of nodes in topological order. Empty if cycle exists.
         */
        vector<int> topologicalSort(int n, const vector<vector<int>>& adj) {
            vector<int> in_degree(n + 1, 0);
            for (int u = 1; u <= n; u++) {
                for (int v : adj[u]) in_degree[v]++;
            }

            queue<int> q;
            for (int i = 1; i <= n; i++) {
                if (in_degree[i] == 0) q.push(i);
            }

            vector<int> result;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                result.push_back(u);

                for (int v : adj[u]) {
                    in_degree[v]--;
                    if (in_degree[v] == 0) q.push(v);
                }
            }

            if (result.size() != n) return {}; // Cycle detected
            return result;
        }
    }
}