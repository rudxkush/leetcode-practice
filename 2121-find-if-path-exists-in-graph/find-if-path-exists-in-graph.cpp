class Solution {
public:
    bool pathFinder(int n, vector<vector<int>>& graph, int source,
                    int destination, vector<bool>& visited) {
        if (source == destination)
            return true;

        if (visited[source])
            return false;

        visited[source] = true;
        for (int neighbour : graph[source]) {
            if (pathFinder(n, graph, neighbour, destination, visited))
                return true;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> graph(n);    
        for(auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);  
            graph[b].push_back(a); 
        }
        vector<bool> visited(n, false);
        return pathFinder(n, graph, source, destination, visited);
    }
};