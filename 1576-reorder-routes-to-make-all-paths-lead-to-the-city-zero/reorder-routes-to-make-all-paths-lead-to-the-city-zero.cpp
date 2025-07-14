class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n); // adj[node] = {neighbor, direction}
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1}); // 1 means original direction from conn[0] -> conn[1]
            adj[connection[1]].push_back({connection[0], 0}); // 0 means reverse direction, no need to change
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int reorderCount = 0;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (auto [neighbour, direction] : adj[city]) {
                if (!visited[neighbour]) {
                    reorderCount += direction;  // If it's an outgoing edge, we need to reverse it
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return reorderCount;
    }
};
