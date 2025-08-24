class Solution {
public:
    void topoSort(vector<vector<int>>& graph, vector<int>& quiet,
                  vector<int>& inDegree, vector<int>& quietRicher, int n) {
        queue<int> q; // person
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int person = q.front();
            q.pop();
            for (auto nei : graph[person]) {
                if (quiet[quietRicher[person]] < quiet[quietRicher[nei]]) {
                    quietRicher[nei] = quietRicher[person];
                }
                inDegree[nei]--;
                if (inDegree[nei] == 0)
                    q.push(nei);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> quietRicher(n);
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            quietRicher[i] = i;
        }
        for (auto rich : richer) {
            graph[rich[0]].push_back(rich[1]);
            inDegree[rich[1]]++;
        }
        topoSort(graph, quiet, inDegree, quietRicher, n);
        return quietRicher;
    }
};
