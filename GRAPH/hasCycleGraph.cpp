#include<bits/stdc++.h>
using namespace std;

void createGraph(vector<vector<int>> &graph, int node1, int node2) {
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
}

bool dfs(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack) {
    visited[start] = 1;
    recStack[start] = 1;

    for(int neighbor : graph[start]) {
        if(!visited[neighbor]) {
            if(dfs(neighbor, graph, visited, recStack)) {
                return true;
            }
        } else if(recStack[neighbor]){
            return true;
        }
    }

    recStack[start] = false;
    return false;
}

bool hasCycle(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dfs(i, graph, visited, recStack)) {
            return true;
        }
    }
    return false;
}



int main() {
    int node, edge;
    cin >> node >> edge;
    // vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    vector<vector<int>> edges={{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}};
    vector<vector<int>> graph(node);
    for (auto &e : edges) {
        createGraph(graph, e[0], e[1]);
    }

    if (hasCycle(graph)) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }
}
