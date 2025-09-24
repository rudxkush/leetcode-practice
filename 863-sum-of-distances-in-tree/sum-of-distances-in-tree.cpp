class Solution {
public:
    vector<int> dp, sbtrSize, ans;
    void dfs1(vector<vector<int>>& adj, int node, int par) {
        for (auto& child : adj[node]) {
            if (child == par)
                continue;
            dfs1(adj, child, node);
            sbtrSize[node] += sbtrSize[child];
            dp[node] += (dp[child] + sbtrSize[child]);
        }
    }
    void dfs2(vector<vector<int>>& adj, int node, int par, int n, int val) {
        ans[node] = val;
        for (auto& child : adj[node]) {
            if (child == par)
                continue;
            int newval = val + n - 2 * sbtrSize[child];
            dfs2(adj, child, node, n, newval);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dp.resize(n, 0);
        sbtrSize.resize(n, 1);
        ans.resize(n, 1);
        dfs1(adj, 0, -1);
        dfs2(adj, 0, -1, n, dp[0]);
        return ans;
    }
};