class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& dummy, int i, int j) {
        // base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        for(int k = i; k <= j; k++) {
            int temp = dummy[i - 1] * dummy[k] * dummy[j + 1] +
                       solve(dummy, i, k - 1) + 
                       solve(dummy, k + 1, j);
            maxi = max(temp, maxi);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> dummy;
        dummy.push_back(1);
        for(int num : nums)
            dummy.push_back(num);
        dummy.push_back(1);
        int n = dummy.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(dummy, 1, n - 2);
    }
};