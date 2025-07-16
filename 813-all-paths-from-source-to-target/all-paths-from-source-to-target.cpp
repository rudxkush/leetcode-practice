class Solution {
public:
    vector<vector<int>> allPaths;
    vector<int> pathTaken;
    int n = 0;
    void findTarget(vector<vector<int>>& graph, int node) {
        pathTaken.push_back(node);
        // base case
        if(node == n - 1) {
            allPaths.push_back(pathTaken);
        } else {
            for(auto neighbour : graph[node]) 
            findTarget(graph, neighbour);
        }
        // backtrack
        pathTaken.pop_back();
    } 
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // the adjList is already given to you
        n = graph.size();
        findTarget(graph, 0);
        return allPaths;
    }
};