class Solution {
public:
    vector<vector<int>> prefixSum;
    vector<vector<vector<int>>> dp;
    int MOD = (int) 1e9 + 7;
    int n = 0, m = 0;
    void computePrefix(vector<string>& pizza) {
       prefixSum.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; --i) 
            for (int j = m - 1; j >= 0; --j) 
                prefixSum[i][j] = (pizza[i][j] == 'A' ? 1 : 0) +
                                  prefixSum[i + 1][j] + 
                                  prefixSum[i][j + 1] -
                                  prefixSum[i + 1][j + 1];
            
        return;
    }
    int getSlices(vector<string>& pizza, int r, int c, int k) {
        if (prefixSum[r][c] == 0) return 0;
        if(k == 1) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];

        int ways = 0;
        // trying to cut the pizza horizontally
        for (int nr = r + 1; nr < n; nr++) 
            if (prefixSum[r][c] - prefixSum[nr][c] > 0) 
                ways = (ways + getSlices(pizza, nr, c, k - 1)) % MOD;

        // trying to cut the pizza vertically
        for(int nc = c + 1; nc < m; nc++) 
            if(prefixSum[r][c] - prefixSum[r][nc] > 0) 
                ways = (ways + getSlices(pizza, r, nc, k - 1)) % MOD;
            

        return dp[r][c][k] = ways;
    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        computePrefix(pizza);
        dp.assign(n, vector<vector<int>>(m, vector<int> (k + 1, -1)));
        return getSlices(pizza, 0, 0, k);
    }
};