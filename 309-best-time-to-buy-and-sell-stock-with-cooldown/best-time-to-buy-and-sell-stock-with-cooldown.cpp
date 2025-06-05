class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& prices, int i, bool canbuy) {
        // base case
        if(i >= prices.size()) return 0;
        if(dp[i][canbuy] != -1) return dp[i][canbuy];

        long maxProfit = 0;
        if(canbuy) {
            maxProfit = max(
                             -prices[i] + helper(prices, i + 1, false),
                              helper(prices, i + 1, true)
                           );
        } else {
            maxProfit = max(
                              prices[i] + helper(prices, i + 2, true),
                              helper(prices, i + 1, false)
                           );
        }
        return dp[i][canbuy] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(), vector<int>(2, -1));
        return helper(prices, 0, true);
    }
};