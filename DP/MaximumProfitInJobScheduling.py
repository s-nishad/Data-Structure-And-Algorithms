class Solution:
    def jobScheduling(self, startTime, endTime, profit):
        n = len(startTime)
        
        jobs = [(startTime[i], endTime[i], profit[i]) for i in range(n)]
        
        jobs.sort(key=lambda x: x[1])
        
        dp = [0] * n
        
        dp[0] = jobs[0][2] 
        
        def binary_search(current_index):
            low, high = 0, current_index - 1
            
            while low <= high:
                mid = (low + high) // 2
                
                if jobs[mid][1] <= jobs[current_index][0]:
                    if jobs[mid + 1][1] <= jobs[current_index][0]:
                        low = mid + 1
                    else:
                        return mid
                else:
                    high = mid - 1
            
            return -1  # No non-overlapping job found
        
        for i in range(1, n):
            current_profit = jobs[i][2]
            non_overlapping_job_index = binary_search(i)
            
            if non_overlapping_job_index != -1:
                current_profit += dp[non_overlapping_job_index]
            
            dp[i] = max(dp[i - 1], current_profit)
        
        return dp[n - 1]

# Example usage:
solution = Solution()
startTime = [1, 2, 3, 3]
endTime = [3, 4, 5, 6]
profit = [50, 10, 40, 70]
result = solution.jobScheduling(startTime, endTime, profit)
print(result)
