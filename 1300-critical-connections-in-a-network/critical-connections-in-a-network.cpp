class Solution {
private: 
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>& adj, 
             int tin[], int low[], vector<bool>& visited, 
             vector<vector<int>>& bridges) {

        visited[node] = true;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]) {
            if(it == parent) continue;
            if(!visited[it]) {
                dfs(it, node, adj, tin, low, visited, bridges);
                low[node] = min(low[node], low[it]);
                // node --- it
                if(low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, 
    vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        // time of insertion
        int tin[n]; 
        // lowest time of insertion of all the adj 
        // node apart from the parent.
        int low[n]; 
        vector<vector<int>> bridges;
        dfs(0, -1, adj, tin, low, visited, bridges);
        return bridges;
    }
};