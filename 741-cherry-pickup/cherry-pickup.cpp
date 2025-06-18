class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;  
        if (r1 >= n || c1 >= m || r2 >= n || c2 >= m ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == m - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2)  
            cherries += grid[r2][c2];

        int next = max({
            dfs(grid, r1 + 1, c1, r2 + 1),  // both down
            dfs(grid, r1, c1 + 1, r2),      // first right, second down
            dfs(grid, r1 + 1, c1, r2),      // first down, second right
            dfs(grid, r1, c1 + 1, r2 + 1)   // both right
        });

        if (next == INT_MIN)
            return dp[r1][c1][r2] = INT_MIN;

        return dp[r1][c1][r2] = cherries + next;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n, -1)));
        return max(0, dfs(grid, 0, 0, 0));
    }
};
