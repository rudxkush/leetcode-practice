class Solution { 
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(),
        n = matrix[0].size(); 
        int left = matrix[0][0], right = matrix[m - 1][n - 1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right =
                    mid - 1; 
            } else
                left = mid + 1; 
        }
        return ans;
    }
    // similar to search in a 2D sorted matrix" problem where you start from the
    // top-right corner and move toward the bottom-left corner to find a
    // specific target.
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int count = 0, col = n - 1;
        for (int row = 0; row < m; row++) {
            while (col >= 0 && matrix[row][col] > x){
                --col;
            }
            count += (col + 1);
        }
        return count;
    }
};