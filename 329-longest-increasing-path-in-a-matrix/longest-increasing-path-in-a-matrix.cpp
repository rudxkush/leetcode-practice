class Solution {
public:
    int n = 0, m = 0;
    int dp[200][200];
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int helper(vector<vector<int>>& matrix, int row, int col) {
        if(dp[row][col] != -1) return dp[row][col];

        int dis = 1;  // minimum path length = 1 (the cell itself)
        for(auto dir : directions) {
            int newRow = row + dir[0]; 
            int newCol = col + dir[1];
            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) 
                continue;
            if(matrix[newRow][newCol] > matrix[row][col]) {
                dis = max(dis, 1 + helper(matrix, newRow, newCol));
            }
        }

        return dp[row][col] = dis;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        
        int lisMaxSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                lisMaxSum = max(lisMaxSum, helper(matrix, i, j));
            }
        }
        return lisMaxSum;
    }
};
