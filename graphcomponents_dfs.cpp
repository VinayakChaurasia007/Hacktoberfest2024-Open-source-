#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true; // Mark the node as visited
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited); // Visit all unvisited neighbors
        }
    }
}

// Function to calculate number of connected components
int countComponents(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n, false); // To keep track of visited nodes
    int components = 0; // Count of connected components

    // Traverse all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // If the node is not visited, it's part of a new component
            dfs(i, adj, visited);
            components++; // Increment component count
        }
    }

    return components;
}

int main() {
    int n, m; // n = number of nodes, m = number of edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n); // Adjacency list representation of the graph

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Since the graph is undirected, add edges in both directions
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Calculate and output the number of connected components
    int result = countComponents(n, adj);
    cout << "Number of connected components: " << result << endl;

    return 0;
}
