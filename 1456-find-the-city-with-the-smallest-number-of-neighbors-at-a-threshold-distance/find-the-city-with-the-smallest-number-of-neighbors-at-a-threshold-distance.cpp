class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

        for (auto edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }

        for(int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][k] < INT_MAX && distance[k][j] < INT_MAX) {
                        distance[i][j] = min(distance[i][j],
                                             distance[i][k] + distance[k][j]);
                    }
                }
            }
        }
        int cntCity = n;
        int cityNum = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (distance[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNum = i;
            }
        }

        return cityNum;
    }
};