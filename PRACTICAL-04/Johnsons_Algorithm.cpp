#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Johnson's Algorithm - All Pairs Shortest Path
// Time Complexity: O(V*E log V) with binary heap Dijkstra
// Space Complexity: O(V^2)
// Use Case: Find shortest paths between all pairs in sparse graphs (handles negative weights)

typedef pair<long long, int> pli;

// Main Johnson's Algorithm
void johnsonsAlgorithm(int n, int m, vector<tuple<int, int, long long>>& edges) {
    // Build adjacency list
    vector<vector<pair<int, long long>>> adj(n);
    for (auto& [u, v, w] : edges) {
        adj[u].push_back({v, w});
    }
    
    // Create graph with virtual source (vertex 0 connects to all with weight 0)
    vector<vector<pair<int, long long>>> adj_with_source(n + 1);
    
    // Virtual source (vertex n) connects to all original vertices with weight 0
    for (int i = 0; i < n; i++) {
        adj_with_source[n].push_back({i, 0});
    }
    
    // Copy original edges
    for (int i = 0; i < n; i++) {
        for (auto& [v, w] : adj[i]) {
            adj_with_source[i].push_back({v, w});
        }
    }
    
    // Compute h values using Bellman-Ford from virtual source
    vector<long long> h(n + 1, INF);
    h[n] = 0;  // Virtual source
    
    // Relax edges n times
    for (int i = 0; i < n; i++) {
        for (int u = 0; u <= n; u++) {
            if (h[u] == INF) continue;
            for (auto& [v, w] : adj_with_source[u]) {
                if (h[u] + w < h[v]) {
                    h[v] = h[u] + w;
                }
            }
        }
    }
    
    // Check for negative cycle
    for (int u = 0; u <= n; u++) {
        if (h[u] == INF) continue;
        for (auto& [v, w] : adj_with_source[u]) {
            if (h[u] + w < h[v]) {
                cout << "Negative cycle detected!\n";
                return;
            }
        }
    }
    
    // Run Dijkstra from each vertex with reweighted edges
    vector<vector<long long>> dist(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        dist[i].assign(n, INF);
        dist[i][i] = 0;
        
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, i});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if (d > dist[i][u]) continue;
            
            for (auto& [v, w] : adj[u]) {
                long long newDist = dist[i][u] + w + h[u] - h[v];
                if (newDist < dist[i][v]) {
                    dist[i][v] = newDist;
                    pq.push({dist[i][v], v});
                }
            }
        }
        
        // Convert back to original weights
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != INF) {
                dist[i][j] += h[j] - h[i];
            }
        }
    }
    
    // Print results
    cout << "All Pairs Shortest Paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    vector<tuple<int, int, long long>> edges;
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    johnsonsAlgorithm(n, m, edges);
    
    return 0;
}

/*
EXAMPLE INPUT:
4 5
0 1 5
0 3 10
1 2 3
2 3 1
3 2 -5

EXPECTED OUTPUT:
All Pairs Shortest Paths:
0 5 8 6 
INF 0 3 1 
INF INF 0 -4 
INF INF -5 0 
*/
