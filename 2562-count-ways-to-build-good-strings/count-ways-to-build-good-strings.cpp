class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> dp;
    int solve(int low, int high, int zero, int one, int len) {
        // base case
        if(len > high) {
            return 0;
        }
        if(dp[len] != -1) return dp[len];
        int ways = 0;
        if(len >= low) ways = 1;
        
        ways = (ways + solve(low, high, zero, one, len + one)) % MOD;
        ways = (ways + solve(low, high, zero, one, len + zero)) % MOD;

        return dp[len] = ways;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high + 1, -1);
        return solve(low, high, zero, one, 0);
    }
};