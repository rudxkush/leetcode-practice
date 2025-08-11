class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> res;
            for (int i = 0; i < n; i++) res.push_back(i);
            return res;
        }

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) leaves.push(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leafCount = leaves.size();
            remainingNodes -= leafCount;
            for (int i = 0; i < leafCount; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : graph[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> mhts;
        while (!leaves.empty()) {
            mhts.push_back(leaves.front());
            leaves.pop();
        }
        return mhts;
    }
};
