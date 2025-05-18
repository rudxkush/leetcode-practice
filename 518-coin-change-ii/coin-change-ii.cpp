class Solution {
public:
    vector<vector<int>> memo;
    // no of ways we could form the amount using combinations on coins
    int cHelper(int amount, vector<int>& coins, int i) {
        // base case
        if(amount == 0) return 1;
        if(i < 0) 
            return 0;

        if(memo[i][amount] != -1)
            return memo[i][amount];

        int include = 0;
        if(coins[i] <= amount)
            include += cHelper(amount - coins[i], coins, i);

        int exclude = 0;
            exclude += cHelper(amount, coins, i - 1);

        return memo[i][amount] = (include + exclude);

    } 
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memo.resize(n, vector<int> (amount + 1, -1));
        return cHelper(amount, coins, n - 1);
    }
};