#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Floyd Warshall Algorithm - All Pairs Shortest Path
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
// Use Case: Find shortest paths between all pairs of vertices in a weighted graph

void floydWarshall(vector<vector<int>>& dist, int n) {
    // dist[i][j] represents the shortest distance from vertex i to vertex j
    
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the source vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // Update distance if path through k is shorter
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Function to print the distance matrix
void printMatrix(vector<vector<int>>& dist, int n) {
    cout << "Shortest distances between all pairs:\n";
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
    
    // Initialize distance matrix
    vector<vector<int>> dist(n, vector<int>(n, INF));
    
    // Distance from a vertex to itself is 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);  // Handle multiple edges
    }
    
    cout << "\nBefore Floyd Warshall:\n";
    printMatrix(dist, n);
    
    floydWarshall(dist, n);
    
    cout << "\nAfter Floyd Warshall:\n";
    printMatrix(dist, n);
    
    // Detect negative cycle
    bool negativeCycle = false;
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            negativeCycle = true;
            cout << "\nNegative cycle detected at vertex " << i << "\n";
        }
    }
    
    if (!negativeCycle) {
        cout << "\nNo negative cycle detected.\n";
    }
    
    return 0;
}

/*
EXAMPLE INPUT:
4 5
0 1 5
0 3 10
1 2 3
2 3 1
3 2 9

EXPECTED OUTPUT:
Shortest distances between all pairs:
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF 9 0 

No negative cycle detected.
*/
