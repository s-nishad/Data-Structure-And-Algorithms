#include <iostream>
#include <vector>
using namespace std;

int rodCutting(vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], prices[j] + dp[i - j]);
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the rod size: ";
    cin >> n;

    vector<int> prices(n + 1);
    cout << "Enter the prices: ";
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    int maxRevenue = rodCutting(prices, n);
    cout << "Maximum revenue: " << maxRevenue << endl;

    return 0;
}
