class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // can move in all 8 direction where grid[i][j] must be 0
        // in order to reach grid[r - 1][c - 1] from grid[0][0].
        int directions[8][2] = {{-1, 0},  {0, 1},  {1, 0},  {0, -1},
                                {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        int r = grid.size();
        int c = grid[0].size();
        if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1)
            return -1; // edge case
            
        vector<vector<int>> distance(r, vector<int>(c, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        distance[0][0] = 0;
        q.push({1, {0, 0}}); // {steps, {row, col}}

        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int step = q.front().first;
            q.pop();
            if (row == r - 1 && col == c - 1)
                return step;

            for (auto dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if (nrow >= 0 && ncol >= 0 && nrow < r && ncol < c 
                && grid[nrow][ncol] == 0 
                && distance[nrow][ncol] > step + 1) {

                    distance[nrow][ncol] = step + 1;
                    q.push({step + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};