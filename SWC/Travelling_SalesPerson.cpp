#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[12][12];
int ans = 1000000;
int visited[12] = {};

void solve(int x, int count, int dis) {
    if (count + 1 == n) {
        ans = min(ans, dis + a[x][0]);
        return;
    }
    visited[x] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            solve(i, count + 1, dis + a[x][i]);
        }
    }
    visited[x] = 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        solve(0, 0, 0);
        cout << ans << endl;
        ans = 1000000;
    }

    return 0;
}