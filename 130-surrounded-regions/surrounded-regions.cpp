class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        // for marking all corner Os to T
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != 'O')
            return;

        board[i][j] = 'T';

        dfs(board, i - 1, j); // up
        dfs(board, i, j - 1); // left
        dfs(board, i + 1, j); // down
        dfs(board, i, j + 1); // right
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0); // left border
            if (board[i][c - 1] == 'O')
                dfs(board, i, c - 1); // right border
        }

        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j); // top border
            if (board[r - 1][j] == 'O')
                dfs(board, r - 1, j); // bottom border
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};