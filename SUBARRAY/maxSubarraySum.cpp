#include <iostream>
#include <vector>

using namespace std;

int kadanesAlgorithm(const vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int maxSubarraySum = kadanesAlgorithm(nums);
    
    cout << "Maximum Subarray Sum: " << maxSubarraySum << endl;

    return 0;
}
