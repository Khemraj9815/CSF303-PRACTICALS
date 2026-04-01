#include <bits/stdc++.h>
using namespace std;

// Boruvka's Algorithm - Minimum Spanning Tree
// Time Complexity: O(E log^2 V) or O(E log V) with union-find optimizations
// Space Complexity: O(V + E)
// Use Case: Find the minimum spanning tree, works with disconnected graphs

struct Edge {
    int u, v;
    long long weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return false;  // Already in same set
        
        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

struct BoruvakaResult {
    vector<Edge> mstEdges;
    long long totalWeight;
    int components;
};

BoruvakaResult boruvka(int n, vector<Edge>& edges) {
    BoruvakaResult result;
    result.totalWeight = 0;
    result.components = n;
    
    UnionFind uf(n);
    vector<Edge> mstEdges;
    
    // Repeat until we have only one component
    while (uf.find(0) != uf.find(n - 1) || result.components > 1) {
        result.components = 0;
        vector<bool> visited(n, false);
        
        // Count components
        for (int i = 0; i < n; i++) {
            if (!visited[uf.find(i)]) {
                visited[uf.find(i)] = true;
                result.components++;
            }
        }
        
        if (result.components == 1) break;
        
        // For each component, find the minimum weight edge going out
        map<int, Edge> minEdge;  // minEdge[component] = cheapest edge leaving component
        
        for (auto& edge : edges) {
            int comp1 = uf.find(edge.u);
            int comp2 = uf.find(edge.v);
            
            if (comp1 == comp2) continue;  // Edge within component
            
            // Track minimum edge for each component
            if (minEdge.find(comp1) == minEdge.end() || edge.weight < minEdge[comp1].weight) {
                minEdge[comp1] = edge;
            }
            if (minEdge.find(comp2) == minEdge.end() || edge.weight < minEdge[comp2].weight) {
                minEdge[comp2] = edge;
            }
        }
        
        // Add all minimum edges to MST
        for (auto& [comp, edge] : minEdge) {
            if (uf.unite(edge.u, edge.v)) {
                mstEdges.push_back(edge);
                result.totalWeight += edge.weight;
            }
        }
    }
    
    result.mstEdges = mstEdges;
    return result;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    vector<Edge> edges;
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    BoruvakaResult result = boruvka(n, edges);
    
    cout << "\nMinimum Spanning Tree Edges:\n";
    cout << "Format: (u -- v) : weight\n";
    for (auto& edge : result.mstEdges) {
        cout << "(" << edge.u << " -- " << edge.v << ") : " << edge.weight << "\n";
    }
    
    cout << "\nTotal MST Weight: " << result.totalWeight << "\n";
    cout << "Number of edges in MST: " << result.mstEdges.size() << "\n";
    
    return 0;
}

/*
EXAMPLE INPUT:
6 9
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 3

EXPECTED OUTPUT:
Minimum Spanning Tree Edges:
Format: (u -- v) : weight
(1 -- 2) : 1
(0 -- 2) : 2
(3 -- 4) : 2
(1 -- 3) : 5
(4 -- 5) : 3

Total MST Weight: 13
Number of edges in MST: 5
*/
