class Solution {
public:
    int src, dest;

    bool dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
        if (node == dest) return true; // Found destination
        visited[node] = true;

        for (auto neighbour : graph[node]) {
            if (!visited[neighbour]) {
                if (dfs(graph, neighbour, visited)) 
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        src = source;
        dest = destination;

        // Build adjacency list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        return dfs(graph, src, visited);
    }
};
