class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int N = graph.size();
        const int DRAW = 0, MOUSE = 1, CAT = 2;

        // color[m][c][t] = result (0=draw, 1=mouse wins, 2=cat wins)
        vector<vector<vector<int>>> color(N, vector<vector<int>>(N, vector<int>(3, DRAW)));
        // degree[m][c][t] = number of neutral moves available
        vector<vector<vector<int>>> degree(N, vector<vector<int>>(N, vector<int>(3, 0)));

        // initialize degree
        for (int m = 0; m < N; ++m) {
            for (int c = 0; c < N; ++c) {
                degree[m][c][1] = graph[m].size(); // mouse's turn
                degree[m][c][2] = graph[c].size(); // cat's turn
                for (int x : graph[c]) {
                    if (x == 0) { // cat can't move to hole
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
        }

        queue<array<int,4>> q;

        // base cases
        for (int i = 0; i < N; ++i) {
            for (int t = 1; t <= 2; ++t) {
                color[0][i][t] = MOUSE;
                q.push({0, i, t, MOUSE});
                if (i > 0) {
                    color[i][i][t] = CAT;
                    q.push({i, i, t, CAT});
                }
            }
        }

        // percolate
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            int m = node[0], c = node[1], t = node[2], result = node[3];

            for (auto& parent : parents(graph, m, c, t)) {
                int m2 = parent[0], c2 = parent[1], t2 = parent[2];
                if (color[m2][c2][t2] == DRAW) {
                    if (t2 == result) {
                        // parent can force a win
                        color[m2][c2][t2] = result;
                        q.push({m2, c2, t2, result});
                    } else {
                        // reduce degree, if no moves left then parent is losing
                        degree[m2][c2][t2]--;
                        if (degree[m2][c2][t2] == 0) {
                            color[m2][c2][t2] = 3 - t2;
                            q.push({m2, c2, t2, 3 - t2});
                        }
                    }
                }
            }
        }

        return color[1][2][1];
    }

    vector<array<int,3>> parents(vector<vector<int>>& graph, int m, int c, int t) {
        vector<array<int,3>> ans;
        if (t == 2) { // cat's turn now, so previous was mouse
            for (int m2 : graph[m]) {
                ans.push_back({m2, c, 3 - t});
            }
        } else { // mouse's turn now, so previous was cat
            for (int c2 : graph[c]) {
                if (c2 > 0) {
                    ans.push_back({m, c2, 3 - t});
                }
            }
        }
        return ans;
    }
};
