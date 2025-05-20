class Solution {
public:
    int row, col;
    vector<vector<int>> memo;
    int solve(int i, int j) {
        if(i == row && j == col) return 1;
        if(i > row || j > col) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        
        int down = solve(i + 1, j);

        int right = solve(i , j + 1);

        return memo[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        // m * n matrix
        // down -> i + 1, j 
        // right -> i ,j + 1
        row = m - 1;
        col = n - 1;
        memo.resize(m, vector<int>(n, -1));
        return solve(0, 0);
    }
};