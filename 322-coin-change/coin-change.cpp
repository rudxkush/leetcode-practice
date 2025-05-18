class Solution {
public:
    vector<vector<int>> dp;
    int coinChangeHelper(vector<int>& coins, int i, int amount) {
        // base case
        if(amount == 0) return 0;
        if(i < 0 || amount < 0) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        int taken = 1e9;
        if(coins[i] <= amount)
            taken = 1 +  coinChangeHelper(coins, i, amount - coins[i]);

        int notTaken = coinChangeHelper(coins, i - 1, amount);

        return dp[i][amount] = min(taken, notTaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n, vector<int> (amount + 1, -1));
        int res = coinChangeHelper(coins, n - 1, amount);
        return res >= 1e9 ? -1 : res;
    }
};