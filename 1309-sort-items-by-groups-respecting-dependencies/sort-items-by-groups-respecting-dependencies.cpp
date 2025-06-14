class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Assign unique group id to ungrouped items
        for (int i = 0; i < n; ++i)
            if (group[i] == -1)
                group[i] = m++;

        // Item and group graphs + indegree
        vector<vector<int>> itemGraph(n), groupGraph(m);
        vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int before : beforeItems[i]) {
                itemGraph[before].push_back(i);
                itemIndegree[i]++;

                if (group[i] != group[before]) {
                    groupGraph[group[before]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Topological sorts
        vector<int> sortedItems = topoSort(itemGraph, itemIndegree);
        vector<int> sortedGroups = topoSort(groupGraph, groupIndegree);
        if (sortedItems.empty() || sortedGroups.empty())
            return {};

        // Group the items
        unordered_map<int, vector<int>> groupedItems;
        for (int item : sortedItems)
            groupedItems[group[item]].push_back(item);

        // Output in sorted group order
        vector<int> result;
        for (int g : sortedGroups) {
            for (int item : groupedItems[g]) {
                result.push_back(item);
            }
        }

        return result;
    }

    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return (order.size() == graph.size()) ? order : vector<int>();
    }
};
