class Solution {
public:
    int n = 0, m = 0;
    vector<vector<vector<int>>> dp;
    // i, j1 -> robot1's start point; i, j2 -> robot2's start point
    int reachLastRow(vector<vector<int>>& grid, int i, int j1, int j2) {
        // out of bound related base case
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // destination related base case
        if(i == n - 1) {
            if(j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        int maxCherries = -1e8;
        // recursive function call
        // for each alice's move [ bottom right, down, bottom left ]
        // there is bob's 9 combos that could be made (3 for each -> 3 * 3 = 9).
        for(int dirJ1 = -1; dirJ1 < 2; dirJ1++) {
            for(int dirJ2 = -1; dirJ2 < 2; dirJ2++) {
                int newJ1 = j1 + dirJ1;
                int newJ2 = j2 + dirJ2;
                int next = reachLastRow(grid, i + 1, newJ1, newJ2);
                int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                maxCherries = max(maxCherries, curr + next);
            }
        }
        return dp[i][j1][j2] = maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return reachLastRow(grid, 0, 0, m - 1);
    }
};