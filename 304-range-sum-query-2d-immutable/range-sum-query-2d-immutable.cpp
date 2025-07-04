class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.assign(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefix[i][j] = matrix[i - 1][j - 1] + 
                               prefix[i - 1][j] + 
                               prefix[i][j - 1] -
                               prefix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - 
               prefix[row1][col2 + 1] - 
               prefix[row2 + 1][col1] + 
               prefix[row1][col1];
    }
};