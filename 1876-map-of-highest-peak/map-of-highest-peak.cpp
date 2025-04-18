class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        vector<vector<int>> height(r, vector<int>(c, -1));
        vector<vector<int>> visited(r, vector<int>(c, 0));

        queue<pair<pair<int, int>, int>> q; // i, j, height

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isWater[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int h = q.front().second;
            q.pop();
            height[row][col] = h;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dirs[i][0];
                int ncol = col + dirs[i][1];

                // check if nrow, ncol is valid
                if (nrow < 0 || ncol < 0 || nrow >= r || ncol >= c ||
                    visited[nrow][ncol] == 1) {
                    continue;
                }
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, h + 1});
            }
        }
        return height;
    }
};