#include <bits/stdc++.h>
using namespace std;

#define int long long

int LIS_Length(vector<int> &num) {
    int n = num.size();
    int maxLength = 0;

    if (n == 0) {
        return 0;
    }

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    
    return maxLength;
    
}



int32_t main() {

    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    
    int lisLength = longestIncreasingSubsequence(nums);
    
    cout << "Length of the Longest Increasing Subsequence: " << lisLength << endl;
    return 0;
}
