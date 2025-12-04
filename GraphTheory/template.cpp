/**********************************************************************************************
->                      @author : a_e_kasem
->   "Code is an art — let logic be your ink and syntax your rhythm."
***********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const int INF = 1e18;

// --- Graph Library Modules ---

namespace Graph {
    // 1. DSU (Disjoint Set Union)
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n + 1); iota(parent.begin(), parent.end(), 0);
            size.assign(n + 1, 1);
        }
        int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }
        bool unite(int x, int y) {
            int rx = find(x), ry = find(y);
            if (rx != ry) {
                if (size[rx] < size[ry]) swap(rx, ry);
                parent[ry] = rx; size[rx] += size[ry]; return true;
            }
            return false;
        }
    };

    // 2. Shortest Path (Dijkstra)
    struct Edge { int to; int weight; };
    vector<int> dijkstra(int n, int start, const vector<vector<Edge>>& adj) {
        vector<int> dist(n + 1, INF);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second; pq.pop();
            if (d > dist[u]) continue;
            for (auto& e : adj[u]) {
                if (dist[u] + e.weight < dist[e.to]) {
                    dist[e.to] = dist[u] + e.weight;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        return dist;
    }
}

using namespace Graph;

void solve() {
    // Write your solution here...
    // Example: DSU dsu(n);
}

int32_t main() {
    fast_io;
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}