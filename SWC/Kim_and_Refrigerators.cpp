#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int n;
int a[20], b[20];
int ans;


int dist(int prev, int idx) {
    int x1 = a[prev], y1 = b[prev];
    int x2 = a[idx], y2 = b[idx];
    return (abs(x1-x2)+ abs(y1-y2));
}

void solve(int idx, bool vis[], int value, int nodescount) {
    if(nodescount == n) {
        ans = min(ans, value + dist(idx, n+1));
    }

    for(int  i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            solve(i, vis, value + dist(idx, i), nodescount+1);
            vis[i] = false;
        }
    }
}

int main() {
    int m = 10;
    for(int i = 0; i < m; i++) {
        cin >> n;
        cin >> a[0] >> b[0] >> a[n+1] >> b[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        ans = INT_MAX;
        bool vis[n+2] = {false};
        int value = 0;
        int prev = 0;
        solve(0, vis, value, prev);
        cout << "# " << i + 1 << " " << ans << endl;
    }
}