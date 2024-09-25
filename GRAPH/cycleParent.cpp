#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void createGraph(int node1, int node2) {
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
}

// DFS function with parent check to detect cycles in an undirected graph
bool dfs(int start, int parent) {
    visited[start] = true;

    for (int neighbor : graph[start]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, start)) {
                return true;
            }
        } else if (neighbor != parent) {
            // If the neighbor is visited and is not the parent, there's a cycle
            return true;
        }
    }
    return false;
}

// Function to check if the graph contains a cycle
bool hasCycle(int nodes) {
    // Iterate over each node to ensure disconnected components are also checked
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    
    // Resize the graph and visited array based on the number of nodes
    graph.resize(nodes);
    visited.resize(nodes, false);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        createGraph(u, v);
    }

    if (hasCycle(nodes)) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}
