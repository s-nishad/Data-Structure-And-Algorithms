#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& graph, int start) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); 
    stack<int> st; 

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();
        cout << current << " ";  

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
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

    cout << "DFS traversal starting from node " << startNode << ": ";
    DFS(graph, startNode);

    return 0;
}
