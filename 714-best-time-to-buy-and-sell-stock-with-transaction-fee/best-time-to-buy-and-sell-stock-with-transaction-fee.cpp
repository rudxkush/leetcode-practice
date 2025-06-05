class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int fee, int i, bool canbuy) {
        // base case
        if(i >= prices.size()) return 0;
        if(dp[i][canbuy] != -1) return dp[i][canbuy];

        long profit = 0;
        if(canbuy) {
            profit = max(
                          -prices[i] + helper(prices, fee, i + 1, false),
                           helper(prices, fee, i + 1, true)
                        );
        } else {
            profit = max(
                           (prices[i] - fee) + helper(prices, fee, i + 1, true),
                           helper(prices, fee, i + 1, false)
                        );
        }

        return dp[i][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.assign(prices.size(), vector<int>(2, -1));
        return helper(prices, fee, 0, true);
    }
};