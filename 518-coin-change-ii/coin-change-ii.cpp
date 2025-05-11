class Solution {
public:
    vector<vector<int>> dp;
    int knapsack(vector<int>& arr, int target, int i) {
        // base case
        if (i < 0) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }
        // if target went beyond 0
        if (target < 0) {
            return 0;
        }
        // if already computed!
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        // choice : include
        int include = 0;
        if (arr[i] <= target) {
            include = knapsack(arr, target - arr[i], i);
        }
        // choice : exclude
        int exclude = knapsack(arr, target, i - 1);

        return dp[i][target] = (include + exclude);
    }
    int change(int target, vector<int>& arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(target + 1, -1));
        return knapsack(arr, target, n - 1);
    }
};