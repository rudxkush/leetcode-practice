class Solution {
public:
    int collectTheCoins(vector<int>& hasCoin, vector<vector<int>>& edges) {
        int n = hasCoin.size();
        vector<set<int>> adj(n);

        // build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        queue<int> leafQueue;
        int totalConnections = edges.size() * 2;
        int removedConnections = 0;

        // push leaves that have no coin
        for (int node = 0; node < n; node++) {
            if (adj[node].size() == 1 && hasCoin[node] == 0) {
                leafQueue.push(node);
            }
        }

        // prune leaves with no coin
        while (!leafQueue.empty()) {
            int leaf = leafQueue.front();
            leafQueue.pop();

            if (adj[leaf].empty()) continue; // isolated

            int parent = *adj[leaf].begin();
            adj[parent].erase(leaf);
            adj[leaf].erase(parent);
            removedConnections += 2;

            if (adj[parent].size() == 1 && hasCoin[parent] == 0) {
                leafQueue.push(parent);
            }
        }

        // push remaining leaves (must have coins)
        for (int node = 0; node < n; node++) {
            if (adj[node].size() == 1) {
                leafQueue.push(node);
            }
        }

        // remove leaves and their parents (two rounds)
        int rounds = 2;
        while (rounds--) {
            int currSize = leafQueue.size();
            while (currSize--) {
                int leaf = leafQueue.front();
                leafQueue.pop();

                if (adj[leaf].empty()) continue;

                int parent = *adj[leaf].begin();
                adj[parent].erase(leaf);
                adj[leaf].erase(parent);
                removedConnections += 2;

                if (adj[parent].size() == 1) {
                    leafQueue.push(parent);
                }
            }
        }

        return totalConnections - removedConnections;
    }
};
