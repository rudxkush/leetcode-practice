class Solution {
public:
    vector<vector<int>> dp;
    int unboundedKnapsack(vector<int>& coins, int i, int amount) {
        // base cases
        if(amount == 0) return 0;
        if(i < 0 || amount < 0) return INT_MAX;

        if(dp[i][amount] != -1) return dp[i][amount];

        // Include current coin
        int include = unboundedKnapsack(coins, i, amount - coins[i]);
        if (include != INT_MAX) include += 1;

        // Exclude current coin
        int exclude = unboundedKnapsack(coins, i - 1, amount);

        return dp[i][amount] = min(include, exclude);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1)); // properly initialize with -1
        int answer = unboundedKnapsack(coins, n - 1, amount);
        return answer == INT_MAX ? -1 : answer;
    }
};
