class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<bool>& visited,
             vector<bool>& path_visited, vector<bool>& check) {
        visited[node] = true;
        path_visited[node] = true;
        check[node] = false;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (dfs(adj, adjNode, visited, path_visited, check))
                    return true;
            } else if (path_visited[adjNode]) {
                return true;
            }
        }

        check[node] = true;
        path_visited[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        vector<bool> path_visited(adj.size(), false);
        vector<bool> check(adj.size(), false);
        vector<int> safeNodes;

        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i])
                dfs(adj, i, visited, path_visited, check);
        }

        for (int i = 0; i < adj.size(); i++) {
            if (check[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};