class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        visited[entrance[0]][entrance[1]] = true;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for(auto& dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol] && maze[nrow][ncol] != '+') {
                    if(nrow == 0 || nrow == n-1 || ncol == 0 || ncol == m-1) return steps + 1;
                    q.push({{nrow, ncol}, steps + 1});
                    visited[nrow][ncol] = true;
                } 
            }
        }
        return -1;
    }
};