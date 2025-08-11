class Solution {
public:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph,
             const string& node,
             vector<string>& itinerary) {
        while (!graph[node].empty()) {
            string next = graph[node].top();
            graph[node].pop();
            dfs(graph, next, itinerary);
        }
        itinerary.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        vector<string> itinerary;
        dfs(graph, "JFK", itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
