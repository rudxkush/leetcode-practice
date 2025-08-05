class Solution {
public:
    pair<int, int> getCoordinates(int num, int n) {
        int r = n - 1 - (num - 1) / n;
        int c = (num - 1) % n;
        if (((n - 1 - r) % 2) == 1) c = n - 1 - c; // flip column for odd row from bottom
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {cell number, number of moves}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            if (curr == n * n) return moves;

            for (int dice = 1; dice <= 6; ++dice) {
                int next = curr + dice;
                if (next > n * n) continue;

                auto [r, c] = getCoordinates(next, n);
                if (board[r][c] != -1) next = board[r][c];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
