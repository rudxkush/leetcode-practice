class Solution {
public:
    int res = 1;
    int dfs(vector<vector<int>>& graph, int currNode, int parentNode,
            string& s) {
        int longest1 = 0, longest2 = 0;

        for (auto nei : graph[currNode]) {
            if (nei == parentNode)
                continue;

            int childLen = dfs(graph, nei, currNode, s);

            if (s[nei] != s[currNode]) {
                if (childLen > longest1) {
                    longest2 = longest1;
                    longest1 = childLen;
                } else if (childLen > longest2) {
                    longest2 = childLen;
                }
            }
        }

        res = max(res, 1 + longest1 + longest2);
        return 1 + longest1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                graph[parent[i]].push_back(i);
                graph[i].push_back(parent[i]);
            }
        }

        dfs(graph, 0, -1, s);
        return res;
    }
};
