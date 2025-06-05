class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int i, bool canBuy) {
        // base case
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][canBuy] != -1) return dp[i][canBuy];

        // if choosed to buy
        long profit = 0;
        if(canBuy) {
            profit = max( 
                          -prices[i] + solve(prices, i + 1, 0),
                           solve(prices, i + 1, 1) 
                        );
        } else {
            // if only there is canBuy set to 0
            profit = max(
                         prices[i] + solve(prices, i + 1, 1), 
                         solve(prices, i + 1, 0) 
                        );
        }

        return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1);
    }
};