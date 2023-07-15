#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recursionStack) {
    visited[node] = true;
    recursionStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && dfs(neighbor, graph, visited, recursionStack))
            return true;
        else if (recursionStack[neighbor])
            return true;
    }

    recursionStack[node] = false;
    return false;
}

bool isCyclic(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<bool> recursionStack(numVertices, false);

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i] && dfs(i, graph, visited, recursionStack))
            return true;
    }

    return false;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
    }

    if (isCyclic(graph))
        cout << "The graph contains a cycle.\n";
    else
        cout << "The graph does not contain a cycle.\n";

    return 0;
}
