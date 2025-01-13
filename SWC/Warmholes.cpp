#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a[10][5];
bool vis[10] = {false};
int ans;


int dist(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}


void solve(int sx, int sy, int dx, int dy, int val) {
    ans = min(ans, (dist(sx, sy, dx, dy) + val));

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            vis[i] = true;

            solve(a[i][0], a[i][1], dx, dy, val + dist(sx, sy, a[i][2], a[i][3]) + a[i][4]);
            
            solve(a[i][2], a[i][3], dx, dy, val + dist(sx, sy, a[i][0], a[i][1]) + a[i][4]);
            
            vis[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        solve(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
}