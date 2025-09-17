class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n, m;
    vector<vector<int>> dp;
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        
        long long res = 1; // single cell path
        for (auto& d : directions) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] > grid[i][j]) {
                res += dfs(grid, x, y);
                res %= MOD;
            }
        }
        return dp[i][j] = (int)res;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                total += dfs(grid, i, j);
                total %= MOD;
            }
        }
        return (int)total;
    }
};
