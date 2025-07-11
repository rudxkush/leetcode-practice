class Solution {
public:
    int n = 0;
    vector<vector<vector<int>>> dp;

    int stoneGame(vector<int>& piles, int i, int M, bool isAlice) {
        if(i >= n) 
            return 0;
        if(dp[i][M][isAlice] != -1)
            return dp[i][M][isAlice];

        int stones = 0;
        int result = isAlice ? 0 : INT_MAX;

        for(int step = 1; step <= 2 * M && i + step <= n; step++) {
            stones += piles[i + step - 1];
            if(isAlice){
                result = max(result, stones + stoneGame(piles, i + step, max(M, step), false));
            } else {
                result = min(result, stoneGame(piles, i + step, max(M, step), true));
            }
        }

        return dp[i][M][isAlice] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return stoneGame(piles, 0, 1, true);
    }
};
