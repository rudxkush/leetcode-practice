class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        for (auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = true;
            connected[v][u] = true;
        }

        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = degree[i] + degree[j];
                if (connected[i][j]) rank--; 
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};

/***********************************************
    n = 4, ** bi-directional** roads = [
                                        [0,1]
                                        [0,3]
                                        [1,2]
                                        [1,3]
                                    ]
    Output: 4

        0 ---- 1 ---- 2
          \   /
            3
        
        Find the path that has the highest number of cities 
        connected to both the cities combined.
***********************************************/