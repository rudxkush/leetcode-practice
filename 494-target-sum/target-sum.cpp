class Solution {
public:
    vector<vector<int>> dp;
    int knapsack(vector<int>& arr, int i, int target) {
        // base case 
        if(i < 0) {
            if(target == 0){
                return 1;
            }
            return 0;
        }
        if(target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        
        int include = 0;
        if(arr[i] <= target) { 
            include = knapsack(arr, i - 1, target - arr[i]);
        }
        int exclude = knapsack(arr, i - 1, target);
        
        return dp[i][target] = (include + exclude);
    }
    int findTargetSumWays(vector<int>& nums, int d) {
        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
        }
        if ((totalSum + d) % 2 != 0 || totalSum < d || totalSum < -d) return 0;
        int target = (totalSum + d) / 2;
        int n = nums.size();
        dp.resize(n, vector<int> (target + 1, -1));
        return knapsack(nums, n - 1, target);
    }
};