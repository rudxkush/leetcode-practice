class Solution {
public:
    int n = 0, m = 0;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size();
        m = grid[0].size();
        int keyMask = 0;
        queue<tuple<int, int, int, int>> q;
        set<tuple<int, int, int>> visited;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0, 0});
                    visited.insert({i, j, 0});
                } else if (islower(grid[i][j])) {
                    keyMask |= (1 << (grid[i][j] - 'a'));
                }
            }
        }

        // bfs search
        while (!q.empty()) {
            auto [row, col, steps, keys] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                int newKeys = keys;
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) 
                    continue;
                char cell = grid[nrow][ncol];

                if (cell == '#') 
                    continue;

                if(islower(cell)) 
                    newKeys |= (1 << (cell - 'a'));

                if(newKeys == keyMask) 
                    return steps + 1;

                if (isupper(cell)) 
                    if(!(newKeys & (1 << (cell - 'A'))))
                        continue;
                
                if (!visited.count({nrow, ncol, newKeys})) {
                    visited.insert({nrow, ncol, newKeys});
                    q.push({nrow, ncol, steps + 1, newKeys});
                }
            }
        }
        return -1;
    }
};

/*
    grid = [
                "@  .  a  .  .",
                "#  #  #  .  #",
                "b  .  A  .  B"
            ]
    . -> empty cell
    # -> wall
    @ -> Starting Point
    Lower Case -> keys
    Upper Case -> locks

    four direction movement allowed
    pick a key and cant walk over unless you have its corresponding key
    that is corresponding capital letter.


    https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/?envType=study-plan-v2&envId=graph-theory

    // MULTI SOURCE BFS
    https://leetcode.com/problems/01-matrix/description/
    https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
    https://leetcode.com/problems/shortest-distance-from-all-buildings/description/
    https://leetcode.com/problems/walls-and-gates/description/
    https://leetcode.com/problems/rotting-oranges/description/

    // BIT MASK DP
    https://maang.in/courses/Dynamic-Programming-with-Bitmasking-74?tab=chapters
*/