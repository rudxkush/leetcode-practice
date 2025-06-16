class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n * m;
        vector<int> res;
        int up = 0, down = n - 1;
        int left = 0, right = m - 1;
        while(total > res.size()) {
            for(int i = left; i <= right && total > res.size(); i++) {
                res.push_back(matrix[up][i]);
            }
            up++;
            for(int i = up; i <= down && total > res.size(); i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right; i >= left && total > res.size(); i--) {
                res.push_back(matrix[down][i]);
            }
            down--;
            for(int i = down; i >= up && total > res.size(); i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};