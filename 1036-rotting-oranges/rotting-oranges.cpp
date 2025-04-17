class Solution {
public:
    // BFS
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<pair<int, int>, int>> q; // row, col -> time
        vector<vector<int>> visited(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int time = 0;
        // bfs at every level
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);
            for (int i = 0; i < 4; i++) { // exactly 4 neighbours
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c &&
                    visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};