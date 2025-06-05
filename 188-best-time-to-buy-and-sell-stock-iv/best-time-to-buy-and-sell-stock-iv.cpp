class Solution {
public:
    vector<vector<vector<int>>> dp;
    int helper(vector<int>& prices, int k, int i, bool canbuy) {
        // base case
        if(k <= 0) return 0; 
        if(i >= prices.size()) return 0;
        if(dp[i][k][canbuy] != -1) return dp[i][k][canbuy];

        long profit = 0;
        if(canbuy) {
            profit = max(
                          -prices[i] + helper(prices, k, i + 1, false), 
                           helper(prices, k, i + 1, true)
                        );
        } else {
            profit = max(
                           prices[i] + helper(prices, k - 1, i + 1, true), 
                           helper(prices, k, i + 1, false)
                        );
        }
        return dp[i][k][canbuy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.assign(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return helper(prices, k, 0, true);
    }
};