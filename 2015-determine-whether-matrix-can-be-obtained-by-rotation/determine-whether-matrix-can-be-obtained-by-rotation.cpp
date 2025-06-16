class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix == target) return true;
        int degree = 3;
        while(degree != 0) {
            for(int i = 0; i < n; i++) {
                for(int j = i; j < m; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            for(int i = 0; i < n; i++) {
                reverse(matrix[i].begin(), matrix[i].end());
            }
            if(matrix == target) return true;
            degree--;
        }
        return false;
    }
};