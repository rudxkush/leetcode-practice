class Solution {
public:
    int n = 0, m = 0; 
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    bool dfsTraversal(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        if (grid[i][j] == 1 || visited[i][j]) return true;

        visited[i][j] = true;
        bool isClosed = true;

        for (auto& dir : directions) {
            if (!dfsTraversal(grid, i + dir[0], j + dir[1], visited)) {
                isClosed = false;
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfsTraversal(grid, i, j, visited)) count++;
                } 
            }
        }

        return count;
    }
};
