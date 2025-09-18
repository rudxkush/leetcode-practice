class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }

        // use bitsets to track ancestors compactly
        vector<bitset<1001>> ancestorBits(n);
        queue<int> q;

        // start topo
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                // inherit ancestors[u] + u itself
                ancestorBits[v] |= ancestorBits[u];
                ancestorBits[v].set(u);

                if (--inDegree[v] == 0) q.push(v);
            }
        }

        // convert bitset to sorted vector
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ancestorBits[i].test(j)) {
                    result[i].push_back(j);
                }
            }
        }

        return result;
    }
};
