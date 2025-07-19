class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfsTraversal(vector<vector<int>>& heights, vector<vector<bool>>& visited, int height, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= m || visited[r][c] || heights[r][c] < height) {
            return;
        }

        visited[r][c] = true;
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfsTraversal(heights, visited, heights[r][c], nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacificVisited(n, vector<bool>(m, false)),
                             atlanticVisited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfsTraversal(heights, pacificVisited, heights[i][0], i, 0);
            dfsTraversal(heights, atlanticVisited, heights[i][m - 1], i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            dfsTraversal(heights, pacificVisited, heights[0][j], 0, j);
            dfsTraversal(heights, atlanticVisited, heights[n - 1][j], n - 1, j);
        }

        vector<vector<int>> commonPath;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j]) {
                    commonPath.push_back({i, j});
                }
            }
        }
        return commonPath;
    }
};
