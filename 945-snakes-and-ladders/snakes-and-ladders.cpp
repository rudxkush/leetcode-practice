class Solution {
public:
    int n = 0;
    pair<int,int> getCoordinate(int s) {
        int r = n - 1 - s / n; // bottom row = n-1
        int c = s % n;
        if ((n - 1 - r) % 2 == 1) c = n - 1 - c; // odd row from bottom → right to left
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size(); 
        vector<bool> visited(n*n, false);

        queue<pair<int, int>> q; // cell, steps;
        q.push({0, 0});
        visited[0] = true;
        while(!q.empty()) {
            auto [cell, steps] = q.front(); q.pop();
            if(cell == (n*n) - 1) return steps;

            for(int i = 1; i <= 6; i++) {
                int next = cell + i;
                if(next >= n*n) continue;

                auto [row, col] = getCoordinate(next);
                if(board[row][col] != -1) next = board[row][col] - 1;
                if(!visited[next]) {
                    q.push({next, steps + 1});
                    visited[next] = true;
                }
            }
        }
        return -1;
    }
};