class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& q) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) return;
        grid[i][j] = 2; 
        q.push({i, j});
        for(auto& d : dirs) {
            dfs(grid, i + d[0], j + d[1], q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;

        // Find the first island and mark it using DFS
        bool found = false;
        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < m && !found; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }

        // BFS to expand into water and find the second island
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [x, y] = q.front(); q.pop();
                for(auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if(grid[nx][ny] == 1) return steps; // Reached second island
                        if(grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }

        return -1; 
    }
};

/*
Think of these ones as island and as they are not connected in any four
direction we need to connect them with the land type to make them connected.
    0 1
    1 0

    0 1     (or)    1 1
    1 1             1 0
    extra land used : 1

    0 1 0
    0 0 0
    0 0 1
    similarly,

    0 1 0
    0 1 1
    0 0 1
    extra land used : 2
*/
