#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); 
    queue<int> q; 

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";  

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    //input
    //freopen("travers.txt", "r", stdin);
    
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << endl;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        // Add edges to the graph (undirected graph)
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << endl;

    cout << "BFS traversal starting from node " << startNode << ": ";
    BFS(graph, startNode);

    return 0;
}
