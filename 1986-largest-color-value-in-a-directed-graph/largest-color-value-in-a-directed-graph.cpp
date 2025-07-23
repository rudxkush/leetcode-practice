class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Kahn's algorithm (toposort)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<vector<int>> colorCount(n, vector<int>(26, 0));
        int processed = 0, maxColor = 0;

        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            processed++;

            int c = colors[node] - 'a';
            colorCount[node][c]++;

            maxColor = max(maxColor, colorCount[node][c]);

            for (int neighbor : graph[node]) {
                for (int i = 0; i < 26; i++) {
                    colorCount[neighbor][i] = max(colorCount[neighbor][i], colorCount[node][i]);
                }
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return (processed == n) ? maxColor : -1;
    }
};
