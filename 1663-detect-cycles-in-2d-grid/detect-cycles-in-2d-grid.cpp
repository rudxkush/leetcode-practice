class Solution {
public:
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};  // up, down, left, right

    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];

            if (ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size())
                continue;

            if (grid[ni][nj] != grid[i][j])
                continue;

            if (!visited[ni][nj]) {
                if (dfs(grid, ni, nj, i, j, visited))
                    return true;
            } else if (ni != pi || nj != pj) {
                // Cycle found
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};
