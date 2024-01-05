class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0

        # Initialize an array to store the lengths of LIS
        dp = [1] * n

        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            #maxlength = max(dp[i], maxlength)

        # The result is the maximum value in the dp array
        return max(dp)

# Example usage:
nums = [10, 22, 9, 33, 21, 50, 41, 60, 80]
solution = Solution()
result = solution.lengthOfLIS(nums)
print("Length of the Longest Increasing Subsequence:", result)
