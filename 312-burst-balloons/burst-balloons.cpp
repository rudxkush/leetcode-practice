class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& dummy, int i, int j) {
        // base case
        if(i > j) return 0;
        if(i == j) return dummy[i-1] * dummy[i] * dummy[i+1];
        if(dp[i][j] != -1) return dp[i][j];

        int maxSum = 0;
        for(int k = i; k <= j; k++) {
            int sum = dummy[i - 1] * dummy[k] * dummy[j + 1] + 
                      solve(dummy, i, k - 1) + 
                      solve(dummy, k + 1, j);
            maxSum = max(maxSum, sum);
        }
        return dp[i][j] = maxSum;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> dummy;
        dummy.push_back(1);
        for(int i = 0; i < n; i++)
            dummy.push_back(nums[i]);
        dummy.push_back(1);
        dp.resize(n + 2, vector<int>(n + 2, -1));
        return solve(dummy, 1, n);
    }
};

/*
[3, 1, 5, 8]
burst = 1
coins = 3 * 1 * 5 = 15

[3, 5, 8]
burst = 5
coins = 3 * 5 * 8 = 120

[3, 8]
burst = 3
coins = 1 * 3 * 8 = 24

[8]
burst = 8
coins = 1 * 8 * 1 = 8

totalSum = 15 + 120 + 24 + 8 = 167

[1, 3, 1, 5, 8, 1]
    i        j

*/
