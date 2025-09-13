class Solution {
public:
    vector<vector<int>> outputPairs;

    void eulerianDfs(unordered_map<int, vector<int>>& graph, int start) {
        while(!graph[start].empty()) {
            int nei = graph[start].back();
            graph[start].pop_back();
            eulerianDfs(graph, nei);
            outputPairs.push_back({start, nei}); // post-order push
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;

        for(auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        int start = pairs[0][0]; // default start
        for(auto [node, _] : graph) {
            if(outDegree[node] == inDegree[node] + 1) {
                start = node;
                break;
            }
        }

        eulerianDfs(graph, start);
        reverse(outputPairs.begin(), outputPairs.end());
        return outputPairs;
    }
};

/*
    we want to get the set of pairs in an order where
    every consecutive pair's end and start would match (endi-1 == starti).
    pairs = [[5,1],[4,5],[11,9],[9,4]]
    11->9->4->5->1
    outputPairs = [[11,9],[9,4],[4,5],[5,1]]
    11->9->4->5->1
    From examples we can see a clear pattern: in an Eulerian path,
    the starting node has exactly one more outgoing edge than incoming,
    and the ending node has exactly one more incoming than outgoing.
    Every other node is balanced. So to decide the start, I check
    if such a node exists — if yes, I begin there; otherwise,
    if all nodes are balanced, it’s an Eulerian circuit and
    I can start anywhere with outgoing edges. From there I use DFS
    to consume edges one by one.
*/