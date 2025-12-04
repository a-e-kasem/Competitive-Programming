#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Graph::ShortestPath
 * @brief Dijkstra, Floyd-Warshall, Bellman-Ford.
 * @note STANDALONE.
 */
namespace Graph {
    namespace ShortestPath {
        using ll = long long;
        const ll INF = 1e18;

        struct Edge {
            int to;
            ll weight;
        };

        /**
         * @brief Dijkstra's Algorithm (O(E log V)).
         * @return Vector of distances from start_node.
         */
        vector<ll> dijkstra(int n, int start_node, const vector<vector<Edge>>& adj) {
            vector<ll> dist(n + 1, INF);
            dist[start_node] = 0;
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
            pq.push({0, start_node});

            while (!pq.empty()) {
                ll d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (d > dist[u]) continue;

                for (const auto& edge : adj[u]) {
                    if (dist[u] + edge.weight < dist[edge.to]) {
                        dist[edge.to] = dist[u] + edge.weight;
                        pq.push({dist[edge.to], edge.to});
                    }
                }
            }
            return dist;
        }

        /**
         * @brief Floyd-Warshall Algorithm (O(V^3)).
         * @details Computes shortest paths between ALL pairs.
         * @param adjMatrix n x n matrix where adj[i][j] = weight (or INF).
         */
        void floydWarshall(int n, vector<vector<ll>>& dist) {
            for (int k = 1; k <= n; ++k) {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (dist[i][k] < INF && dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
}