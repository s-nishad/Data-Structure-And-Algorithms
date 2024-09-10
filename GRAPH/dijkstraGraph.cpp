#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 1e5 + 123;
using pi = pair<int, int>;
vector<vector<pi>> graph(mx);
vector<int> dist(mx);

void dijkstra(int s, int n) {
    // Initialize distances with a large value
    for(int i = 0; i <= n; i++) {
        dist[i] = LLONG_MAX;
    }

    dist[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto e : graph[u]) {
            int v = e.first;
            int w = e.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int32_t main() {
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(0, nodes);

    for(int i = 0; i < nodes; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
