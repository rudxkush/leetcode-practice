class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<int> onesRow(r, 0);
        vector<int> onesCol(c, 0);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }

        vector<vector<int>> res(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - r - c;
            }
        }
        return res;
    }
};