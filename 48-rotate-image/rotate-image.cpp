class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // To rotate a matrix 90 degrees, 
        // we should first transpose the matrix -> convert rows into columns
        // and then reverse each row -> reverse each row of a matrix
        for(int i = 0; i < n; i++) {
            for(int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        /*
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
        */
    }
};