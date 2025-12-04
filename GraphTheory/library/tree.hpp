#pragma once
#include <bits/stdc++.h>
using namespace std;

/**
 * @namespace Graph::Tree
 * @brief Tree specific algorithms (Diameter, etc).
 * @note STANDALONE.
 */
namespace Graph {
    namespace Tree {
        
        // Helper BFS for diameter
        void bfs_dist(int start, int n, const vector<vector<int>>& adj, vector<int>& dist, int& farthest_node) {
            fill(dist.begin(), dist.end(), -1);
            dist[start] = 0;
            queue<int> q;
            q.push(start);
            farthest_node = start;
            int max_dist = 0;

            while(!q.empty()){
                int u = q.front(); q.pop();
                if(dist[u] > max_dist){
                    max_dist = dist[u];
                    farthest_node = u;
                }
                for(int v : adj[u]){
                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        /**
         * @brief Calculates Tree Diameter (Longest path between any two nodes).
         * @return The diameter length.
         */
        int getDiameter(int n, const vector<vector<int>>& adj) {
            if (n == 0) return 0;
            vector<int> dist(n + 1);
            int nodeU, nodeV;
            // 1st BFS to find farthest node from an arbitrary node (say 1)
            bfs_dist(1, n, adj, dist, nodeU);
            // 2nd BFS from nodeU to find the actual diameter end nodeV
            bfs_dist(nodeU, n, adj, dist, nodeV);
            return dist[nodeV];
        }
    }
}